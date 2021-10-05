#include <stdio.h>
#include <time.h>
#include "arraylist.h"

int main() {
    int a = 13, b = 20, c = 22, cc = 66, x = 0, y = 43, i;
    srand(time(0));

    arrayList* intlist = initializeList(sizeof(int));
    addElementInList(intlist, &a);
    addElementInList(intlist, &b);
    addElementInList(intlist, &c);
    insertElementInList(intlist, &cc, 3);
    setElementByIndex(intlist, &y, 1);

    assert(intlist->size == sizeof(int));
    assert(13 == *(int*) getElement(intlist, 0));
    assert(43 == *(int*) getElement(intlist, 1));
    assert(22 == *(int*) getElement(intlist, 2));
    assert(66 == *(int*) getElement(intlist, 3));

    for(i = 0;i < getSize(intlist);i++) {
        printf("%d ", *(int*)getElement(intlist, i));
    }
}
