/* Стандартная защита от рекурсивного импортирования заголовка*/
#ifndef SNIP_SLINKED_LIST_H
#define SNIP_SLINKED_LIST_H
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* FIXME: namings aren't correct */
/*=============================*
 * Структура узла списка:      *
 * Данные                      *
 * Следующий узел              *
 *=============================*
*/
struct LinkedListNode
  {
    uint8_t *data;
    struct LinkedListNode *next;
  };
typedef struct LinkedListNode llist_node_t;


llist_node_t *newLinkedListNode(void);

void delLinkedListNode(llist_node_t*);

/*=============================*
 * Структура связного списка:  *
 * Длина                       *
 * Размер единицы              *
 * Указатель на первый узел    *
 * Указатель на последний узел *
 *=============================*
*/
struct LinkedList
  {
    size_t len;
    size_t _size;
    llist_node_t *first;
    llist_node_t * last;
  };
typedef struct LinkedList llist_t;

/* Конструктор*/
llist_t *_newLinkedList(size_t);
#define newLinkedList(type) (_newLinkedList(sizeof(type)))
/*Деструктор*/
void delLinkedList(llist_t*);
/* Функция добавления узлов */
bool addLList(llist_t*, size_t, void*);
#define addFirstLList(list, data) (addLList(list, 0, data))
#define addLastLList(list, data) (addLList(list, list->len, data))
/* Функции удаления узлов */
bool removeLList(llist_t*, size_t);
#define removeFirstLList(list, data) (addLList(list, 0, data))
#define removeLastLList(list, data) (addLList(list, list->len, data))
/* Сеттеры */
bool setLList(llist_t*, size_t, void*);
#define setFirstLList(list, data) (addLList(list, 0, data))
#define setLastLList(list, data) (addLList(list, list->len, data))
/* Геттеры */
void* getLList(llist_t*, size_t);
#define getFirstLList(list, data) (addLList(list, 0, data))
#define getLastLList(list, data) (addLList(list, list->len, data))
void clearLList(llist_t*);
void printLList(llist_t*, void(*)(void*, size_t));

#endif