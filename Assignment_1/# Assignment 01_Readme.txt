# Assignment 01: Student Marks Analyzer

## Objective
To develop a structured, modular menu-driven C application executing foundational array modifications, conditional analytics, search methods, and in-place sorting patterns.

## Problem Statement
Build a menu-driven application capable of handling scores for `N` students. The application executes user operations to view arrays, isolate extrema values (highest/lowest), compute cumulative sums and arithmetic means, locate exact data indexes via values, and re-order data in ascending alignment.

## Algorithm
1. **Initialize Application**: Dynamic initialization of integer structure array size `N`.
2. **Collect Input**: Loop validation logic bounds entry boundaries strictly from 0 to 100.
3. **Menu Evaluation Engine**:
   * **Display**: Loop across sequence from index $0 \dots N-1$.
   * **Statistics**: Maintain running tracking variables (`total`, `highest`, `lowest`). Mutate limits inside an active linear traverse pass. Divide summary by count context for mean computation.
   * **Linear Search**: Linearly match internal items against parameter keys. Return the tracking index context step if matched; otherwise, output a failure flag (-1).
   * **Adaptive Sort**: Run nested passes over target bounds. Swap out-of-order neighbors. Terminate early if an entire boundary loop generates zero swap events.

## Time and Space Complexity
* **Display Marks**: Time $O(N)$ | Space $O(1)$
* **Calculate Statistics**: Time $O(N)$ | Space $O(1)$
* **Search Mark**: Time $O(N)$ | Space $O(1)$
* **Sort Marks**: Time $O(N^2)$ worst case, $O(N)$ best case | Space $O(1)$ auxiliary

## Sample Input
```text
Enter the number of students: 5
Student 1: 85
Student 2: 92
Student 3: 76
Student 4: 64
Student 5: 89