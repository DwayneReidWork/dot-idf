#include "linked_list.h"

#include <stdlib.h>

#define ARRAY_SIZE 20

int main(void)
{
    struct Node *list = NULL;
    struct Node *to_free = NULL;
    int array[ARRAY_SIZE] = { 0 };

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = i;
    }

    list = list_init(&array[0]);

    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        list_append(list, &array[i]);
    }

    // walking a linked list to free it
    while (NULL != list) {
        to_free = list;
        list = list->next;
        free(to_free);
    }

    return 0;
}
