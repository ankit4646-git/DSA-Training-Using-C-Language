# Assignment 06: Inventory Management System

## Objective
To build a structural data registry using complex nested primitives, implementing tracking logic, inline modifications, value accumulation patterns, and efficient sorting routines.

## Problem Statement
Design an asset tracking architecture storing Product IDs, tracking names, unit costs, and warehouse allocations[cite: 1]. The backend handles interactive insertions, matches structural details via explicit code profiles, recalculates item valuations, and re-orders arrays cleanly based on cost parameters using efficient in-place algorithms[cite: 1].

## Algorithm
1. Entity Definition: Structure item schemas to hold matching attributes (`int`, `char[]`, `double`)[cite: 1].
2. Asset Validation Check: Scan and ensure new entity definitions contain globally unique transaction ID codes.
3. Linear Extraction Lookups: Inspect sequence arrays continuously to display matches or modify localized targets.
4. Insertion Sort Implementation (O(N^2)): Step through product lines sequentially. Extract item instances as key models, cascade elements backwards while structural prices override target levels, and fit the tracking context cleanly into position.
5. Cumulative Accumulation Tracking: Run a single loop across data boundaries, multiply quantity fields against unit cost records, and sum results into a master valuation field.

## Time and Space Complexity
* Product Insertion: Time O(1) base (O(N) validation step) | Space O(1)
* Ledger Output Table: Time O(N) | Space O(1)
* Product Search Logic: Time O(N) | Space O(1)
* In-place Field Mutation: Time O(N) | Space O(1)
* Insertion Price Sorting: Time O(N^2) average/worst case, O(N) best case | Space O(1) auxiliary
* Warehouse Valuation Summary: Time O(N) | Space O(1)

## Sample Input
Select Option: 1 (Add Product)
Enter ID: 501
Enter Name: Mechanical Keyboard
Enter Price: 89.99
Enter Quantity: 15

##Learning Outcome
Mastered record grouping setups, single-pass value analysis methods, and in-place sorting routines while tracking data bounds carefully.
