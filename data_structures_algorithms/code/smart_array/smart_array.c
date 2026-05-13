#include "smart_array.h"

#include <stdlib.h>
#include <string.h>

int array_init(struct Array *array, int capacity)
{
    int status =  -1;

    if (NULL == array || 0 >= capacity) {
        goto END;
    }

    array->data = calloc(capacity, sizeof(void *));
    if (NULL == array->data) {
        goto END;
    }

    array->capacity = capacity;
    status = 0;

END:
    return status;
}

int array_insert(struct Array *array, int index, void *item) {
    int status = -1;

    if (NULL == array || 0 > index || NULL == item || index >= array->capacity) {
        goto END;
    }

    array->data[index] = item;
    array->size++;
    status = 0;

END:
    return status;
}

void *array_select(struct Array *array, int index) {
    void *value = NULL;

    if (NULL == array || 0 > index || index >= array->capacity) {
        goto END;
    }

    value = array->data[index];

END:
    return value;
}

void *array_remove(struct Array *array, int index) {
    void *value = NULL;

    if (NULL == array || 0 > index || index >= array->capacity) {
        goto END;
    }

    value = array_select(array, index);
    array->data[index] = NULL;
    array->size--;

END:
    return value;
}

int array_resize(struct Array *array, int new_capacity) {
    int status = -1;
    void **old = NULL;

    if (NULL == array ||  new_capacity < array->size ) {
        goto END;
    }

    old = array->data;
    array->data = calloc(new_capacity, sizeof(void *));
    if (NULL == array->data) {
        array->data = old;
        goto END;
    }

    memcpy(array->data, old, array->capacity * sizeof(void *));
    array->capacity = new_capacity;
    free(old);
    status = 0;

END:
    return status;
}

void array_free(struct Array *array) {
    if (NULL == array) {
        return;
    }

    free(array->data);
    array->data = NULL;
}
