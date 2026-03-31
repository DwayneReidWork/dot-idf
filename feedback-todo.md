# C Languge

- [ ] cmake/better hello-world slides
- [ ] threading section -> C and Networking
- [?] more advanced preprocessor stuff
- [?] add section on unions after structs 
- [ ] add section on poll/select and discuss epoll, but not in depth -> network section

# Python Languge

- add continue/break in the looping section
- add keyboard i/o
- finish file i/o
- importing our own files
- implement cli parsing
    - sys
    ```
    import sys
    len(sys.argv)
    sys.argv[n]
    ```
    - argparse?

- threading and multiprocessing

- beef up the functions section to discuss positional and named arguments
    - discuss how python can have variable arguments (same function with more or less arguments)

# network programming
- add socket constants AF_INET, AF_INET6, SOCK_STREAM, IPPROTO_TCP
- add UDP
- add openssl and/or wolfssl

- break up networking and add those slides to python / C respectively

# network_game
- fix level 8s logic bug of xoring key by itself (which becomes zero)
