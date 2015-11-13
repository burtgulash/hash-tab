#include <stdio.h>
#include <stdlib.h>
#include "listik.h"
#include "hashek.h"

/* #define BASE 14695981039346656037u */
/* #define PRIME 1099511628211u */

#define BASE 2166136261u
#define PRIME 16777619u

#define LOAD_FACTOR_UPPER 75
#define LOAD_FACTOR_LOWER 25
#define MIN_SIZE 4


hashek *hashek_new() {
    hashek *h = (hashek*) malloc(sizeof(hashek));
    h->num_items = 0;
    h->size = MIN_SIZE;
    h->table = (node**) malloc(h->size * sizeof(node*));

    return h;
}

void hashek_resize(hashek *h, int new_size) {
    node **tmp = (node**) malloc(new_size * sizeof(node*));

    int i;
    for (i = 0; i < h->size; i++)
        tmp[i] = h->table[i];

    free(h->table);
    h->table = tmp;
    h->size = new_size;
}

unsigned int hash(void *item, int size) {
    char *bytes = (char *) item;
    unsigned int hash = BASE;

    for (size--; size >= 0; size--) {
        hash ^= bytes[size];
        hash *= PRIME;
    }
    return hash;
}

void hashek_put(hashek *h, char x) {
    int position = hash(&x, sizeof(char)) % h->size;
    listik_push(&(h->table[position]), x);
    h->num_items++;

    if (h->num_items * 100 / h->size > LOAD_FACTOR_UPPER)
        hashek_resize(h, h->size * 2);

    printf("load factor: %d\n", h->num_items * 100 / h->size);
}

char hashek_get(hashek *h, char x) {
    int position = hash(&x, sizeof(char)) % h->size;
    char y = listik_get(h->table[position], x);

    if (y != '\0')
        return y;

    return '\0';
}

char hashek_delete(hashek *h, char x) {
    int position = hash(&x, sizeof(char)) % h->size;
    char y = listik_delete(&(h->table[position]), x);
    if (y != '\0') {
        h->num_items--;
        if (h->num_items * 100 / h->size < LOAD_FACTOR_LOWER
            && h->size / 2 >= MIN_SIZE)
            hashek_resize(h, h->size / 2);

        return y;
    }
    return '\0';
}
