#ifndef BINARY_MODULE_H_INCLUDED
#define BINARY_MODULE_H_INCLUDED

/* Псевдоним типа данных для передачи функции сравнения элементов.
 */
typedef int (*com_fun) (const void *, const void *);

/* Функция находит элемент со значением mean в массиве a размера size_t.
 * Сравнение через функцию com_F. Размер типа s_type.
 * Функция возвращает NULL, если массив не был передан или элемент не найден.
 * Функция возвращает указатель на элемент, если он найден.
 */
const void* bin_search (size_t size_a, size_t s_type, const void *mean, const void *a, com_fun com_F);

/* Функция находит место вставки со значением mean в массиве a размера size_t.
 * Сравнение через функцию com_F. Размер типа s_type.
 * Функция возвращает -1, если массив не был передан.
 * Функция возвращает индекс элемента, если массив был передан.
 */
size_t bin_place (size_t size_a, size_t s_type, const void *mean, const void *a, com_fun com_F);

#endif // BINARY_MODULE_H_INCLUDED
