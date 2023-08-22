/* Лабораторная работа 12.3a.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль удаляет все чётные (нечётные) элементы массива m размера size_m со сдвигом.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "del_even_noteven_array.h"

/* Функция удаляет все чётные элементы массива m размера size_m со сдвигом.
 * Функция возвращает 0, если массив был передан неправильно.
 * Функция возвращает размер изменённого массива.
 */
int del_even_array (size_t size_m, int *m)
{
    if (!m)
        return -1;

    int *i_del = m;
    int middle;

    for (int *i = m; i < m + size_m; i ++)
    {
        middle = *i;
        *i = 0;
        if ((middle) % 2)
        {
            *i_del = middle;
            i_del ++;
        }
    }

    return i_del - m;
}

/* Функция удаляет все нечётные элементы массива m размера size_m со сдвигом.
 * Функция возвращает 0, если массив был передан неправильно.
 * Функция возвращает размер изменённого массива.
 */
int del_noteven_array (size_t size_m, int *m)
{
    if (!m)
        return -1;

    int *i_del = m;
    int middle;

    for (int *i = m; i < m + size_m; i ++)
    {
        middle = *i;
        *i = 0;
        if (!((middle) % 2))
        {
            *i_del = middle;
            i_del ++;
        }
    }

    return i_del - m;
}
