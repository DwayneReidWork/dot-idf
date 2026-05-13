#ifndef LINKED_LIST
#define LINKED_LIST

struct Node {
    void *data;
    struct Node *next;
};

struct Node *list_init(void *item);

int list_append(struct Node *list, void *item);

struct Node *list_insert(struct Node *list, void *item, int index);

void *list_index(struct Node *list, int index);

void *list_remove(struct Node *list, int index);

#endif
