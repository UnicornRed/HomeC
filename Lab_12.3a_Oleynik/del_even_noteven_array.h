#ifndef DEL_EVEN_NOTEVEN_ARRAY_H_INCLUDED
#define DEL_EVEN_NOTEVEN_ARRAY_H_INCLUDED

/* Функция удаляет все чётные элементы массива m размера size_m со сдвигом.
 * Функция возвращает 0, если массив был передан неправильно.
 * Функция возвращает размер изменённого массива.
 */
int del_even_array (size_t size_m, int *m);

/* Функция удаляет все нечётные элементы массива m размера size_m со сдвигом.
 * Функция возвращает 0, если массив был передан неправильно.
 * Функция возвращает размер изменённого массива.
 */
int del_noteven_array (size_t size_m, int *m);

#endif // DEL_EVEN_NOTEVEN_ARRAY_H_INCLUDED
