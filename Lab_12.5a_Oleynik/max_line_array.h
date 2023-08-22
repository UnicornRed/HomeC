#ifndef MAX_LINE_ARRAY_H_INCLUDED
#define MAX_LINE_ARRAY_H_INCLUDED

#define ARRAY_SIZE 100

/* Функция определяет номер строки массива a размера size_a_h на size_a_w с наибольшей суммой элементов.
 * Функция возвращает 0, если массив был передан неверно.
 * Функция возвращает номер строки (начиная с 1), если переданные данные корректны.
 */
int max_line_array (size_t size_a_h, size_t size_a_w, const double a[][ARRAY_SIZE]);

#endif // MAX_LINE_ARRAY_H_INCLUDED
