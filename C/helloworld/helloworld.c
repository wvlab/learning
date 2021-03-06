#include <stdio.h>

/* Си — язык, что можно причислить к языкам "среднего уровня", 
 * он достаточно низкоуровневый(то бишь ближе к компьютеру), 
 * чтоб писать операционные системы на нём(к примерам далеко 
 * ходить не нужно! Linux), но не настолько, как языки Assembler'а.
 * Он вполне читаем как проза :)
 *
 * В верхней части программы находится "секция для препроцессора", да я сам
 * придумал. Обычно там находятся #include разных заголовков(header'ов).
 * Простейшая программа вывода строки использует заголовок stdio(что с
 * ельфийского STanDart Input Output). К ним вернёмся позже
 * Также здесь можно определить константы и макросы через #define
 * #define PI 3.14
 * (на стадии препроцессинга на всех местах где было PI появится 3.14)
 *
 * Дальше определяются глобальные переменные, о них будет позже
 * В этом же примере инициализируется глобальная переменная
 * string хранящая строку "Hello, World!"
 *
 * Следующая секция — начало вычислений, главная функция
 * она принимает либо ничего(void), либо argc, argv, где
 * argc — кол-во элементов массива argv
 * argv — массив аргументов
 * Сама функция main возвращает код завершения, 0, 1, -1, 2...
 * 0 — программа завершилась успешно
 * В функции main инициализируются локальные переменные, 
 * выполняются иные функции, выводятся данные и тд.

 * Функции putchar, puts, printf из stdio.h предназначены для вывода
 * текста, putchar — единичного символа, puts — строк
 * printf — форматированного текста */

const char string[] = "Hello, World!";

int
main (int argc, char *argv[])
{
    /* Также можно использовать printf(), но это здесь не нужно
    при наличии функции вывода строки без форматирования.
    Вы же не забиваете шурупы молотком? */
    puts(string);

    return 0;
}
