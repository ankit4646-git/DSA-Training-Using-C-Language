# Assignment 05: Dynamic Array Management

## Objective
To manage runtime allocation of memory segments using heap commands (`malloc`), validate allocation success, reference memory locations via offset tracking, and execute complete resource cleanups using deallocation commands (`free`)[cite: 1].

## Problem Statement
Build an application capable of requesting heap blocks based on runtime user specifications[cite: 1]. The architecture tracks arrays via pointer syntax, captures grades within explicit boundaries, parses the allocated memory space to extract descriptive metrics, and systematically clears allocations prior to program shutdown to prevent system resource exhaustion[cite: 1].

## Algorithm
1. **Dynamic Workspace Provisioning**: Request integer array segments via `malloc(N * sizeof(int))` at runtime[cite: 1]. Check for pointer failures (`NULL`) to ensure allocation safety.
2. **Data Insertion**: Walk consecutive heap offsets using base addresses combined with index multipliers (`marks + i`).
3. **Statistical Summary Compilation**: Run a single loop across the heap addresses. Update standard tracker registers (`total`, `highest`, `lowest`) by evaluating data properties.
4. **Memory Deallocation**: Free the allocated space using the base memory pointer via `free(marks)` and explicitly assign it to `NULL` to clear dangling pointer references[cite: 1].

## Time and Space Complexity
* **Array Allocation**: Time $O(1)$ | Space $O(1)$ auxiliary
* **Data Gathering Loop**: Time $O(N)$ | Space $O(1)$
* **Data Print Loop**: Time $O(N)$ | Space $O(1)$
* **Dynamic Range Calculation**: Time $O(N)$ | Space $O(1)$
* **Memory Release Processing**: Time $O(1)$ | Space $O(1)$ auxiliary

## Sample Input
```text
Enter the number of student marks to allocate: 3
Populate Marks:
Student 1: 78
Student 2: 95
Student 3: 88
