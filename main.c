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
    hashek_put(h, '1');
    hashek_put(h, '2');
    hashek_put(h, '3');
    hashek_put(h, '4');
    hashek_put(h, '5');
    hashek_put(h, '6');
    hashek_put(h, '7');
    hashek_put(h, '8');
    hashek_put(h, 'a');
    hashek_put(h, 'b');
    hashek_put(h, 'c');
    hashek_put(h, 'd');
    hashek_put(h, '9');

    printf("found %c\n", hashek_get(h, '9'));
    hashek_delete(h, '9');
    hashek_delete(h, '9');
    printf("found %c\n", hashek_get(h, '9'));

    return 0;
}
