#include <stdio.h>
#include <stdlib.h>

// Functions Used
void displayArray(const int *arr, int size);
void insertElement(int **arr, int *size, int *capacity);
void deleteElement(int *arr, int *size);
void updateElement(int *arr, int size);
void searchComparison(int *arr, int size);
int linearSearch(const int *arr, int size, int target, int *comparisons);
int binarySearch(const int *arr, int size, int target, int *comparisons);
void sortArray(int *arr, int size);
void clearInputBuffer(void);

int main(void) {
    int capacity = 4; 
    int size = 0;
    
    int *arr = (int *)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Fatal Error: Initial heap allocation failed.\n");
        return 1;
    }

    int choice;
    printf("=========================================\n");
    printf("        DYNAMIC ARRAY OPERATIONS         \n");
    printf("=========================================\n");

    do {
        printf("\n-----------------------------------------\n");
        printf("                 MENU                    \n");
        printf("-----------------------------------------\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element by Index\n");
        printf("3. Update Element by Index\n");
        printf("4. Display Array Elements\n");
        printf("5. Search & Compare Algorithms (Linear vs Binary)\n");
        printf("6. Exit\n");
        printf("-----------------------------------------\n");
        printf("Current Size: %d | Current Capacity: %d\n", size, capacity);
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                insertElement(&arr, &size, &capacity);
                break;
            case 2:
                deleteElement(arr, &size);
                break;
            case 3:
                updateElement(arr, size);
                break;
            case 4:
                displayArray(arr, size);
                break;
            case 5:
                searchComparison(arr, size);
                break;
            case 6:
                free(arr);
                arr = NULL;
                printf("\nDynamic workspace freed. Program terminated safely.\n");
                break;
            default:
                printf("Invalid choice. Please pick an option from 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}

/**
 * Inserts an element at the end
 * Time Complexity: O(1) | Space Complexity: O(1) 
 */
void insertElement(int **arr, int *size, int *capacity) {
    if (*size >= *capacity) {
        int newCapacity = (*capacity) * 2;
        int *temp = (int *)realloc(*arr, newCapacity * sizeof(int));
        if (temp == NULL) {
            printf("\nError: Memory reallocation failed. Insertion aborted.\n");
            return;
        }
        *arr = temp;
        *capacity = newCapacity;
        printf("\n[System Notice] Array capacity expanded to %d elements.\n", *capacity);
    }

    int value;
    printf("Enter integer element to insert: ");
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Enter an integer: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    (*arr)[*size] = value;
    (*size)++;
    printf("Element appended successfully.\n");
}

/**
 * Traverses and displays contents.
 * Time Complexity: O(N) | Space Complexity: O(1)
 */
void displayArray(const int *arr, int size) {
    if (size == 0) {
        printf("\nArray is currently empty.\n");
        return;
    }
    printf("\nDynamic Array Contents: ");
    for (int i = 0; i < size; i++) {
        printf("[%d]", arr[i]);
        if (i < size - 1) printf(" -> ");
    }
    printf("\n");
}

/**
 * Deletes an element at a chosen index
 * Time Complexity: O(N) | Space Complexity: O(1)
 */
void deleteElement(int *arr, int *size) {
    if (*size == 0) {
        printf("\nError: Cannot delete from an empty array.\n");
        return;
    }

    int index;
    printf("Enter target index to delete (0 to %d): ", *size - 1);
    while (scanf("%d", &index) != 1 || index < 0 || index >= *size) {
        printf("Invalid index boundary. Try again: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element at index %d deleted successfully.\n", index);
}

/**
 * Modifies an existing data point using target index
 * Time Complexity: O(1) | Space Complexity: O(1)
 */
void updateElement(int *arr, int size) {
    if (size == 0) {
        printf("\nError: No values available to update.\n");
        return;
    }

    int index, newVal;
    printf("Enter target index to modify (0 to %d): ", size - 1);
    while (scanf("%d", &index) != 1 || index < 0 || index >= size) {
        printf("Invalid index boundary. Try again: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    printf("Enter new value for index %d: ", index);
    while (scanf("%d", &newVal) != 1) {
        printf("Invalid input. Enter an integer: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    arr[index] = newVal;
    printf("Element at index %d updated to %d.\n", index, newVal);
}
                    
/**   
 * Doing a performance comparison between Linear Search and Binary Search.
 * Time Complexity: O(N^2) sorting overhead, O(N) search baseline | Space Complexity: O(1)
 */
void searchComparison(int *arr, int size) { 
    if (size == 0) {
        printf("\nPopulate array data before evaluating search models.\n");
        return;
    }  

    int target;
    printf("\nEnter value to search for performance benchmarking: ");
    while (scanf("%d", &target) != 1) {
        printf("Invalid value: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    int linComp = 0, binComp = 0;
    
    // 1. Perform Linear Search on unsorted structure
    int linPos = linearSearch(arr, size, target, &linComp);

    // 2. Sort the array dynamically to meet Binary Search prerequisite
    printf("\nSorting the array in-place to establish Binary Search prerequisites...\n");
    sortArray(arr, size);
    displayArray(arr, size);

    // 3. Perform Binary Search on sorted structure
    int binPos = binarySearch(arr, size, target, &binComp);

    // Render Metrics Comparison Table
    printf("\n=========================================\n");
    printf("        ALGORITHM ANALYSIS METRICS       \n");
    printf("=========================================\n");
    printf("%-20s | %-10s | %-15s\n", "Strategy Metric", "Linear", "Binary");
    printf("-----------------------------------------\n");
    printf("%-20s | %-10s | %-15s\n", "Status Result", (linPos != -1 ? "FOUND" : "NOT FOUND"), (binPos != -1 ? "FOUND" : "NOT FOUND"));
    printf("%-20s | %-10d | %-15d\n", "Comparisons Step", linComp, binComp);
    printf("%-20s | %-10s | %-15s\n", "Time Complexity", "O(N)", "O(log N)");
    printf("=========================================\n");
}

/**
 * Inspects the array tracking match iterations.
 * Time Complexity: O(N) | Space Complexity: O(1)
 */
int linearSearch(const int *arr, int size, int target, int *comparisons) {
    for (int i = 0; i < size; i++) {
        (*comparisons)++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

/**
 * To locate target values.
 * Time Complexity: O(log N) | Space Complexity: O(1)
 */
int binarySearch(const int *arr, int size, int target, int *comparisons) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        (*comparisons)++;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

/**
 * Sorts values using bubble sort algo
 * Time Complexity: O(N^2) | Space Complexity: O(1)
 */
void sortArray(int *arr, int size) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

/**
 * Discards terminal entry garbage.
 */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}