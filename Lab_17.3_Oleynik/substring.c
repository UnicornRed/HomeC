/* Лабораторная работа 17.3.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль выделяет подстроку dst с началом в pos и размера num из строки str максимального размера size_string.
 */

#include <stdio.h>
#include <stdlib.h>
#include "substring.h"

/* Функция выделяет подстроку dst с началом в pos и размера num из строки str размера length_str.
 */
void substring_fun (const char *str, int pos, int num, char *dst, size_t length_str)
{
    char *idst = dst;

    for (const char *i = str + pos, *e = str + pos + num; i < e; i ++, idst ++)
        *idst = *i;

    *idst = '\0';
}

/* Функция выделяет подстроку dst с началом в pos и размера num, преобразуя их, из строки str максимального размера size_string.
 * Функция возвращает 1, если строка или указатель на подстроку не были переданы или не было в строке элемента с нулевым кодом.
 * Функция возвращает 0 в остальных случаях.
 */
int substring (const char *str, int pos, int num, char *dst, size_t size_string)
{
    if (!str || !dst)
        return 1;

    const char *i = str;
    int length_str = 0;

    while (*i != '\0')
    {
        length_str ++;
        i ++;

        if (i - str >= size_string)
            return 1;
    }

    if (pos < (-1) * length_str || pos >= length_str)
        num = 0;
    else
    {
        if (pos < 0)
            pos = length_str + pos;

        if (num < 0)
        {
            if (pos + num < 0)
            {
                num = pos + 1;
                pos = 0;
            }
            else
            {
                pos += (num + 1);
                num *= (-1);
            }
        }

        if (num == 0 || pos + num > length_str)
            num = length_str - pos;
    }

    substring_fun(str, pos, num, dst, length_str);

    return 0;
}
