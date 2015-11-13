#ifndef HASHT_H
#define HASHT_H

typedef struct b {
    char x;
    struct b *next;

} node;

char listik_get(node *root, char x);
void listik_print(node *root);
void listik_push(node **root, char x);
char listik_delete(node **root, char x);

#endif
