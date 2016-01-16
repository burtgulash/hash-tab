#include <stdio.h>
#include <stdlib.h>
#include "hashik.h"

Hashik *new_hashik(int tabsize) {
    Hashik *h = (Hashik*) malloc(sizeof(Hnode));
    h->size = 0;
    h->tabsize = tabsize;
    h->table = (hptr_t*) malloc(sizeof(hptr_t) * h->tabsize);
    for (int i = 0; i < h->tabsize; i++)
        h->table[i] = NULL;
    return h;
}

int hashfn(int key) {
    unsigned h = 0;
    for (int i = 0; i < sizeof(int); i++)
        h = 31 * h + ((char*) &key)[i];
    return h;
}

void hashik_insert(Hashik *h, int key, void *value) {
    int i = hashfn(key) % h->tabsize;
    hptr_t new = (hptr_t) malloc(sizeof(Hnode));
    new->key = key;
    new->value = value;
    new->next = h->table[i];
    h->table[i] = new;
    h->size ++;
}

void *hashik_find(Hashik *h, int key) {
    int i = hashfn(key) % h->tabsize;
    for (hptr_t c = h->table[i]; c != NULL; c = c->next)
        if (c->key == key)
            return c->value;
    return NULL;
}

int main() {
    Hashik *h = new_hashik(1024);
    for (int i = 0; i < 1000; i++)
        hashik_insert(h, i, (void*) (i * i));

    printf("test\n");
    for (int i = 0; i < 1000; i++) {
        void *found = hashik_find(h, i);
        if (found == NULL)
            printf("h[%d] NOT FOUND!\n", i);
        else
            printf("h[%d] = %d\n", i, (int) found);
    }

    return 0;
}
