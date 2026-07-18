# Assignment 03: Pointer Playground

## Objective
To understand memory models in C by working with explicit pointers, extraction of physical memory addresses, memory address manipulation (pointer arithmetic), and data swaps via pass-by-reference architectures.

## Problem Statement
Build an application demonstrating explicit pointer interaction profiles. The system prints addresses and resolves values via dereferencing, modifies external scopes via pointers, walks contiguous blocks entirely via address updates, and verifies how byte jumps adjust dynamically across numerical shifts.

## Algorithm
1. Basic Inspection: Extract address profiles via address-of operators (`&`). Fetch data from targets via dereferencing operators (`*`).
2. Pass-by-Reference Swapping: Pass memory addresses into lower operational components. Use a temporary placeholder register to execute value adjustments across scopes in place.
3. Array Reference Traversal: Bind base pointer paths to array structures. Advance memory positions via pointer increment operators (`ptr++`), using direct references (`*ptr`) without using standard indexing brackets.
4. Pointer Arithmetic Evaluation: Add and subtract scaling integers from pointer structures, observing how memory jumps automatically factor in the base storage footprint of the referenced data type.

## Time and Space Complexity
* Basic Pointer Concepts: Time O(1) | Space O(1)
* Swapping Logic: Time O(1) | Space O(1)
* Array Traversal: Time O(N) | Space O(1)
* Pointer Arithmetic: Time O(1) | Space O(1)

## Sample Input
Enter first number (A): 15
Enter second number (B): 30

##Learning Outcome
Mastered low-level variable mappings, pointer references, safe memory modifications across stack contexts, and tracking structured sequences directly via byte increments.
