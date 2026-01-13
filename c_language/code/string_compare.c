#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char string1[] = "hello, world!";
    char string2[] = "hello, world!";

    int status = (string1 == string2);

    printf("status: %d\n", status);

    status = strcmp(string1, string2);
    printf("status: %d\n", status);
}
