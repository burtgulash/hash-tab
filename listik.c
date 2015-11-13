#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "listik.h"

char listik_get(node *root, char x) {
    for (; root != NULL; root = root->next)
        if (root->x == x)
            return root->x;

    return '\0';
}

void listik_push(node **root, char x) {
    assert (root != NULL);
    node *new = (node*) malloc(sizeof(node));
    new->x = x;

    if (*root == NULL)
        new->next = NULL;
    else
        new->next = *root;

    *root = new;
}

int listik_update(node **root, char x) {
    assert (root != NULL);

    if (*root != NULL) {
        node *cur;
        for (cur = *root; cur != NULL; cur = cur->next)
            if (cur->x == x) {
                cur->x = x;
                return 0;
            }
    }

    listik_push(root, x);

    return 1;
}

char listik_delete(node **root, char x) {
    node *cur = *root;
    char retval;

    if (cur == NULL)
        return '\0';

    if (cur->x == x) {
        retval = cur->x;
        *root = cur->next;
        free(cur);
        return retval;
    }

    node *prev = cur;
    for (cur = cur->next; cur != NULL; prev = cur, cur = cur->next)
        if (cur->x == x) {
            retval = cur->x;
            prev->next = cur->next;
            free(cur);
            return retval;
        }

    return '\0';
}

void listik_print(node *root) {
    fputs("list: ", stdout);
    for (; root != NULL; root = root->next)
        putchar(root->x);
    putchar('\n');
}
