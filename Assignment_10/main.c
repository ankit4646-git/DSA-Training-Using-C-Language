#include <stdio.h>
#include <stdlib.h>

// Functions Used
void displayArray(const int *arr, int size);
void findExtremas(const int *arr, int size);
void reverseArray(int *arr, int size);
int removeDuplicates(int *arr, int size);
void countFrequencies(int *arr, int size);
void sortArray(int *arr, int size);
void quickSort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void clearInputBuffer(void);

int main(void) {
    int size;

    printf("=========================================\n");
    printf("         LEETCODE ARRAY CHALLENGE        \n");
    printf("=========================================\n");

    while (1) {
        printf("Enter the size of the array (N > 1): ");
        if (scanf("%d", &size) == 1 && size > 1) {
            break;
        }
        printf("Invalid size. Please enter an integer greater than 1.\n");
        clearInputBuffer();
    }
    clearInputBuffer();

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Fatal Error: Heap allocation failed.\n");
        return 1;
    }

    printf("\nEnter %d array elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element [%d]: ", i);
        while (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Enter an integer: ");
            clearInputBuffer();
        }
    }
    clearInputBuffer();

    int choice;
    do {
        printf("\n-----------------------------------------\n");
        printf("                 MENU                    \n");
        printf("-----------------------------------------\n");
        printf("1. Display Array\n");
        printf("2. Find Statistics (Largest, 2nd Largest, Smallest, 2nd Smallest)\n");
        printf("3. Reverse the Array\n");
        printf("4. Remove Duplicates (Modifies Size)\n");
        printf("5. Count Frequency of Each Element\n");
        printf("6. Sort the Array (Ascending via QuickSort)\n");
        printf("7. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-7): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                findExtremas(arr, size);
                break;
            case 3:
                reverseArray(arr, size);
                printf("\nArray reversed successfully.\n");
                displayArray(arr, size);
                break;
            case 4:
                size = removeDuplicates(arr, size);
                printf("\nDuplicates eliminated. Updated structure:\n");
                displayArray(arr, size);
                break;
            case 5:
                countFrequencies(arr, size);
                break;
            case 6:
                sortArray(arr, size);
                printf("\nArray sorted via O(N log N) QuickSort:\n");
                displayArray(arr, size);
                break;
            case 7:
                printf("\nFreeing workspace. Terminating challenge wrapper.\n");
                break;
            default:
                printf("Invalid choice. Please pick an option from 1 to 7.\n");
        }
    } while (choice != 7);

    free(arr);
    return 0;
}

/**
 * Outputs formatted array items.
 * Time Complexity: O(N) | Space Complexity: O(1)
 */
void displayArray(const int *arr, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/**
 * Isolate 1st/2nd order extrema metrics 
 * Time Complexity: O(N) | Space Complexity: O(1)
 */
void findExtremas(const int *arr, int size) {
    int max1 = (arr[0] > arr[1]) ? arr[0] : arr[1];
    int max2 = (arr[0] > arr[1]) ? arr[1] : arr[0];
    int min1 = (arr[0] < arr[1]) ? arr[0] : arr[1];
    int min2 = (arr[0] < arr[1]) ? arr[1] : arr[0];

    for (int i = 2; i < size; i++) {
        // Cal maxima
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }

        // Cal Minima
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    printf("\n--- Array Extrema Extracted ---\n");
    printf("Smallest Element        : %d\n", min1);
    printf("Second Smallest Element : %d\n", min2);
    printf("Largest Element         : %d\n", max1);
    printf("Second Largest Element  : %d\n", max2);
}

/**
 * Reverses array sequence elements 
 * Time Complexity: O(N) | Space Complexity: O(1)
 */
void reverseArray(int *arr, int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/**
 * Removes duplicate records from sorted spaces
 * Automatically triggers an internal sort pass to meet invariants if unsorted.
 * Time Complexity: O(N log N) sorting base if unsorted, O(N) deduplication sweep | Space Complexity: O(1)
 */
int removeDuplicates(int *arr, int size) {
    if (size == 0 || size == 1) return size;

    sortArray(arr, size);

    int uniqueIdx = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[uniqueIdx]) {
            uniqueIdx++;
            arr[uniqueIdx] = arr[i];
        }
    }
    return uniqueIdx + 1;
}

/**
 * Counts character/integer frequency metrics ]
 * Time Complexity: O(N log N) sort + O(N) scan | Space Complexity: O(1)
 */
void countFrequencies(int *arr, int size) {
    if (size == 0) return;

    sortArray(arr, size);
    printf("\n--- Element Frequency Map ---\n");
    
    int i = 0;
    while (i < size) {
        int count = 1;
        while (i + 1 < size && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
        printf("Element %d : Appears %d time(s)\n", arr[i], count);
        i++;
    }
}

/**
 * Sort wrapper using randomized divide-and-conquer logic.
 */
void sortArray(int *arr, int size) {
    quickSort(arr, 0, size - 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

/**
 * Standard utility to drop line leftovers from input stream buffers.
 */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}