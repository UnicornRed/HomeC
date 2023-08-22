/* Лабораторная работа 18.2ab.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль разделяет строку str на слова, указатели на которые и число появлений которых записываются в массив структур word, определяет количество слов в word.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "words_in_string.h"

/* Константная строка, содержащая пунктационные знаки.
 */
const char punctuation_marks[20] = " ,.!?;:\'\"[]{}()-";

/* Функция проверяет наличие слова token в массив структур word максимальной вместимости array_size с указателем на следующий
 * после последнего элемент num_word.
 * Функция возвращает NULL, если token, word или num_word не были переданы или num_word указывает за начало или конец массива.
 * Функция возвращает указатель i на существующую структуру, если слово было найдено.
 * Функция возвращает неизменённый указатель num_word, если слово не было найдено.
 */
words_st * word_have (const char *token, words_st *word, words_st *num_word, size_t array_size)
{
    if (!token || !word || !num_word || num_word - word > array_size || num_word < word)
        return NULL;

    for (words_st *i = word; i < num_word; i ++)
    {
        if (!strcmp(token, i->word))
            return i;
    }

    return num_word;
}

/* Функция добавляет слово token в массив структур word максимальной вместимости array_size с указателем на следующий
 * после последнего элемент num_word, если его нет, или прибавляет 1 к количествам его появления, если оно есть.
 * Функция возвращает NULL, если word или num_word не были переданы или num_word указывает за начало или конец массива
 * или произошла ошибка в функции word_have.
 * Функция возвращает указатель num_word в остальных случаях.
 */
words_st * add_word (char *token, words_st *word, words_st *num_word, size_t array_size)
{
    if (!word || !num_word || num_word - word > array_size || num_word < word)
        return NULL;

    if (!token)
        return num_word;

    words_st *word_now;

    if (!(word_now = word_have(token, word, num_word, array_size)))
        return NULL;
    else
    {
        if (word_now != num_word)
            word_now->num ++;
        else
        {
            if (num_word - word + 1 > array_size)
                return num_word;
            else
            {
                num_word->word = token;
                num_word->num = 1;
                num_word ++;
            }
        }
    }

    return num_word;
}

/* Функция разделяет строку str на слова, указатели на которые и число появлений которых записываются
 * в массив структур word максимальной вместимости array_size.
 * Функция возвращает -1, если строка str или массив word не были переданы или произошла ошибка при добавлении элемента в массив.
 * Функция возвращает неотрицательное значение num_word-word в остальных случаях.
 */
int word_del (char *str, words_st *word, size_t array_size)
{
    if (!str || !word)
        return -1;

    char *token;
    words_st *num_word = word;

    token = strtok(str, punctuation_marks);

    while (token != NULL)
    {
        if (!(num_word = add_word(token, word, num_word, array_size)))
            return -1;

        token = strtok(NULL, punctuation_marks);
    }

    return num_word - word;
}

/* Функция вычисляет количество слов в массиве структур word размера num_different_word и максимальной вместимости array_size.
 * Функция возвращает -1, если массив word не были переданы или размер массива отрицателен или больше максимальной вместимости.
 * Функция возвращает неотрицательное значение num_all_word в остальных случаях.
 */
int all_word(const words_st *word, int num_different_word, size_t array_size)
{
    if (num_different_word > array_size || !word || num_different_word < 0)
        return -1;

    int num_all_word = 0;

    for (const words_st *i = word, *e = word + num_different_word; i < e; i ++)
        num_all_word += i->num;

    return num_all_word;
}
