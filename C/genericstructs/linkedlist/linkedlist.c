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
_NewLinkedList (size_t size)
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
    return addLList(list, list->len, data);
}


bool
addLList (llist_t* list, size_t index, void *data)
{
    if (list == NULL)
      {
        fprintf(stderr, "Linked list does not exist anymore\n");
        return false;
      }
    


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