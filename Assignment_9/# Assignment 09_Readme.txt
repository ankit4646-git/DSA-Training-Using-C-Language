# Assignment 09: Dynamic Array Operations

## Objective
To develop structural dynamic array management primitives (allocations, expansion limits, item removal, element updates) in C, while evaluating performance metrics by benchmarking Linear and Binary search variations[cite: 1].

## Problem Statement
Design an interactive array workspace management module utilizing heap arrays supporting runtime resizing operations (`realloc`)[cite: 1]. The logic accommodates inline insertions, cell deletions, array prints, updates, and comparative search diagnostics tracking absolute check comparisons between Linear and Binary processing models[cite: 1].

## Algorithm
1. Dynamic Resizing Allocation: Instantiate workspace contexts via dynamic base sizing. When size trackers meet limits, resize data frames using `realloc` formulas to scale dynamic thresholds cleanly.
2. In-place Shift Deletion: Relocate elements from position `index+1` downward to overwrite elements, updating sizing configurations.
3. Linear Scan Check (O(N)): Check array targets sequentially from index 0 up to limit step values, incrementing evaluation metrics.
4. Binary Search Metric (O(\log N)): Enforce optimized sorting conditions. Set low/high bounds, isolate mid-points via safe integer offsets, and prune search zones by half every cycle.

## Time and Space Complexity
* Element Insertion: Time O(1) Amortized worst-case (O(N) during reallocation copy execution) | Space O(1) auxiliary
* Element Deletion: Time O(N) tracking shifts | Space O(1)
* Element Update: Time O(1) | Space O(1)
* Linear Search Performance: Time O(N) | Space O(1)
* Binary Search Performance: Time O(\log N) | Space O(1) auxiliary (requires an array sorting phase of O(N^2) beforehand)

## Sample Input
Array Elements: [12, 45, 7, 23, 89]
Select Search Benchmarking: 5
Value to search: 23

##Learning Outcome
Mastered dynamic buffer adjustments using reallocation strategies, implemented index shifting, tracked iteration efficiencies, and verified algorithmic scaling advantages through exact performance comparisons.