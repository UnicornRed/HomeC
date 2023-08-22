#ifndef SEARCH_MISSES_H_INCLUDED
#define SEARCH_MISSES_H_INCLUDED

/* Функция вычисляет среднее арифметическое элементов массива a размера size_a.
 * Функция возвращает NaN, если массив не был передан.
 * Функция возвращает значение mean, если массив передан корректно.
 */
double arithmetic_mean (size_t size_a, const double *a);

/* Функция вычисляет несмещенную оценку среднеквадратичного отклонения элементов массива a размера size_a.
 * Функция возвращает NaN, если массив не был передан.
 * Функция возвращает значение sqrt(mean), если массив передан корректно.
 */
double unbiased_root_mean_square (size_t size_a, const double *a);

/* Функция находит первое вхождение элемента miss, значение которого отклоняется от переданного значения mean
 * на некоторую величину variance, в хвосте массива a размера size_a_tail.
 * Функция возвращает NULL, если массив не был передан или такой элемент не был обнаружен.
 * Функция возвращает указатель miss, если массив передан корректно и такой элемент был обнаружен.
 */
const double* search_miss (size_t size_a_tail, double variance, double mean, const double *a);

/* Функция находит все промахи измерения в массиве a размера size_a и записывает их в массив miss_array.
 * Функция возвращает -1, если массив a или массив miss_array не были переданы.
 * Функция возвращает значение counter, если массивы были переданы корректно.
 */
size_t all_miss (size_t size_a, const double *a, double *miss_array);

#endif // SEARCH_MISSES_H_INCLUDED
