#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define LIST_CAPACITY 16


typedef struct alist_t {
    int len;
    int cap;
    size_t size;
    void* data;

} alist_t;

static alist_t* initializeList(int size) {
    alist_t* list = malloc(sizeof(alist_t));
    list->len = 0;
    list->size = size;
    list->cap = LIST_CAPACITY;
    list->data = calloc(list->cap, list->size);
    return list;
}


static void resizeList(alist_t* list) {
    list->cap *= 2;
    list->data = realloc(list->data, list->size);
}

static void addElementInList(alist_t* list, void* data) {
    if (list->len == list->cap)
        resizeList(list);
    memcpy(list->data + list->len++ * list->size, data, list->size);
}

static void insertElementInList(alist_t* list, void* data, int index) {
    if (index <= list->len) {
        if (list->len + 1 == list->cap) {
            resizeList(list);
        }
        list->len++;
        memmove(list->data + (index + 1) * list->size, list->data + index * list->size,
                list->size * (list->len - index));
        memcpy(list->data + index * list->size, data, list->size);
    }
}


static void clearList(alist_t* list) {
    list->len = 0;
    free(list->data);
    list->cap = LIST_CAPACITY;
    list->data = calloc(list->cap, list->size);
}

static void* getElement(alist_t* list, int index) {
    if (index < list->len)
        return list->data + index * list->size;
    else
        return NULL;
}

static int isListEmpty(alist_t* list) {
    return list->len == 0;
}

static void removeElementByIndex(alist_t* list, int index) {
    if (index == list->len - 1) {
        list->len--;
    } else if (index < list->len) {
        memmove(list->data + index * list->size, list->data + (index + 1) * list->size,
                (list->len - index) * list->size);
        list->len--;
    }
}

static void setElementByIndex(alist_t* list, void* elem, int index) {
    if (index < list->len) {
        memcpy(list->data + index * list->size, elem, list->size);
    }
}

static int getSize(alist_t* list) {
    return list->len;
}
