- grep for TODO's
- integrate git into the course work

# C Languge
- Add speaker notes:
    - when discussing the hello_world.c
        - discuss c processing one line at a time
        - discuss that most statements end in a semicolon
        - things need to be declared before they can be used
        - maybe move all these things to a "c-basics" slide

- why c:
    - discuss the fact that c is a statically typed language

- road to hello world:
    - discuss the individual silos that build up the foundation required to develop

- control flow
    - add continue, break

- functions and scope
    - function parameters have function scope
    - global variables are in scope
    - caller variables are not in scope
    - file scope variables are in the BSS segment

- variables:
    - functions are a label -- C standard refers to variable names as labels
    - discuss the assignment operator, and how it is evaluated (almost) last
    - chars use single quotes `'`
    - chars are still binary, but they are "interpreted" differently
    
- sections to add:
    - 'function' like macro
    - add a sizeof section, potentially with/before/after functions?
    - add a typedef function -- until then, dont talk about typedef
        - using struct tends to add more clarity, while using typedef can obscure the data type
        - typedef makes sense on "opaque" data types


- add keyboard i/o
- file operations and i/o blocking
- cmake/better hello-world slides



## make these combined section? like python and C?
- section on threading
- section on file operations

# Python Languge

- add continue/break in the looping section
- add keyboard i/o
- finish file i/o
- beef up the functions section to discuss positional and named arguments
    - discuss how python can have variable arguments (same function with more or less arguments)

# network programming
- rewrite serialization to use a type, length, value
- add UDP

# All
- replace terms like "agent" with USCC terms
