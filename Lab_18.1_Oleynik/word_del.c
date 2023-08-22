/* Лабораторная работа 18.1.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль разделяет строку str на слова, указатели на которые записываются в массив word.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_del.h"

/* Функция разделяет строку str на слова, указатели на которые записываются в массив word.
 * Функция возвращает -1, если строка str или массив word не были переданы.
 * Функция возвращает положительное значение num_word в остальных случаях.
 */
int word_del (char *str, char **word)
{
    if (!str || !word)
        return -1;

    char *token;
    char **num_word = word;

    token = strtok(str, " ,.!?;:\'\"[]{}()-");

    if (token != NULL)
    {
        *num_word = token;
        num_word ++;
    }

    while (token != NULL)
    {
        token = strtok(NULL, " ,.!?;:\'\"[]{}()-");

        if (token != NULL)
        {
            *num_word = token;
            num_word ++;
        }
    }

    return num_word - word;
}
