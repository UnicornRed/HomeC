#ifndef COLLECTION_OF_FUNCTIONS_H_INCLUDED
#define COLLECTION_OF_FUNCTIONS_H_INCLUDED

/* Функция вычисляет значение кубической функции y = a * x ^ 3 + b * x ^ 2 + c * x + d
 * с переданными параметрами через массив param в заданной точке x.
 * Функция возвращает число - значение в точке.
 */
double cub_function (double x, double *param);

/* Функция вычисляет значение квадратичной функции y = a * x ^ 2 + b * x + c
 * с переданными параметрами через массив param в заданной точке x.
 * Функция возвращает число - значение в точке.
 */
double squ_function (double x, double *param);

/* Функция вычисляет значение функции синуса y = a * sin(b * x)
 * с переданными параметрами через массив param в заданной точке x.
 * Функция возвращает число - значение в точке.
 */
double sin_function (double x, double *param);

/* Функция вычисляет значение экспоненциальной функции y = a * e ^ (b * x)
 * с переданными параметрами через массив param в заданной точке x.
 * Функция возвращает число - значение в точке.
 */
double exp_function (double x, double *param);

#endif // COLLECTION_OF_FUNCTIONS_H_INCLUDED
