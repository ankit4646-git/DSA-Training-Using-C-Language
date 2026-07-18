# Assignment 10: LeetCode Array Challenge

## Objective
To implement optimal array modification algorithms, analyze time complexities for individual tracking routines, handle duplicates, and use quick sort variants[cite: 1].

## Problem Statement
Design an analytics suite implementing multiple algorithmic filters on integer dynamic lists: single-pass extrema discovery (first/second order min/max), in-place reversing, lookahead sliding windows to deduplicate nodes, and item distribution matching patterns using efficient divide-and-conquer processing engines[cite: 1].

## Algorithm
1. Single-Pass Extrema Extraction: Scan the array linearly from index 2 to N-1, tracking primary and secondary constraints concurrently.
2. In-Place Reverse Mapping: Swap symmetric index positions from opposite ends toward the middle of the array structure.
3. Two-Pointer Unique Packing: Enforce sorting. Walk the array, matching current items against tracked unique thresholds. Advance structural boundaries and copy distinct elements forward to strip duplicates.
4. Grouped Block Count Tracking: Sort the array to group duplicate values. Skip forward while items remain identical, printing the tracked frequency summaries once differences emerge.

## Complexity Analysis
The algorithmic efficiencies are mapped as follows[cite: 1]:

| Structural Operation | Time Complexity | Space Complexity | Analytical Context Summary 				     |
| :---                 | :---            | :---             | :---                       				     |
| Display Contents     | O(N) 		 | O(1) 	    | Direct item walk mapping entries. 	 		     |
| Extract Extremas     | O(N) 		 | O(1) 	    | Single pass evaluating first and second limits simultaneously. |
| In-place Reversal    | O(N) 		 | O(1) 	    | Linear operations ending at center points. 		     |
| Remove Duplicates    | O(N \log N) 	 | O(1) 	    | Dominated by quicksort requirements (O(N) logic follow-up).    |
| Frequency Analysis   | O(N \log N)     | O(1) 	    | Enforces sorted tracking boundaries beforehand. 		     |
| QuickSort Sorting    | O(N\logN)average|O(1) auxiliary    | Divide-and-conquer partitioning logic framework. 	             |

## Sample Input

Enter array size: 6
Elements input: [4, 1, 2, 1, 4, 4]

##Learning Outcome
Mastered single-pass tracking arrays, multi-pointer data compaction techniques, frequency identification using sorted array models, and runtime performance profiling workflows.