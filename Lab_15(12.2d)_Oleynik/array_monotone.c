/* Лабораторная работа 15.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль, вычисляющий длину наибольшего промежутка монотонности в вещественном массиве a длины size_a.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array_monotone.h"

int array_monotone (size_t size_a, const double *a)
{
    if (a == 0)
        return -1;

    int length_up = 1, length_down = 1, length_max = 0;
    const double e = 1e-10;

    if (size_a == 1)
        length_max = 1;

    for (int i = 1; i < size_a;  i++)
    {
        if (a[i] - a[i - 1] > -e * fabs(a[i]))
        {
            length_up ++;
            length_down = 1;
        }
        else if (a[i] - a[i - 1] < e * fmin(fabs(a[i - 1]), fabs(a[i])))
        {
            length_down ++;
            length_up = 1;
        }
        else
        {
            length_up ++;
            length_down ++;
        }
        length_max = length_max > length_up ? length_max : length_up;
        length_max = length_max > length_down ? length_max : length_down;
    }

    return length_max;
}
