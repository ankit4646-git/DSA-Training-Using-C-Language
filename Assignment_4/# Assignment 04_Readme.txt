# Assignment 04: Student Record Management System

## Objective
To develop a database management abstraction using structured data types (`struct`) in C, implementing contiguous record storage, search patterns, field updates, and stable item removal.

## Problem Statement
Design a modular database shell handling an internal array of student structures[cite: 1]. The architecture must accommodate adding distinct structured components securely, rendering formatted tables, targeting item fields via numeric keys, rewriting existing data cells, and deleting records while preserving continuous data boundaries without creating unallocated internal holes.

## Algorithm
1. **Structural Mapping**: Create a custom context object type holding discrete primitives (`int`, `char[]`, `float`).
2. **Insertion ($O(1)$)**: Append data immediately to the end of the data layout using a global array tracker index pointer context.
3. **Linear Scan Lookup ($O(N)$)**: Walk the structures, verifying if the target structural field identity matches the key pattern query.
4. **Target Mutation ($O(N)$)**: Locate target items inside the array frame and rewrite active variables via string assignments and numeric inputs.
5. **Contiguous Element Shift Deletion ($O(N)$)**: Locate the target record index, run a structural shift copying items at position `j+1` into position `j`, and update the global allocation tracker.

## Time and Space Complexity
* **Record Insertion**: Time $O(1)$ auxiliary ($O(N)$ worst-case validation check) | Space $O(1)$
* **Table Output Display**: Time $O(N)$ | Space $O(1)$
* **Identity Target Search**: Time $O(N)$ | Space $O(1)$
* **Record Field Mutation**: Time $O(N)$ | Space $O(1)$
* **Record Gap Deletion**: Time $O(N)$ | Space $O(1)$ auxiliary (due to in-place sequential structural shifting)

## Sample Input
```text
Select: 1 (Add Record)
Enter Student ID: 101
Enter Student Name: Ajay
Enter Student GPA: 7.85