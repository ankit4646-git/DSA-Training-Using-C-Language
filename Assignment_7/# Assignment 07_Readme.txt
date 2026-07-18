# Assignment 07: Hospital Patient Management System

## Objective
To develop a structured records database application handling discrete record registration, query execution, information updates, and safe contiguous line removal operations[cite: 1].

## Problem Statement
Build an information tracking module capable of storing unique Patient IDs, names, ages, and diagnostic details inside an array of patient structures[cite: 1]. The system uses structured functions to register records safely, generate printable status charts, modify diagnosis details, and remove records while preserving continuous data boundaries[cite: 1].

## Algorithm
1. Model Specification: Declare structural blocks grouping primitive components (`int`, `char[]`)[cite: 1].
2. Admission Record Check: Collect inputs, ensuring target registration IDs remain unique across the active database array size.
3. Linear Scanning: Iterate across array bounds to output records or target matching profiles using search parameters.
4. Information Updates: Overwrite the target index fields inside the struct components.
5. In-Place Shift Deletion (O(N)): Locate the target index element, run a shifting loop to copy item `j+1` into position `j` to eliminate memory gaps, and update the array size counter.

## Time and Space Complexity
* Patient Registration: Time O(1) base (O(N) duplication check) | Space O(1)
* Directory Display: Time O(N)| Space O(1)
* Patient Search Pattern: Time O(N) | Space O(1)
* Record Field Modification: Time O(N) | Space O(1)
* Record Overwrite Deletion: Time O(N) | Space O(1) auxiliary (due to structured internal array elements shifting)

## Sample Input
Select Option: 1 (Register Patient)
Enter Patient ID: 702
Enter Patient Name: Mr.Akshay Verma
Enter Patient Age: 45
Enter Diagnosed Disease: Chronic Hypertension

##Learning Outcome
Understood structural data integrity management, linear searching mechanics, boundary parsing strategies, and array compaction techniques during structural row removal operations.
