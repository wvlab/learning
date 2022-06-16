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

void
delLinkedListNode (llist_node_t *node)
{
    free(node->data);
    free(node);

    return;
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


/* Деструктор списка*/
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

bool
__check_llist_index (llist_t *list, size_t index)
{
    if (list == NULL)
      {
        fprintf(stderr, "Linked list does not exist anymore\n");
        return false;
      }
    if (index > (list->len - 1))
      {
        fprintf(stderr, "IndexError: linked list index out of range\n");
        return false;
      }
    return true;
}

/* Функция добавления узлов */

bool
addLList (llist_t *list, size_t index, void *data)
{
    llist_node_t *new_node;
    llist_node_t *buf;

    if (!__check_llist_index(list, index))
        return false;

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
        buf = list->first;
        for (size_t i = 0; i < (index - 1); i++)
            buf = buf->next;

        new_node->next = buf->next;
        buf->next = new_node;
      }

    list->len += 1;
    return true;
}


/* Функция удаления узлов */
bool
removeLList(llist_t *list, size_t index)
{
    llist_node_t *buf, *removed_next;
    if (!__check_llist_index(list, index))
        return false;

    list->len -= 1;
    if (index == 0)
      {
        buf = list->first->next;
        delLinkedListNode(list->first);
        list->first = buf;

        return true;
      }
      
    buf = list->first;
    for (size_t i = 0; i < (index - 1); i++)
        buf = buf->next;
    removed_next = buf->next->next;
    delLinkedListNode(buf->next);
    buf->next = removed_next;

    if (index == list->len)
        list->last = buf;
    
    return true;
}


/* Сеттер */
bool
setLList (llist_t *list, size_t index, void *data)
{
    if (!__check_llist_index(list, index))
        return false;

    llist_node_t *buf;
    if (index == 0)
        buf = list->first;
    else if (index == (list->len - 1))
        buf = list->last;
    else
      {
        buf = list->first;
        for (size_t i = 0; i < index; i++)
            buf = buf->next;
      }
    memcpy(buf->data, data, list->_size);

    return true;
}

/* Геттер */
void *
getLList (llist_t *list, size_t index)
{
    if (!__check_llist_index(list, index))
        return NULL;

    if (index == (list->len - 1))
        return list->last->data;

    llist_node_t *buf = list->first;
    for (size_t i = 0; i < index; i++)
        buf = buf->next;

    return buf->data;
}


void
clearLList (llist_t* list)
{
    llist_node_t *buf;
    list->last = NULL;
    while ((buf = list->first) != NULL)
      {
        list->first = buf->next;
        delLinkedListNode(buf);
      }
    
    return;
}

/* TODO: sort method */

void
printLList (llist_t* list, void (*__print_el) (void*, size_t))
{
    if (list->len == 0)
        return;

    printf("[");
    for (llist_node_t *i = list->first; i != NULL; i = i->next)
      {
        __print_el(i->data, list->_size);
        printf(", ");
      }
    printf("\b\b]\n");

    return;
}