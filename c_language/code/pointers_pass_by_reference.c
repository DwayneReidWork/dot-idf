#include <stdio.h>

void add_to_ints(int *a, int *b);

int main(int argc, char **argv) {
    int a = 12;
    int b = 15;
    int *b_ptr = &b;

    printf("a = %d; b = %d\n", a, b);
    add_to_ints(&a, b_ptr);
    printf("a = %d; b = %d\n", a, b);

    return 0;
}

void add_to_ints(int *a, int *b) {
    (*a)++; // increment the value located in the callers stack space
    *b = *b + 1; // [6.11]
}
