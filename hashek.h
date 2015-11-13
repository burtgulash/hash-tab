#ifndef HASHEK_H
#define HASHEK_H
#include "listik.h"

typedef struct {
    int num_items;
    int size;
    node **table;
} hashek;

hashek *hashek_new();
void hashek_put(hashek *h, char x);

#endif
