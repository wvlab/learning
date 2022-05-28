#include <stdio.h>
#include <stdbool.h>

/* Прототип функции */
long factorial(int n);

int main(int argc, const char* argv[]) {
    /*
     * В Си существует три вида циклов:
     * 1. while (expr) {foo();}
     * 2. do {foo();} while (expr);
     * 3. for(type var; expr; foo1()) {foo2();}
     * Различия while и do-while циклов в том, когда проверяется условие:
     * while проверяет на начале, do-while в конце, то бишь
     * while (0) {printf("while");} не выведет ничего, когда
     * do {printf("do-while");} while (0); выведет
     *
     * for loop удобен для итерирования каждого элемента массива
     * Замечание: пример будет в коде!
    */

    /* Добавим в массив факториалы от 0 до 9 с помощью do-while*/
    long f[10];
    int a = 0;
    do {
        f[a] = factorial(a);
        a++;
    } while (a < 10);

    /* Итерируем массив выводя факториалы*/
    for (int i = 0; i < 10; i++) {
        printf("%d! = %ld\n", i, f[i]);
    }

    return 0;
}


long factorial(int n) {
    /*
     * Факториалы отрицательных чисел - комплексные числа
     * поэтому возвращаем -1, свидетельствуя о ошибке
     */
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 1;
    }

    long r = (long) n;

    /* Если n == 0, то цикл прекращается*/
    while (--n) {
        r *= n;
    }

    return r;
}
