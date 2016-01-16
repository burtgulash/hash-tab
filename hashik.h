#ifndef _HASHIK_H_
#define _HASHIK_H_

typedef struct hnode *hptr_t;
typedef struct hnode {
    int key;
    void *value;
    hptr_t next;
} Hnode;

typedef struct hashik {
    int size;
    int tabsize;
    hptr_t *table;
} Hashik;

#endif
