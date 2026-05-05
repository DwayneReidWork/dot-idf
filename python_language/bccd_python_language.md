---
title: Python3 Language
author: CW2 Richard Hailey
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
- Why Python
- Program Execution
- The Road to "Hello, World!"
- Variables
- Arithmetic Operations
- Control Flow
- Functions
- Scope
- imports
- Object Oriented Programming
- File Operations
<!-- end_slide -->

Why Python
---
- General programming language
<!-- new_line -->
- High level of abstraction
    - don't have to think about the implementation details
<!-- new_line -->
- Interpreted Language
    - Python source files are processed by the python interpreter. if a system has an interpreter, it will run (version pending)
<!-- new_line -->
- Unlike C, Python has an integrated ecosystem of tools, with 3rd party options as well
<!-- end_slide -->

Program Execution -- How Operating Systems Run Python Code
---
- unlike C, our python code isnt the process that is running.
<!-- new_line -->
- the python interpreter is the executable code that is loaded into the process
- the python interpreter then ingests and executes your code as the middleman, abstracting the platform and operating system from the developer
- the python interpreter processes one line at a time, so there is no "compile time" or "build time checking" or errors
<!-- new_line -->
- each line is processed into Python Opcodes, which can be thought of as the assembly of the interpreter
- the interpreter processes the opcode via its built in capabilities
<!-- end_slide -->

Program Execution -- How Operating Systems Run Python Code
---
- placeholder for process memory map with python as the middle-man
<!-- end_slide -->

The Road to "Hello, World!"
---
- write soure code
- execute with python3 interpreter
<!-- end_slide -->

The Road to "Hello, World!"
---
# Source
```file +line_numbers
path: code/hello_world.py
language: python
```

# Execution
```bash +line_numbers +exec
python3 code/hello_world.py
```
<!-- end_slide -->

Variables
---
# intro
- in python, variables are labels that store data.
- unlike C, this label is not necessarly a label to memory.
- the data is stored somewhere in memory, but how all that works in managed by python and the interpreter

# types [7.1, 7.2]
- Integer (int) for storing integer data -- `immutable`
- Float (float) for storing floating point types (decimals) -- `immutable`
- String (str)  for storing strings!
    - note: python strings are NOT null terminated, they are a first class type
    - python strings are `immutable` and cannot be changed
    - string operations create new strings, more to follow
- List (list)   for storing multiple datas (including other lists)
- Dictonary (dict) for storing `key:value` pairs
- Typle (tuple) for containing an `immutable` sequence of datas
<!-- end_slide -->


Variables -- Syntax
---
# Grammar
```
<variable_name> = <data>
```

# Example [7.1, 7.2]
- no need for types, python will infer that 
- no need to declare a variable before its usage
- a variable name can be reused, and assigned to a different data type
- in python, there is no "stack" and "heap" for the developer to manager. the python interpreter will manage all that
```python +line_numbers
some_variable_name = 5    # python is going to infer this in an integer
some_variable_name = 4.6  # python is going to adjust the data type to float
some_variable_name = "this is a string" # you guessed it, its a string now
some_list = [1, "string," 4.2] # list instantiation with various types
some_dict = { "key": "value", "key2": 5 }
some_dict["key"] = "new_value"

some_tuple = ("127.0.0.1", 8888)
```
<!-- end_slide -->

Variables -- immutable?
---
data in python can be mutable, or immutable, but what does that mean?

# mutable [7.1]
- the value of the data labeled by a variable can change

# immutable [7.1]
- the value of the data labeled by a variable cannot change
- if 'reusing' a variable name to `modify` immutable values, entirely new data is created and assigned to the variable
- "freeing" the old data is done automatically by python through a process known as garbage collection
- memory usage should still be taken into account, small changes to an immutable variable can exponentially add up
- mutable variables passed to functions are automatically passed by reference, no need for pointers
<!-- end_slide -->

Variables -- immutable?
---
- placeholder for immutable memory growth
<!-- end_slide -->

Arithmetic Operations
---

# Precedence [7.3]
- refer to python operator precedence documentation:
https://docs.python.org/3/reference/expressions.html#operator-precedence

# Addition [7.3]
```python +line_numbers
a = 5   # this is an int
b = 7.2 # this is a float

c = a + b # no type casting needed.
```

# Subtraction [7.3]
```python +line_numbers
a = 5   # this is an int
b = 7.2 # this is a float

c = a - b # no need for signed or unsigned variables
```

# Multiplication [7.3]
```python +line_numbers
a = 5   # this is an int
b = 7.2 # this is a float

c = a * b # no need for signed or unsigned variables
```
<!-- end_slide -->

Arithmetic Operations
---

# Division [7.3]
```python +line_numbers
a = 5   # this is an int
b = 7.2 # this is a float

c = a / b # dont divide by zero
```

# Modulus [7.3]
```python +line_numbers
a = 5   # this is an int
b = 7.2 # this is a float

c = a % b # unlike C, python can modulo more than just int numeric types, and even mixed numeric types
```

# Parenthesis [7.3]
- Just like in C, add `()` to group operations to bring clarity to operations
<!-- end_slide -->

Control Flow
---
- Conditional Expressions
<!-- new_line -->
- Conditional Control Flow
    - if
    - if/else
    - if/elif/else
    - match
<!-- new_line -->
- Iteration
    - for
    - while
<!-- new_line -->
- Exception Based Control Flow
    - try/except/finally
<!-- end_slide -->

Control Flow -- Conditional Expressions
---
# Logical `and`, `or`, `not`, `==`, `!=`, `>`, `>=`, `<`, `<=`
- when performing logical operations, the literal words `and`, `or`, and `not` are used
```python +line_numbers
a == 1
b == 0
a and b
a or b
not a
not b
```

# `None`: pythons version of NULL
# `is`, `in`
```python +line_numbers
socket = socket.create_connection(("127.0.0.1", 1337))
socket is None     # will evaluate to False if we have a socket
socket is not None # will evaluate to True if we have a socket

my_list = [5, 4, 3, 2, 1]
5 in my_list              # will evaluate to 5 if it is in my_list
9 in my_list
```
<!-- end_slide -->

Control Flow -- Conditional Expressions
---
# Boolean
- python comes packaged with literal `True` and `False` values
- 0 is still false, and non-zero is still truthy
```python +line_numbers
is_running = True
while is_running:
    is_running = False

is_running = 1
while is_running:
    is_running = 0
```
<!-- end_slide -->

Control Flow -- Conditional Control Flow
---
- Same as C, different syntax
# if [7.7]
```python +line_numbers
some_var = input("enter an option, or 'q' to quit: ")
if some_var == 'q': # wow! simple string comparison, thanks python!
    exit() # Python is indentation based. your indendation levels matter!
```
- as noted above, indentation levels matter in python
- think of the levels of indentation as groups of `{}` code blocks in c
- the level of indentation for `tabs` and `spaces` are different. even if a tab is 5 spaces, it is not equivalent to 5 spaces
- be consistent!
# if / else [7.7]
```python +line_numbers
password = <secret password>
some_var = input("Enter the password: ")
if some_var == password:
    print("correct!")
else:
    print("incorrect!")
```
<!-- end_slide -->

Control Flow -- Conditional Control Flow
---
# if / elif / else [7.7]
```python +line_numbers
if var1 == var2:
    # do stuff
elif var1 == var3:
    # do other stuff
< chain as needed >
< optionally add an else >
else:
    # else stuff
```

# match
- match is similar to switch, but far more complicated
- match is also python 3.10, might not be on older systems
- refer to documentation for full usage:
https://docs.python.org/3/reference/compound_stmts.html#match

- this example is a very simple match example that is similar to switch functionality
```python +line_numbers
x = <some result>
match x:
    case 10:
        # do case 10 stuff
    case 20:
        # do case 20 stuff
    case <value>:
        # do case <value> stuff
    case _:
        # this case will catch anything, like default in C
```
<!-- end_slide -->

Control Flow -- Iterative Control Flow
---
# for loops [7.7]
- for loops in python are a mechinism that allows iteration over a sequence of items
- in c, you might loop over the number of elements in an array or pointer, and the bounds need to be known before hand
- python iterable data types (like lists) know their size at run time so the syntax is more concise

# syntax
```
for <i> in <iterable>:
    <statements>
```

# example
```python +line_numbers
my_list = [1, 2, 3, 4, 5]
for i in my_list:
    print(i)

# use the range function to iterate a specific amount of times
# this range will iterate over 10 values, 0 -> 9.
# range is non-inclusive of the value provided
for i in range(10):
    print(i)
```
<!-- end_slide -->

Control Flow -- Iterative Control Flow
---
# while loops [7.7]
- like their c counterpart, while loops iterate `while` a condition holds `True`
- `True` is any value that is not `0`, `None`, or `False`

# syntax
```
while <expression>:
    <statements>
    <possibly modify the expression>
    <statements>
```

# example
```python +line_numbers
running = True
while running:
    user_input = input()
    if user_input == "exit":
        running = False

user_input = "default"
while user_input != "exit":
    user_input = input()
    handle_input(user_input)
```
<!-- end_slide -->

Control Flow -- Exception Based Control Flow
---
# try/except/finally [7.7]
- in C, errors are a value returned by a function that must be checked for success
- some errors in C, cause undefined behavior and can crash the application
- checks must be put in place to test conditions `before` a breaking operation occurs
- in Python, errors can be returned values, but they can also be `Exceptions`
- expections happen at runtime, and can can be "caught" or "handled" with `try/except/finally`
- exceptions that are not handled continue to "go up the call stack" until a handler catches it, or the program exits

```python +line_numbers
try:
    my_file = open("some_file", "rw")
catch FileNotFoundError:
    print("file not found")

user_input = input()

try:
    result = 9 / user_input

except ZeroDivisionError:
    print("division by zero occured")

# this trailing catch will catch all other exceptions that could possibly be thrown
except: 
    print("oops! something went wrong!")
finally:
    # regardless of the try/expect, this block of code will execute afterwords
```
<!-- end_slide -->

Functions [7.1, 7.5]
---
- python functions operate similarly to C functions in that they encapsulate reussable code
- unlike C, python functions do not need a return type, can have variable parameters, and default values
    - also unlike C, the parameters dont have/need types
    - parameters with a default type do not need to be provided when called
- functions are declared using the `def` keyword, followed by `function_name(<parameters):`
- the `return` keyword is used to return the result of a function

```python +line_numbers
def my_add(a, b):
    return a + b
```

```python +line_numbers
def my_add(a, b = 4):
    return a + b
```

- how do you ensure you are receiving the right type of data?
- runtype checks of variable types can be performed with the `type()` function and either `==` or `is` operators
- additional input validation should always be performed, just like with C Always Be Checking (ABC) [7.6]

```python +line_numbers
my_var = 10
type(my_var) == int
type(my_var) is int
```
<!-- end_slide -->

Functions [7.1, 7.5]
---
- immutable data types are copied by value into function
- mutable data types are copied by reference into functions, and can be modified by the function
- if no data is `return`ed, the keyword may be ommited
```python +line_numbers
def my_func(my_list):
    my_list.append(4)

var = [1, 2, 3]
my_func(var)
my_func(var)
my_func(var)
print(var)
```
- in this instance, var is a mutable list instantiated with 3 values
- var is passed to the `my_func` function by reference because lists are mutable
- inside the function, my_list (which is a refernce to var) has the value 4 appended to the end of it
- finally, printing the list will result in `[1, 2, 3, 4, 4, 4]`
<!-- end_slide -->

Scope [7.1]
---
- the scope, or name resolution of variables, functions, and additional types follow similar rules to C
- block scope in python is determined by the indendation level
- if a label is defined in a block scope, its scope is limited to that block, unless it was globally defined

```python +line_numbers
a = 5 # declared in top block, similar to file scope in C

# this `my_func` function label also has file scope as it exists in the top scope
def my_func(a)
    # a `shadows` the global a, a in the function refers to the parameter
    b = a + 1  # b has block scope in this function
    return b

if a == 5:
    b = a + 7 # this b has scope inside of this if statement


b = 12
if a == 5:
    b = a + b # this b is going to reference the b of the larger scope
```
- the full list of complex scope/name resolution rules can be found here:
https://docs.python.org/3/reference/executionmodel.html
<!-- end_slide -->

import [7.1]
---
- in c we would use the `#include` preprocessor directive to include code from other files, or libraries into our source code
- python packages code into `modules` and they can be `import`ed with the `import` keyword
- properties (variables) or methods (functions) from the imported module can be access with the `<module>.<property | method>` notation

```python +line_numbers
import time

time.sleep(5)
```

- specific functionality of a module can be imported with the `from <module> import <function>` syntax
```python +line_numbers
from time import sleep

sleep(5)
```

- mutliple items can be imported from a module by coma seperating them
- items imported do can just be referenced by their label without prefixing their module
```python +line_numbers
from time import sleep, localtime

sleep(5)
localtime()
```
<!-- end_slide -->

Object Oriented Programming [7.8]
---
- Pros
- Classes & Objects
- Inheritence & Composition
- Ducktyping
<!-- end_slide -->

Object Oriented Programming - Pros [7.8]
---
- Encapsulation & Data Hiding
- Hightened Code Reusability
- Increased Code Modularity

- All of the Pros of OOP are layers of abstraction. This abstraction can be extremely powerful, but more difficult to logically comprehend
- Anything you can do in an OOP Language can be achieved in C, it just might look uglier
<!-- end_slide -->

Object Oriented Programming - Classes & Objects [7.8]
---
# Class
- A class is a collection of data and/or functions into a logically encapsulated unit
- A class definition is the "blue print" of the class
- Similar to a struct in C, but a class can also have functions that operate on themselves
- distinct keywords used by classes include `class`, `self` and the `__init__` function
    - `class <class_name>:` is used to declare a class labeled <class_name>
    - all class related properties and methods are indented under the class label
    - class functions are use the `def` keyword, and their first parameter must be `self`
        `self` is how an instance of the class, an `object`, refers to itself from its own functions
    - the function `def __init__(self, ...)` is known as a `constructor` and is how an instance of the class is created
<!-- end_slide -->

Object Oriented Programming - Classes & Objects [7.8]
---
```file +line_numbers {1-21 | 1 | 2 | 3-7 | 9-10 | 12-14 | 16-20}
path: code/class_object.py
language: python
start_line: 1
end_line: 21
```
<!-- end_slide -->

Object Oriented Programming - Classes & Objects [7.8]
---

# Object
- An Object is an `instance` of a class
- simliar to a struct definition vs an instance of a struct
- Objects are unique instances of classes whose data and functionality is the same as other objects of the same type, but with its own unique values

```file +line_numbers {1-15 | 1-3 | 5 | 7-8 | 10-15 | 11-13 | 15}
path: code/class_object.py
language: python
start_line: 22
end_line: 36
```

- notice on line 8, when calling an objects method, you do not need to provide a self argument
- while it is a requirement in the method signature, python is automatically providing the self parameter as the object calling the function
<!-- end_slide -->

object oriented programming - inheritance & composition [7.8]
---

# Inheritance
- Inheritance is the mechanism of basing a class upon another class, retaining similar implementation but giving the ability to expand
- `parent class`, `base class`, `super class` is the class being inherited from
- `subclass`, `child class` is the class inheriting implementation from the `parent class`

```file +line_numbers {1-19 | 2-4 | 6-8 | 10 | 11-14 | 12 | 16-19 | 17}
path: code/inheritance.py
language: python
start_line: 1
end_line: 20
```
<!-- end_slide -->

object oriented programming - inheritance & composition [7.8]
---
```file +line_numbers
path: code/inheritance.py
language: python
start_line: 24
end_line: 33
```

```bash +exec
python3 code/inheritance.py
```
<!-- end_slide -->

object oriented programming - inheritance & composition [7.8]
---
# Inheritance
- Inheritence can implement new functionality as well as extend existing functionality

```file +line_numbers {1-22 | 13-14 | 21-22 }
path: code/inheritance.py
language: python
start_line: 1
end_line: 23
```
- lines 13-14 implement new attributes that only exist on the child class. they do not exist on the parent class
- lines 21-22 implement a function `new_function_only_child_has` will be able to execute, it does not exists on the parent class
<!-- end_slide -->

object oriented programming - inheritance & composition [7.8]
---
# Composition
- Inheritance is great for reusing code that has similar data and functionality, or you need extra features to be added to a class
- Composition is another design pattern that allows for greater modularity than the tight coupling created by inheritence
- Composition is here one class contains other objects as attributes or properties
- at first attempt attempt, creating a class structure to represent cars with various types of functionality, one might reach for inheritence
- what about four wheel drive cars? Do we have a gas_four_wheel_drive and an electric_four_wheel_drive subclass? as the levels and branches of inheritence grows, so does the complexity

```file +line_numbers 
path: code/composition.py
language: python
start_line: 1
end_line: 18
```
<!-- end_slide -->

object oriented programming - inheritance & composition [7.8]
---
# Composition
- in this composition example, we only have a single car class, but it is `composed` of an engine rather than extending `car` through inheritence to have an engine
- inheritence still has its place, the `engine` our car is composed of might be a child class of a root `engine` class

```file +line_numbers 
path: code/composition.py
language: python
start_line: 20
end_line: 27
```
<!-- end_slide -->

object oriented programming - Ducktyping
---
- pythons `lazy` implementation of Polymorphism (not covered here!)
- python doesn't have a type system, so how do you ensure that a parameter passed to a function or class has the properties expected?
- documentation, and runtime checks!
```file +line_numbers {8-14 | 9-11,13,14 | 1-6 | 5,14}
path: code/composition.py
language: python
start_line: 28
end_line: 42
```

- in this car class, how do we know that the provided engine has a `drive()` method that can be called?
- at runtime, python will inspect the type at the variable `self.engine` and look for an attribute drive and execute it like a function
- this is where developer documentation is key, the expected behavior of engines being provided to cars should be well known and documented
- with this documentation, any developer can create a brand new type of engine, as long as it acts according to the documentation
<!-- end_slide -->

object oriented programming - everything is an object
---
- In python, everything is an object
- documentation is your friend!
    - https://docs.python.org/3/
- python objects can be inspected for properties and documentation on the command line
- open into an interpreter
```bash {1-9 | 1 | 4 | 5 | 7 | 9}
python3
Python 3.14.2 (main, Dec  5 2025, 16:49:16) [Clang 17.0.0 (clang-1700.4.4.1)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>> import time
>>> type(time)
<class 'module'>
>>> dir(time)
['CLOCK_MONOTONIC', 'CLOCK_MONOTONIC_RAW', 'CLOCK_MONOTONIC_RAW_APPROX', 'CLOCK_PROCESS_CPUTIME_ID', 'CLOCK_REALTIME', 'CLOCK_THREAD_CPUTIME_ID', 'CLOCK_UPTIME_RAW', 'CLOCK_UPTIME_RAW_APPROX', '_STRUCT_TM_ITEMS', '__doc__', '__loader__', '__name__', '__package__', '__spec__', 'altzone', 'asctime', 'clock_getres', 'clock_gettime', 'clock_gettime_ns', 'clock_settime', 'clock_settime_ns', 'ctime', 'daylight', 'get_clock_info', 'gmtime', 'localtime', 'mktime', 'monotonic', 'monotonic_ns', 'perf_counter', 'perf_counter_ns', 'process_time', 'process_time_ns', 'sleep', 'strftime', 'strptime', 'struct_time', 'thread_time', 'thread_time_ns', 'time', 'time_ns', 'timezone', 'tzname', 'tzset']
>>> help(time.time)
```

- the last function, `help()` will open a man-page-like interface with documentation related to the parameter

<!-- end_slide -->

File Operations
---
- file operations in python are achieved using the builtin `open()` function, and then interacting with the returned file object
- file objects in python are an abstraction of platform specific file operations and operating primitives like linux file descriptors and `open`, `read`, `write`

```python +line_numbers
my_file = open("some_file", "r+") # this returns a file object

# we opened the file as a regular, non-binary file. the result of read will be a str
contents = my_file.read() 
print(contents)
```

- we can open a file in the interpreter to play around with file operations
- we can use `type()` and `help()` to inspect the open command, and the resulting file object
<!-- end_slide -->

File Operations - A detour into I/O and operating systems
---
# Operating System Abstraction
- the operating systems (OS) is a chunk of code living in memory, and being executed by the CPU.
- your code runs in the operating systems memory space, and is encapsulated/restricted to its feature set
- this matters when requesting access to physical devices connected to a computer, commonly called Input/Output or I/O

# Input / Output
Input and output is handled by the operating system, and it exposes various interfaces (syscalls) for requesting access to these resources.
<!-- new_line -->
Input and output includes, but is not limited to, the follow devices:
- mouse
- keyboard
- network interface card
- hard drive

# Blocking Requests
- CPUs are fast, and normally each line of code is executed in fractions of a second
- I/O is relativily slow, and may take time for the OS to handle the request
- during this time, your process/code will "pause" or `block` execution until the operating system responds
- I/O requests are not guaranteed to be fullfilled in their entirety
    - a request to read a file might be for more data than the file has
    - a request to send network information may only send partial data
    - i/o operations are `variable` and extra code needs to handle the partial sending/receiving of data
        - variability in i/o can be caused by hardware I/O controllers, drivers, or the OS
        - I/O operations will generally read/write as much of the requested data in a limited number of execution cycles
- tldr: when you make an I/O call, they are blocking by default and the data sent/recieved is variable
<!-- end_slide -->

File Operations - A detour into I/O and operating systems
---
- placeholder for I/O diagram / demonstration
<!-- end_slide -->

File Operations
---

# File Basics
- Our python file object is an abstraction of operating system primatives
- inspecting the file object, we can find those primatives with the `fileno()` function
- when calling `read` or `write`, python calls the operating systems `read`/`write`

# How does a file know where to write?
- Imagine a file as a logical "array" of bytes, but instead of in memory, they are on a device
- When a file is opened, the OS and/or the abstraction keeps track of the file "offset" or "index"
- a `read` or `write` request is performed for `x` bytes starting at the offset
    - in a read operation, up to `x` bytes are read, and the offset is increased by the amount read
    - in a write operation, up to `x` bytes are written, and the file is expanded if it goes beyond the current bounds
<!-- end_slide -->

File Operations
---
# tell & seek

```bash
python3
Python 3.14.2 (main, Dec  5 2025, 00:00:00) [GCC 15.2.1 20251111 (Red Hat 15.2.1-4)] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> cmake = open("CMakeLists.txt", "r")
>>> cmake.tell()
0
>>> cmake.seek(15)
15
>>> cmake.tell()
15
```

# get filesize
```python +line_numbers
import os
os.path.getsize(<file_path>)
```

# testing file exists
```python +line_numbers
import os
os.path.exists(<path>)
os.path.isfile(<path>)
os.path.isdir(<path>)
```

