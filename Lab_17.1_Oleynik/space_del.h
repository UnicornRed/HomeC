#ifndef SPACE_DEL_H_INCLUDED
#define SPACE_DEL_H_INCLUDED

/* Функция удаляет кратные и находящиеся в начале и конце пробелы в строке str максимальной длины size_string.
 * Функция возвращает 1, если строка не была передана.
 * Функция возвращает 0 в остальных случаях.
 */
int space_del (char *str, size_t size_string);

#endif // SPACE_DEL_H_INCLUDED
