#include <stdio.h> // this is including standard input and output, contains printf

int main(int argc, char **argv) // entrypoint to our application
{
    // this is a single line comment
    // the message to print later
    // this message needs to be declared before it can be used in line 9
    // all things need to be "declared" before they can be used in C
    char *message = "hello, world!\n";

    /*
        printing my previously
        stored message

        this is also a multi-line comment
    */
    printf("%s\n", message);
    // notice how most lines in a semi-colon. most statements in C end in a semi-colon

    // returning 0 -- traditionally meaning success
    return 0;
}
