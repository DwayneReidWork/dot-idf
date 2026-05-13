#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ITEM_COUNT 20

#define LEFT 0
#define RIGHT 1

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

int main (void)
{
    struct Node *index = NULL;
    struct Node *next = NULL;
    int new_value = 0;
    int dir = -1;
    int inner = 0;

    struct Node root = {
        .left = NULL,
        .right = NULL,
        .value = 50
    };

    srand(time(NULL));

    for (int i = 0; i < ITEM_COUNT; i++)
    {
        index = &root;
        next = index;
        new_value = rand() % 100;
        inner = 1;

        while (inner) {
            if (new_value < index->value) {
                next = index->left;
                dir = LEFT;
            } else if (new_value > index->value) {
                next = index->right;
                dir = RIGHT;
            } else {
                printf("no duplicates!\n");
                inner = 0;
                continue;
            }

            if (NULL == next)
            {
                break;
            }

            index = next;
        }


        switch (dir) {
            case LEFT:
                index->left = calloc(1, sizeof(struct Node));
                index->left->value = new_value;
                break;

            case RIGHT:
                index->right = calloc(1, sizeof(struct Node));
                index->right->value = new_value;
                break;
        }
    }
}
