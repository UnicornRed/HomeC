#ifndef SUBSTRING_H_INCLUDED
#define SUBSTRING_H_INCLUDED

/* Функция выделяет подстроку dst с началом в pos и размера num из строки str максимального размера size_string.
 * Функция возвращает 1, если строка или указатель на подстроку не были переданы или не было в строке элемента с нулевым кодом.
 * Функция возвращает 0 в остальных случаях.
 */
int substring (const char *str, int pos, int num, char *dst, size_t size_string);

#endif // SUBSTRING_H_INCLUDED
