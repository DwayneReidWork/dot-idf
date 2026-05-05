---
title: Data Structures and Algorithms (DSA)
author: 90 COS/DOT
theme:
    name: catppuccin-mocha
---

JQR Items
---
Information ending in [#.#] denote sections that covers a JQR item
ex:
- \<instructional information here\> [#.#]
- \<instructional information here\> [#.#, #.#, ...]

This instruction will not cover all the JQR items, and some of the sections are not covered in their entirety
- 6.1 for example has multiple components
<!-- end_slide -->

Overview
---
- Why DSA?
- Data Structure Overview
    - Algorithms and Big-O notation
    - (smart) Arrays
    - Linked List
    - Circularly Linked List
    - Double Linked List
    - Tree & Binary Tree
    - Stack
    - Queue & Priority Queue
    - Hash Table
    - Weighted Graph
- Data Structure Implementation
    - Linked List
    - Circularly Linked List
    - Binary Search Tree
    - Hash Table
    - Stack
    - Priority Queue
<!-- end_slide -->

Why DSA?
---

# Algorithms

finite sequence of mathematically rigorous instructions, typically used to solve a class of specific problems or to perform a computation

or

the steps you take to solve a problem

# Data Structures

are data organization and storage formats that are usually chosen for efficient access to data.

- each data structure has its pros and cons, normally choosing to be more time (execution time) or space efficient (memory/storage)

# Data Structures + Algorithms = Programs

- the data structures choose and the algorithms implemented make up the final program that is developed
<!-- end_slide -->

Algorithms and Big-O notation
---

# Big-O notation

Commonly seen as O(n), big-O notation is a mathematical notation that describes the approximate size of a function on a domain. In computer science, Big-O is used to classify algorithms by how their domain (runtime or space) requirements grow with the input.

Commonly, algorithms will be placed into one of the following classes based on its complexity, which can be mathematically analyzed. The following list is sorted by complexity, least complex fist. this list is not all encompassing.

- O(1)        - instant - regardless of the amount of input
- O(log n)    - logarithmic - as the input grows, domain complexity increases logarithmically
- O(n)        - linear - domain complexity increases linearly as the input size increases
- O(n log n)  - linearithmic / loglinear
- O(n^2)      - quadratic - the domain complexity grows quadratically with an increase to input size

an algorithm will most likely have a seperate Big-O notation for time complexity and space complexity
<!-- end_slide -->

Algorithms and Big-O notation
---

Consider the following scenario:

- you are given a sorted array of integers. given a value, determine if the value is in the array and return its index.

<!-- pause -->

# solution 1: linear search

```c +line_numbers
int linear_search(int *array, int size, int value) {
    int index = -1;

    for (int i = 1; i < size; i++) {
        if (array[i] == value) {
            index = i;
            break;
        }
    }

    return index;
}
```
Takeaways from this code:
<!-- incremental_lists: true -->
- start from the begining
- iterate through each index
- check if index matches provided value
- worse case scenario, check the entire array
- as the size of the input array grows, the time complexity grows linearly
- The Big-O for the time complexity of this function is O(n)
<!-- incremental_lists: false -->
<!-- end_slide -->

Algorithms and Big-O notation
---

Consider the following scenario:

- you are given a sorted array of integers. given a value, determine if the value is in the array and return its index.

# solution 2: binary search

```c +line_numbers
int binary_search(int *array, int size, int value) {
    int index = -1;

    int left = 0;
    int right = size - 1;
    int middle = 0;

    while (left <= right) {
        middle = left + ((right - left)/2);
        if (array[middle] < value) {
            left = middle + 1;
        } else if (array[middle] > value) {
            right = middle - 1;
        } else {
            index = middle;
            break;
        }
    }

    return index;
}
```
Takeaways from this code:
<!-- incremental_lists: true -->
- check if our value is in the middle
- if the middle value is greater than our value, our search space is in the bottom half of the array
- if the middle value is less than our value, our search space is in the top half of the array
- adjust our left and/or right values to check just the top/bottom half of the array
- this has cut out seach space in half in one iteration
- continue to check the middle value of our search space, adjusting the left/right accordingly
- every iteration cuts our search space in half
- this pattern of cutting a search space in half has an O(log n) complexity
- the worst case complexity of this search function is O(log n)
<!-- incremental_lists: false -->
<!-- end_slide -->

Algorithms and Big-O notation
---

Consider the following scenario:

- you are given a random array of integers. sort the array.

<!-- pause -->

# solution 1: bubble sort
```c
void bubble_sort(int *array, int size) {
    int temp = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
```

Takeaways from this code:
<!-- incremental_lists: true -->
- start from the beginning of the array in the outer loop
- in the inner loop, scan forward looking at each pair, swapping if needed
- the nested loop pattern here, where the outer and inner loop iterate over the input size is O(n^2)
- the overall time complexity of this sort function is O(n^2), quadratic. it grows exponentially as the input size grows
<!-- incremental_lists: false -->

Other noteworthly sorting algorithms:
- Insertion Sort -- O(n^2)
- Selection Sort -- O(n^2)
- Merge Sort     -- O(nlogn)
- Heap Sort      -- O(nlogn)
- Quick Sort     -- O(nlogn)

<!-- end_slide -->

Data Structures
---

- Data Structures use algorithms to insert, delete, add, remove, find, (etc etc) items from their storage.
- Each data structure has pros and cons, either the complexity of their operations or the efficiency of their storage
- When determining which data structure to use, we must analyze what we want to do with our data 

