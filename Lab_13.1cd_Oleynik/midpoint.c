/* Лабораторная работа 13.1c.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль вычисляет определённый интеграл (solve_int) методом средних прямоугольников
 * переданной функции fun (с параметрами в массиве param) с границами a и b с разбиением на num точек.
 */

#include <stdio.h>
#include <stdlib.h>
#include "integral.h"

/* Функция вычисляет определённый интеграл (solve_int) методом средних прямоугольников
 * переданной функции fun (с параметрами в массиве param) с границами a и b с разбиением на num точек.
 * Функция возвращает NaN, если границы функции заданы некорректно или количество точек разбиения меньше 2.
 * Функция возвращает число, если данные заданы корректно.
 */
double midpoint (double a, double b, int num, double *param, fun_type fun)
{
    if (b < a || num < 2)
        return 0.0 / 0.0;

    double solve_int, step = (b - a) / (num - 1);

    for (int i = 0; i < num - 2; i ++)
    {
        solve_int += fun(a + step / 2, param) * step;
        a += step;
    }

    solve_int += fun((a + b) / 2, param) * (b - a);

    return solve_int;
}
