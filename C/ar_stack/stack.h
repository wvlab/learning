/* Стандартная защита от рекурсивного импортирования заголовка*/
#ifndef SNIP_STACK_H
#define SNIP_STACK_H
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/*============================*
 * Структура Стека:           *
 * Длина                      *
 * Текущий элемент            *
 * Размер единицы             *
 * Указатель на начало массива*
 *============================*
*/
struct Stack
  {
    size_t len;
    size_t index;
    size_t _size;
    uint8_t* _arr;
  };
typedef struct Stack stack_t;

#define newStack(type, len) (_newStack(sizeof(type), len))
/*Конструктор*/
stack_t* _newStack(size_t, size_t);
/*Деструктор*/
void deStack(stack_t*);

/*Стандартные действия*/
void* popStack(stack_t*);
void pushStack(stack_t*, void*);

bool isStackEmpty(const stack_t*);
bool isStackFull(const stack_t*);
#endif