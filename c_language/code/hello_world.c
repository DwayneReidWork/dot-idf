#include <stdio.h>

int main(int argc, char **argv)
{
    // the message to print later
    char *message = "hello, world!\n";

    /*
        printing my previously
        stored message
    */
    printf("%s\n", message);

    // returning 0 -- traditionally meaning success
    return 0;
}
