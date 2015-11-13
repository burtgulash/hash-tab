#include <stdio.h>
#include "hashek.h"

int main() {
    hashek *h = hashek_new();
    hashek_put(h, '5');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '7');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '7');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_delete(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '7');
    hashek_put(h, '9');
    hashek_delete(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_delete(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '7');
    hashek_put(h, '9');
    hashek_delete(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_put(h, '9');
    hashek_delete(h, '9');
    hashek_delete(h, '9');
    hashek_delete(h, '9');

    printf("found %c\n", hashek_get(h, '9'));
    hashek_delete(h, '9');
    hashek_delete(h, '9');
    printf("found %c\n", hashek_get(h, '9'));

    return 0;
}
