/* Лабораторная работа 12.1.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль ввода и вывода целочисленного и вещественного массивов.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan_print_array.h"

int scan_array (size_t size_m, int *m)
{
    if (m == 0)
        return 1;
    for (int i = 0; i < size_m; i ++)
        if (scanf("%d", &m[i]) != 1)
            return 1;
    return 0;
}

int print_array (size_t size_m, const int *m)
{
    if (m == 0)
        return 1;
    for (int i = 0; i < size_m; i ++)
        printf("%d\n", m[i]);
    return 0;
}

int fscan_array (size_t size_a, double *a)
{
    if (a == 0)
        return 1;
    for (int i = 0; i < size_a; i ++)
        if (scanf("%lf", &a[i]) != 1)
            return 1;
    return 0;
}

int fprint_array (size_t size_a, const double *a)
{
    if (a == 0)
        return 1;
    for (int i = 0; i < size_a; i ++)
        printf("%f\n", a[i]);
    return 0;
}
