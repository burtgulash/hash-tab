#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hasht.h"


void push(node **root, char x) {
    assert (root != NULL);
    node *new = (node*) malloc(sizeof(node));
    new->x = x;

    if (*root == NULL)
        new->next = NULL;
    else
        new->next = *root;

    *root = new;
}

char get(node *root, char x) {
    for (; root != NULL; root = root->next)
        if (root->x == x)
            return root->x;
    return '\0';
}

// TODO
char delete(node **root, char x) {
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

void print(node *root) {
    printf("list: ");
    for (; root != NULL; root = root->next)
        printf("%c", root->x);
    printf("\n");
}

int main() {
    node *list;
    push(&list, 'a');
    print(list);
    push(&list, 'b');
    print(list);
    push(&list, 'c');
    print(list);
    delete(&list, 'b');
    delete(&list, 'c');
    push(&list, 'd');
    print(list);
    printf("found? %c", get(list, 'x'));
}
