/* Лабораторная работа 14.3ab.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль сравнивает элементы a и b.
 */

#include <stdio.h>
#include <stdlib.h>
#include "comparison_fun.h"

/* Функция сравнивает элементы a и b.
 * Функция возвращает -1, если a > b.
 * Функция возвращает 0, если a = b.
 * Функция возвращает 1, если a < b.
 */
int double_comparison (const void *a, const void *b)
{
    if (*((double*)a) > *((double*)b))
        return -1;
    else if (*((double*)a) == *((double*)b))
        return 0;
    else
        return 1;
}
