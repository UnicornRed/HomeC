/* Лабораторная работа 14.2.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль вычисляет среднее арифметическое, несмещенную оценку среднеквадратичного отклонения,
 * находит первое вхождение элемента, значение которого отклоняется от переданного значения
 * на некоторую величину и все промахи измерения.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_misses.h"

/* Функция вычисляет среднее арифметическое элементов массива a размера size_a.
 * Функция возвращает NaN, если массив не был передан.
 * Функция возвращает значение mean, если массив передан корректно.
 */
double arithmetic_mean (size_t size_a, const double *a)
{
    if (!a)
        return 0.0 / 0.0;

    double mean = 0;

    for (const double *i = a; i < a + size_a; i ++)
        mean += (*i) / size_a;

    return mean;
}

/* Функция вычисляет несмещенную оценку среднеквадратичного отклонения элементов массива a размера size_a.
 * Функция возвращает NaN, если массив не был передан.
 * Функция возвращает значение sqrt(mean), если массив передан корректно.
 */
double unbiased_root_mean_square (size_t size_a, const double *a)
{
    if (!a)
        return 0.0 / 0.0;

    double mean = 0, ar_mean = arithmetic_mean(size_a, a);

    for (const double *i = a; i < a + size_a; i ++)
        mean += pow(*i - ar_mean, 2) / (size_a - 1);

    return sqrt(mean);
}

/* Функция находит первое вхождение элемента miss, значение которого отклоняется от переданного значения mean
 * на некоторую величину variance, в хвосте массива a размера size_a_tail.
 * Функция возвращает NULL, если массив не был передан или такой элемент не был обнаружен.
 * Функция возвращает указатель miss, если массив передан корректно и такой элемент был обнаружен.
 */
const double* search_miss (size_t size_a_tail, double variance, double mean, const double *a)
{
    if (!a)
        return NULL;

    for (const double *i = a; i < a + size_a_tail; i ++)
    {
        if (fabs(mean - *i) > variance)
        {
            return i;
        }
    }

    return NULL;
}

/* Функция находит все промахи измерения в массиве a размера size_a и записывает их в массив miss_array.
 * Функция возвращает -1, если массив a или массив miss_array не были переданы.
 * Функция возвращает значение counter, если массивы были переданы корректно.
 */
size_t all_miss (size_t size_a, const double *a, double *miss_array)
{
    if ((!a) || (!miss_array))
        return -1;

    const double *end_a = a + size_a, *element_a = a - 1;
    double *counter = miss_array;
    double mean, var;

    mean = arithmetic_mean(size_a, a);
    var = unbiased_root_mean_square(size_a, a);

    if (mean != mean || var != var)
        return -1;

    do
    {
        element_a = search_miss(size_a, var, mean, element_a + 1);

        if (element_a != NULL && element_a != end_a)
        {
            *counter = *element_a;
            counter ++;
            size_a = end_a - element_a;
        }
    } while (element_a != end_a && element_a != NULL);

    return counter - miss_array;
}
