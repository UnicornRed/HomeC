/* Лабораторная работа 13.23.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль вычисляет определённый интеграл (res_num_p) переданной функции fun (с параметрами в массиве param)
 * с границами a и b с разбиением на num точек через функцию midpoint с удвоением точек разбиения до точности accuracy.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "partition_integral.h"

/* Функция вычисляет определённый интеграл (res_num_p) переданной функции fun (с параметрами в массиве param)
 * с границами a и b с разбиением на num точек через функцию midpoint с удвоением точек разбиения до точности accuracy.
 * Функция возвращает NaN, если границы функции заданы некорректно или количество точек разбиения меньше 2.
 * Функция возвращает число, если данные заданы корректно.
 */
double partition_integral (double a, double b, double accuracy, double *param, fun_type fun, int_fun integral_fun)
{
    if (b < a)
        return 0.0 / 0.0;

    int num = 2;
    double res_num, res_num_p = midpoint(a, b, num, param, fun);

    do
    {
        res_num = res_num_p;
        num *= 2;
        res_num_p = integral_fun(a, b, num, param, fun);
    }
    while (fabs((res_num - res_num_p) / res_num_p) > accuracy);

    return res_num_p;
}
