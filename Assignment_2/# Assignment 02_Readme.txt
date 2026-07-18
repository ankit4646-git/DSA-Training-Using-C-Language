# Assignment 02: String Utility Toolkit

## Objective
To develop a modular utility in C that executes common algorithmic operations on strings, emphasizing safe buffer scanning, direct pointers, single-pass iteration analytics, and in-place transformations.

## Problem Statement
Build an application managing character arrays dynamically through interactive menus. The system calculates element lengths, modifies sequence polarity (reversal), asserts bidirectional sequence symmetries (palindromes), filters character sets (vowels, digits, whitespaces), and calculates accurate population density counts per character.

## Algorithm
1. **Input Generation**: Scan strings safely using context limits (`%999[^\n]`) to allow embedded spaces without stream breakdowns.
2. **Length Computation**: Iterate an index tracker until reaching the null-terminator string sentinel boundary (`\0`).
3. **In-place Reversal**: Maintain double-ended indices at opposite ends of the array string. Meet at the center index swapping elements in pairs.
4. **Palindrome Verification**: Progress two internal boundary counters toward the center. Convert targets to lowercase values temporarily to enforce safe case-insensitivity comparisons.
5. **Token Classification**: Execute a continuous loop through array items, testing ASCII integer bounds for categorizing target metrics.
6. **Frequency Analysis**: Instantiate a fixed integer block map mapping all 256 valid ASCII keys. Map frequency hits across a single linear execution phase.

## Time and Space Complexity
* **Length Analysis**: Time $O(N)$ | Space $O(1)$
* **String Reversal**: Time $O(N)$ | Space $O(1)$ auxiliary
* **Palindrome Verification**: Time $O(N)$ | Space $O(1)$
* **Token Classification**: Time $O(N)$ | Space $O(1)$
* **Frequency Analysis**: Time $O(N)$ | Space $O(1)$ (The lookup bucket is bound to a static 256 array slots regardless of structural input scale size)

## Sample Input
```text
Enter a string: Radar 123