#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>


llist_node_t *
newLinkedListNode (void)
{
    llist_node_t *node = malloc(sizeof(llist_node_t));
    if (node == NULL)
        fprintf(stderr, "Insufficient memory to create new node\n");

    return node;
}


/* Конструктор списка */
llist_t *
_newLinkedList (size_t size)
{
    llist_t *list = malloc(sizeof(llist_t));
    list->len = 0;
    list->_size = size;
    list->first = NULL;
    list->last = NULL;

    return list;
}


/* Деструктор */
void
delLinkedList (llist_t *list)
{
    llist_node_t *node = list->first;
    llist_node_t *buf = NULL;
    free(list);
    while (node != NULL)
      {
        buf = node->next;
        free(node);
        node = buf;
      }

    return;
}


/* Функции добавления узлов */
bool
addFirstLList (llist_t *list, void *data)
{
    return addLList(list, 0, data);
}


bool
addLastLList (llist_t *list, void *data)
{
    return addLList(list, list->len - 1, data);
}


bool
addLList (llist_t* list, size_t index, void *data)
{
    llist_node_t *new_node;

    if (list == NULL)
      {
        fprintf(stderr, "Linked list does not exist anymore\n");
        return false;
      }
    
    if (index > list->len)
      {
        fprintf(stderr, "IndexError: linked list index out of range\n");
        return false;
      }

    new_node = newLinkedListNode();
    if (new_node == NULL)
        return false;

    new_node->data = malloc(list->_size);
    if (new_node->data == NULL)
      {
        fprintf(stderr, "Insufficient memory to allocate node data\n");
        // delLinkedListNode(new_node);
        return false;
      }
    memcpy(new_node->data, data, list->_size);

    if (index == (list->len - 1))
      {
        if (list->last != NULL)
            list->last->next = new_node;
        list->last = new_node;
        if (list->len == 0)
            list->first = new_node;
      }
    else if (index == 0)
      {
        new_node->next = list->first;
        list->first = new_node;
        if (list->len == 0)
            list->last = new_node;
      }
    else
      {
        llist_node_t *buf = list->first;
        for (size_t i = 0; i < (index - 1); i++)
            buf = buf->next;

        new_node->next = buf->next;
        buf->next = new_node;
      }

    list->len += 1;
    return true;
}


/* Функции удаления узлов */
bool
removeFirstLList (llist_t* list)
{

}


bool
removeLastLList(llist_t*)
{

}


bool
removeLList(llist_t*, size_t)
{

}


/* Сеттеры */
bool
setFirstLList (llist_t*, void*)
{

}


bool
setLastLList(llist_t*, void*)
{

}


bool
setLList(llist_t*, size_t, void*)
{


}
/* Геттеры */
void *
getFirstLList (llist_t*, void*)
{

}


void *
getLastLList (llist_t*, void*)
{

}


void *
getLList(llist_t*, size_t, void*)
{

}


bool
clearLList(llist_t*)
{

}

/* TODO: sort method */

void
printLList (llist_t* list, void (*__printdata) (void*, size_t))
{
    llist_node_t *buf = list->first;
    printf("[");
    for (size_t i = 0; i < list->len; i++)
      {
        __printdata(buf->data, list->_size);
        buf = buf->next;
        printf(", ");
      }
    printf("\b\b]\n");

    return;
}