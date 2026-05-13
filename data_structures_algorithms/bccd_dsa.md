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
<!-- end_slide -->

Why DSA?
---

# Algorithms

finite sequence of mathematically rigorous instructions, typically used to solve a class of specific problems or to perform a computation

or

the steps you take to solve a problem

# Data Structures

data organization and storage formats that are usually chosen for efficient access to data.

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
```c +line_numbers
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

data structures
---

# Considerations
- Data Structures use algorithms to insert, delete, add, remove, find, (etc etc) items from their storage.
- Each data structure has pros and cons, either the complexity of their operations or the efficiency of their storage
- When determining which data structure to use, we must analyze what we want to do with our data
    - are we rapidly appending data?
    - are we iterating over fixed data?
    - do we want quick insertion and indexing?

# What is the storage for data structures? what is the format of the storage?
- in C (what we will use for the majority of these demonstrations), the storage is memory.
    - statically allocated, or more likely dynamically allocated to allow resizing
- A data structure in C normally consists of two things:
    - A `struct` whose properties describe the storage format and contain references to the storage
    - Multiple functions that operate on said struct, performing various operations depending on the data structure
<!-- end_slide -->

data structures
---

# (smart) Array

- C has arrays, but if you are coming from a higher level language, they are lacking in features.
- C arrays are *just* contiguous space. the most primative form of "formatted" storage.
- We will demonstrate creating a "smart" array in C that will highlight the core features of data structures

Our smart array will be able to do the following:
- insert items into an index
- access items at an index
- remove items at an index
- resize upon request

## specification
```file +line_numbers
path: ./code/smart_array/smart_array.h
language: c
```
<!-- end_slide -->

data structures
---

# (smart) Array

## implementation

- placeholder to review code at ./code/smart_array/smart_array.c
- review code at ./code/smart_array/main.c
- build the code at ./code/smart_array and run it in a debugger

<!-- pause -->

## Takeaways

- this simple wrapper around primative arrays gives us more flexability with the amount of items
- with the use of a `void **` as the backing storage, we can store pointers of any type. a *generic* data structure
- the functions that operate on our smart array take and return `void *`, adding to the *generic* functionality
- inserting is O(1)
- accessing is O(1)
- deleting is O(1)
- resizing is O(N) where N is the number of items that need to be copied
- needing to continually resize the array as it grows can quickly become expensive, and large resizes could result in unused space
- this highlights the limitation of arrays. indexing items is fast, but growth is slow
<!-- end_slide -->

data structures
---

# linked lists

- Linked Lists are a space effecient data structure that allow the linking or chaining of items in non-contiguous space
- at its simplest form, a link list is a "node" with data and a pointer to the next node
```c +line_numbers
struct Node {
    void *item;
    struct Node *next;
}
```
- by using a `void *` as our items type, this linked list can be used to hold any data type
- A linked list is a chaining of nodes, where  one node points to the next, and the final node's next pointer is NULL (in C)
- only a reference to the first node is needed to reach any index or node in the list
```
+--------+       +--------+      +--------+
|  item  |       |  item  |      |  item  |
|  next -------->|  next ------->|  next ------> NULL
+--------+       +--------+      +--------+
```
- "walking" or iterating over a linked list looks as follows:
```c +line_numbers
struct Node *list = <pretend I have a list with multiple nodes>

for (struct Node *i = list; NULL != i; i = i->next) {
    // do something with i
}
```
- if it isnt apparent yet, `struct addrinfo` as returned by `getaddrinfo` is a linked list of address info records
<!-- end_slide -->

data structures
---

# linked lists

## specification
```file +line_numbers
path: ./code/linked_list/linked_list.h
language: c
```
<!-- end_slide -->

data structures
---

# linked lists

## implementation

- placeholder to review code at ./code/linked_list/linked_list.c
- review code at ./code/linked_list/main.c
- build the code at ./code/linked_list and run it in a debugger
<!-- pause -->

## Takeaways

- linked lists allow us to easily append items to the end of our data structure without having to worry about resizing
- appending items to a linked list requires us to "walk" the list until we find the end of the linked list. this operation is O(n) where n is the list size
- indexing an array is at worst O(n), where the worst case scenario is indexing the end of the linked list
- inserting into an array is at worst O(n), where the index to insert into is also the tail
- use a linked list when you need to append an unknown amount of items and you do not want to worry about reallocating data
- the efficiency of appending can be optimized by keeping track of the tail as well as the head of the list
- keeping track of the size of the list can allow for quicker bounds checking on indexing or inserting
<!-- end_slide -->

data structures
---

# other noteworthy linked lists
## Circularly Linked List
- Circularly linked lists differ from regular linked lists in that the tail node points to the first node instead of `NULL`
- when walking a circularly linked list, the "end" is never NULL, you can choose to walk the list forever, continually cycling

## Double Linked List
- in a Double linked list, each node points to the next node AND the previous node
```
      +--------+       +--------+      +--------+
      |  item  |       |  item  |      |  item  |
      |  next -------->|  next ------->|  next ------> NULL
NULL <-- prev  |<-------- prev  | <------ prev  |
      +--------+       +--------+      +--------+
```
- the head of a double linked list will point to `NULL` for its previous node

## Other
- Circular Double Linked List
- Skip List
<!-- end_slide -->

data structures
---

# Trees & Binary Trees
- Trees are similar to list data structures in that they are "nodes" that point to other "nodes" but in a tree, each node can point to multiple nodes.
- in a tree, nodes are commonly refered to as leaves, and sub leaves are "child" leaves to the "parent" leaves
- nodes, or leaves, in a tree will only have a single parent, and the most parent node is called the "root" 

## Binary Trees
- while tree data structures have a one to many node relationship, it is more common to have a 1:2 relationship. each parent node has a left and right node.
- these trees, where nodes have two subnodes, is referred to as a "binary tree"
- the relationship between parent nodes and their child nodes is that:
    - the value in the left child node is less than the value in the parent node
    - the value in the right child node is greater than the value in the parent node
- when creating a binary tree, the first item is the "root"
- when adding items to a binary tree, the tree is "walked" similar to a linked list, but traversal is done through the left and right nodes as opposed to "next"
<!-- end_slide -->

data structures
---

# Binary Tree Basics

```file +line_numbers
path: ./code/binary_tree/demo.c
language: c
```

