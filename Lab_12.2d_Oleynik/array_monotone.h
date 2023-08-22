#ifndef ARRAY_MONOTONE_H_INCLUDED
#define ARRAY_MONOTONE_H_INCLUDED

/* Функция вычисляет длину участка наибольшей монотонности в массиве a размера size_a.
 * Функция возвращает -1, если массив был передан неверно.
 * Функция возвращает неотрицательное целое число, если длина вычислена без ошибок.
 */
int array_monotone (size_t size_a, const double *a);

#endif // ARRAY_MONOTONE_H_INCLUDED
