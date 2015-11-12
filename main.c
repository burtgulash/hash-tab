#include <stdio.h>
#include "listik.h"

int main() {
    printf("start\n");
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
