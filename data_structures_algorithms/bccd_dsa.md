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
- Linked Lists
- Trees & Binary Tree
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
    - child nodes contain a pointer to their parent node
    - the value in the left child node is less than the value in the parent node
    - the value in the right child node is greater than the value in the parent node
- when creating a binary tree, the first item is the "root"
- when adding items to a binary tree, the tree is "walked" similar to a linked list, but traversal is done through the left and right nodes as opposed to "next"
<!-- end_slide -->

data structures
---

# Binary Trees

- placeholder for whiteboard demonstration of binary trees
- placeholder to review code at ./code/binary_tree/demo.c
- build the code, run it in a debugger

Takeaways from this code:
<!-- incremental_lists: true -->
- binary trees are "sorted"
- depending on the data, a binary tree can become lopsided or unbalanced
- at worse case scenario, inserting items is O(n) where a binary tree is unbalanced
- average case scenario in a balanced binary tree, insertion is O(log n)
- at worse case scenario, searching for nodes is O(n) where the binary tree is unbalanced
- average case scenario in a balanced tree, data search is O(log n)
- use a binary tree if you need to sort, insert, and search data frequently
<!-- incremental_lists: false -->
<!-- end_slide -->

data structures
---

# Stack - the data structure, not the region of process memory

stacks are a "last-in-first-out" or LIFO data structure. items in a stack are generally kept in an array, but they are only added and removed from one side of the array.


```c +line_numbers
struct stack
{
    void *items;
    int size;
    int capacity;
};
```

- this structure tracks the following things:
    - `items` - a `void *` that can hold any type of item
    - `size` - the number of items currently in `items`
    - `capacity` - the allocated size of `items`
- when we add items, we put them at the tail end of the `items` array
- when we remove items, we get them from the tail end of the `items` array
- indexing an item in an array O(1), or instant. making insert removing items O(1)
- resizing the array can be done when the size of th array reaches the capacity
- choose a stack if you need efficient LIFO behavior
<!-- end_slide -->

data structures
---

# Stack

## code example

```c +line_numbers
struct stack A = // an initialized struct

// inserting an item
void *item = // some item

if (A.size  == A.capacity)
{
    // resize
}

A.items[A.size] = item;
A.size++;

// retreiving an item
if (0 == A.size) {
    // empty stack
}

item = A.items[size - 1];
A.items[size - 1] = NULL;
A.size--;
```

<!-- end_slide -->

data structures
---

# queue - First in first out

- queues are a first in first out data structure that provides O(1) insertion and O(1) removal of items.
- the items are normally stored in an array
    - the front/head of the items is tracked for removal
    - the back/tail of the items is tracked for insertion
    - a "circular array" can be used to prevent data fragmentation

## circular arrays
- a technique where the an index into an array can continue to increment, but by "modding" the index by the array size, bound the index to the array bound

```c +line_numbers
#define SIZE 20

int index = 0;
int array[SIZE] = {0};

while (1)
{
    array[index % SIZE];
    index++;
}
```
<!-- end_slide -->

data structures
---

# queue

```c +line_numbers
struct queue
{
    void **array;
    int size;
    int capacity;
    int head;
    int tail;
}
```

properties:
- `array` will hold our data
- `size` is  the current amount of items in the queue
- `capacity` is the current amount of items in the queue
- `head` is the index to the "front" of the queue
- `tail` is the index to the "back" of the queue

notes:
- by using an allocated array, we can resize to have a larger capacity if needed
- using `void **` allows our array to hold items of any type
- by using an array with a head and tail index, our enqueuing and dequeuing are O(1)
<!-- end_slide -->

data structures
---

# queue - adding items

```c +line_numbers
int queue_enqueue(struct queue *queue, void *item) {
    int status = -1;

    if (NULL == queue || NULL == item)
    {
        return status;
    }

    if (queue->capacity == queue->size)
    {
        // resize or return failure
    }

    queue->array[queue->tail] = item;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;
    status = 0;

    return status;
}
```

takeaway:
- using the properties of a circular array lets "tail" be a lower index than the "head"
- using array indexing, we maintain O(1) for adding items to the queue
- depending on our queue requirements, we can resize our queue or return failure if the queue is full
- items are always added to the end of a queue
<!-- end_slide -->

data structures
---

# queue - removing items

```c +line_numbers
void *queue_dequeue(struct queue *queue) {
    void *item = NULL;

    if (NULL == queue || 0 == queue->size) {
        return item;
    }

    item = queue->array[queue->head];
    queue->array[queue->head] = NULL;
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;

    return item;
}
```

takeaway:
- using the properties of a circular array lets "head" be a higher index than the "tail"
- using array indexing, we maintain O(1) for removing items from our queue
- depending on our queue requirements, could choose to "shrink" our array if we have a lot of left over space
- items are always removed from the end of the queue

## notes:
- in the queue implementaitons, our data was stored in an array. that can reduce complexity but requires constant resizes
- other implementations will use a linked list as their data with a pointer to the "head" and "tail" instead of an index

<!-- end_slide -->

data structures
---

# hashing

hashing is a term that describes processing input data through a hash function to retrieve output data called a hash value, hash, or signature.

## hash function (theory)

- a hash function can take an input of `n` size and turn it into a "unique" fixed size output
- hash functions are "one way". a hash can not be "reversed" to the original data
- when multiple inputs result in the same hash, a "hash collision" has occured
- normally the more complex the hash function, and the greater fixed output size, the less collisions
- hash functions can be cryptographically secure for applications that have rigorous security requirements

## hash functions

- sha 1, 2, 3 -- cryptographically secure
- FNV-1, FNV-1a
- SuperFastHash

# note: hashing is a key component of the next data structure the "hash table"
<!-- end_slide -->

data structures
---

# hash table

- hash tables implement an "associative array" or a dictionary
- hash tables map keys to values
    - data is inserted with a key. given the key, the same data is returned
    - the key is hashed and used as an index into the array
    - for the purpose of hash table complexity, the "hashing" component is considered O(1)
- hash tables are a space time tradeoff, where the more space you allocate for an array, the more efficient it is

## complexity
- search - best case O(1) - worst case O(n)
- insert - best case O(1) - worst case O(n)
- delete - best case O(1) - worst case O(n)

note: if more memory (space) is allocated for the hash table, these operations will stay closer to O(1). but as a hashtable becomes "full" its efficiency will deteriorate

## limitations
- given an array that holds 256 items the index key can only be up to byte.
- if every key resulted in a unique 1 byte index, only 256 items could be inserted into the hash table before ite became full
- if multiple keys result in the same index, a "hash collision" has occured.
- multiple techniques exist to mitigate hash collisions but we will focus on "separate chaining"
<!-- end_slide -->

data structures
---

# hash table -- chaining

- chaining in a hash table is the process of storing items at an index in a linked list
- the base array of the hash table will contain only linked lists, and the nodes of the linked lists hold:
    - the original key
    - the data being stored
    - a pointer to the next node
<!-- new_line -->
- when indexing a hash table with a key:
    - the key is hashed
    - the index is found
    - the linked list is walked, comparing the actual key with the nodes stored key
    - if the actual key and the stored key match, the data is returned
<!-- new_line -->
- using the "separate chaining method, we can continue to store any number of items, but as the array fills and the lists grow large the efficiency degrades
- allocating a larger array with a larger index range will slow the degrigation, highlighting the space/efficiency tradeoff
