#ifndef PARTITION_INTEGRAL_H_INCLUDED
#define PARTITION_INTEGRAL_H_INCLUDED

#include "integral.h"

/* Псевдоним типа данных для передачи функции интегрирования.
 */
typedef double (*int_fun) (double, double, int, double *, fun_type);

/* Функция вычисляет определённый интеграл (res_num_p) переданной функции fun (с параметрами в массиве param)
 * с границами a и b с разбиением на num точек через функцию integral_fun с удвоением точек разбиения до точности accuracy.
 * Функция возвращает NaN, если границы функции заданы некорректно или количество точек разбиения меньше 2.
 * Функция возвращает число, если данные заданы корректно.
 */
double partition_integral (double a, double b, double accuracy, double *param, fun_type fun, int_fun integral_fun);

#endif // PARTITION_INTEGRAL_H_INCLUDED
