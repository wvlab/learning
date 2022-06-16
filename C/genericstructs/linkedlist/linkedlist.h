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
/* Функции добавления узлов */
bool addFirstLList(llist_t*, void*);

bool addLastLList(llist_t*, void*);

bool addLList(llist_t*, size_t, void*);
/* Функции удаления узлов */
bool removeFirstLList(llist_t*);

bool removeLastLList(llist_t*);

bool removeLList(llist_t*, size_t);
/* Сеттеры */
bool setFirstLList(llist_t*, void*);

bool setLastLList(llist_t*, void*);

bool setLList(llist_t*, size_t, void*);
/* Геттеры */
void* getFirstLList(llist_t*);

void* getLastLList(llist_t*);

void* getLList(llist_t*, size_t);

void clearLList(llist_t*);

void printLList(llist_t*, void(*)(void*, size_t));

#endif