#ifndef SMART_ARRAY
#define SMART_ARRAY

struct Array {
    void **data;
    int size;
    int capacity;
};

int array_init(struct Array *array, int capacity);

int array_insert(struct Array *array, int index, void *item);

void *array_select(struct Array *array, int index);

void *array_remove(struct Array *array, int index);

int array_resize(struct Array *array, int new_capacity);

void array_free(struct Array *array);

#endif
