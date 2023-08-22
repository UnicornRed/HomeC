/* Лабораторная работа 12.3b.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль удаляет все повторяющиеся элементы массива m размера size_m со сдвигом, оставляя первое включение числа.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "del_norepeat.h"

#define ARRAY_SIZE 1000

int del_norepeat (size_t size_m, double *m)
{
    if (m == 0)
        return -1;

    int i_del = 0;
    double e = 1e-10;

    for (int i = 0; i < size_m; i ++)
    {
        int check = 0;
        for (int j = 0; j < i_del && check != 1; j ++)
            if (fabs(m[i] - m[j]) < e * fmin(fabs(m[i]), fabs(m[j])))
                check = 1;
        if (check == 0)
        {
            m[i_del] = m[i];
            if (i_del != i)
                m[i] = 0;
            i_del ++;
        }
        else
            m[i] = 0;
    }

    return i_del;
}
