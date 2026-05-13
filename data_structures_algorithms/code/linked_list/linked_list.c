#include "linked_list.h"

#include <stdlib.h>

struct Node *list_init(void *item)
{
    struct Node *list = NULL;

    if (NULL == item)
    {
        goto END;
    }

    list = calloc(1, sizeof(struct Node));
    if (NULL == list)
    {
        goto END;
    }

    list->data = item;

END:
    return list;
}

int list_append(struct Node *list, void *item)
{
    int status =  -1;

    if (NULL == list || NULL == item)
    {
        goto END;
    }

    for (struct Node *i = list; NULL != i; i = i->next)
    {
        if (i->next != NULL)
        {
            continue;
        }

        i->next = list_init(item);
        if (NULL == i->next)
        {
            goto END;
        }

        status = 0;
        break;
    }

END:
    return status;
}

struct Node *list_insert(struct Node *list, void *item, int index)
{
    struct Node *temp = NULL;
    int counter = 0;

    if (NULL == list || NULL == item || 0 > index)
    {
        goto END;
    }

    if (0 == index)
    {
        temp = list_init(item);
        if (NULL == temp)
        {
            goto END;
        }

        temp->next = list;
        goto END;
    }

    for (struct Node *i = list; NULL != i; i = i->next)
    {
        if (counter + 1 != index)
        {
            counter++;
            continue;
        }

        temp = list_init(item);
        if (NULL == temp)
        {
            goto END;
        }

        temp->next = i->next->next;
        i->next = temp;
        break;
    }

    temp = list;

END:
    return temp;
}

void *list_index(struct Node *list, int index)
{
    void *item = NULL;
    int counter = 0;

    if (NULL == list)
    {
        goto END;
    }

    for (struct Node *i = list; NULL != i; i = i->next)
    {
        if (counter != index)
        {
            counter++;
            continue;
        }

        item = i->data;
        break;
    }


END:
    return item;
}

void *list_remove(struct Node *list, int index)
{
    struct Node *del_node = NULL;
    void *item = NULL;
    int counter = 0;

    if (NULL == list)
    {
        goto END;
    }

    if (0 == index &&  NULL != list->next) {
        del_node = list;
        list = list->next;
        item = del_node->data;
        free(del_node);
        goto END;
    }

    for (struct Node *i = list; NULL != i; i = i->next)
    {
        if (counter + 1 != index)
        {
            counter++;
            continue;
        }

        if (NULL == i->next)
        {
            break;
        }

        del_node = i->next;
        item = del_node->data;

        i->next = del_node->next;

        free(del_node);

        break;
    }


END:
    return item;
}
