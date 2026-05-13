#include "smart_array.h"

#define ARRAY_SIZE 20

int main(void) {
    int items[ARRAY_SIZE] = {0};
    int status = 0;

    struct Array my_array = {0};
    array_init(&my_array, 5);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        items[i] = i;
    }

    for (int i = 0; i < 5; i++) {
        status = array_insert(&my_array, i, &items[i]);
    }

    status = array_resize(&my_array, ARRAY_SIZE);

    for (int i = 5; i < ARRAY_SIZE; i++) {
        status = array_insert(&my_array, i, &items[i]);
    }

    array_free(&my_array);

    return 0;
}
