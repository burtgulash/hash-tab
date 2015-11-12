#ifndef HASHT_H
#define HASHT_H

typedef struct b {
    char x;
    struct b *next;

} node;

char get(node *root, char x);
void print(node *root);
void push(node **root, char x);
char delete(node **root, char x);

#endif
