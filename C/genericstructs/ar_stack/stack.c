#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

/* Конструктор стека */
stack_t* _newStack(size_t __size, size_t __len)
{
    stack_t* stack = malloc(sizeof(stack_t));
    if (stack == NULL)
    {
        fprintf(stderr, "Insufficient memory to init stack\n");
        exit(EXIT_FAILURE);
    }
    stack->len = __len;
    stack->index = 0;
    stack->_size = __size;
    stack->_arr = calloc(__size, __len);
    if (stack->_arr == NULL)
    {
        fprintf(stderr, "Insufficient memory to init stack storage\n");
    }

    return stack;
}


/*Деструктор стека*/
void deStack(stack_t* stack)
{
    free(stack->_arr);
    free(stack);

    return;
}


/* Удаляет последний элемент стека, возвращает указатель на копию
 * удалённого элемента.
 */
void* popStack(stack_t* stack) {
    if (isStackEmpty(stack))
    {
        fprintf(stderr, "Can't pop from an empty stack\n");
        return NULL;
    }

    size_t el = (stack->index -= 1) * stack->_size;
    uint8_t* result = malloc(stack->_size);
    if (result == NULL)
    {
        fprintf(stderr, "Insufficient memory to init value from stack\n");
        return NULL;
    }
    memcpy(result, stack->_arr + el, stack->_size);

    if (4 * (stack->index + 1) < stack->len)
    {
        void* temp = realloc(stack->_arr, stack->_size * (stack->len /= 2));
        if (temp == NULL)
        {
            fprintf(stderr, "Couldn't realloc memory\n");
            return NULL;
        }
        else
        {
            stack->_arr = temp;
        }
    }

    return (void*) result;
}

void* peekStack(stack_t* stack) {
    if (isStackEmpty(stack))
    {
        fprintf(stderr, "Can't peek from an empty stack\n");
        return NULL;
    }

    size_t el = (stack->index - 1) * stack->_size;
    uint8_t* result = malloc(stack->_size);
    if (result == NULL)
    {
        fprintf(stderr, "Insufficient memory to init value from stack\n");
        return NULL;
    }
    memcpy(result, stack->_arr + el, stack->_size);

    return (void*) result;
}

/* Добавляет в стек копию данных указываемых void* data размером с _size,
 * возвращает успешность выполнения
 */
bool pushStack(stack_t* stack, void* data) {
    if (isStackFull(stack)) {
        void* temp = realloc(stack->_arr, stack->_size * (stack->len *= 2));
        if (temp == NULL) {
            fprintf(stderr, "Couldn't realloc memory\n");
            return false;
        } else {
            stack->_arr = temp;
        }
    }

    size_t el = stack->index * stack->_size;
    memcpy(stack->_arr + el, data, stack->_size);
    stack->index += 1;
    return true;   
}

/* Проверяет есть ли в стеке элементы */
bool isStackEmpty(const stack_t* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Stack doesn't exist anymore\n");
        exit(EXIT_FAILURE);
    }
    if (stack->index == 0) {
        return true;
    }

    return false;
}

/* Проверяет полон ли стек */
bool isStackFull(const stack_t* stack) {
    if (stack == NULL) {
        fprintf(stderr, "Stack doesn't exist anymore\n");
        exit(EXIT_FAILURE);
    }
    if (stack->index + 1 > stack->len) {
        return true;
    }

    return false;
}