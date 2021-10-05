#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define LIST_CAPACITY 16


typedef struct arrayList {
    int length;
    int capacity;
    size_t size;
    void* data;

} arrayList;

static arrayList* initializeList(int size) {
    arrayList* list = malloc(sizeof(arrayList));
    list->length = 0;
    list->size = size;
    list->capacity = LIST_CAPACITY;
    list->data = calloc(list->capacity, list->size);
    return list;
}


static void resizeList(arrayList* list) {
    list->capacity *= 2;
    list->data = realloc(list->data, list->size);
}

static void addElementInList(arrayList* list, void* data) {
    if (list->length == list->capacity)
        resizeList(list);
    memcpy(list->data + list->length++ * list->size, data, list->size);
}

static void insertElementInList(arrayList* list, void* data, int index) {
    if (index <= list->length) {
        if (list->length + 1 == list->capacity) {
            resizeList(list);
        }
        list->length++;
        memmove(list->data + (index + 1) * list->size, list->data + index * list->size,
                list->size * (list->length - index));
        memcpy(list->data + index * list->size, data, list->size);
    }
}


static void clearList(arrayList* list) {
    list->length = 0;
    free(list->data);
    list->capacity = LIST_CAPACITY;
    list->data = calloc(list->capacity, list->size);
}

static void* getElement(arrayList* list, int index) {
    if (index < list->length)
        return list->data + index * list->size;
    else
        return NULL;
}

static int isListEmpty(arrayList* list) {
    return list->length == 0;
}

static void removeElementByIndex(arrayList* list, int index) {
    if (index == list->length - 1) {
        list->length--;
    } else if (index < list->length) {
        memmove(list->data + index * list->size, list->data + (index + 1) * list->size,
                (list->length - index) * list->size);
        list->length--;
    }
}

static void setElementByIndex(arrayList* list, void* elem, int index) {
    if (index < list->length) {
        memcpy(list->data + index * list->size, elem, list->size);
    }
}

static int getSize(arrayList* list) {
    return list->length;
}
