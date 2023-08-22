/* ������������ ������ 18.2ab.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ��������� ������ str �� �����, ��������� �� ������� � ����� ��������� ������� ������������ � ������ �������� word, ���������� ���������� ���� � word.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "words_in_string.h"

/* ����������� ������, ���������� ������������� �����.
 */
const char punctuation_marks[20] = " ,.!?;:\'\"[]{}()-";

/* ������� ��������� ������� ����� token � ������ �������� word ������������ ����������� array_size � ���������� �� ���������
 * ����� ���������� ������� num_word.
 * ������� ���������� NULL, ���� token, word ��� num_word �� ���� �������� ��� num_word ��������� �� ������ ��� ����� �������.
 * ������� ���������� ��������� i �� ������������ ���������, ���� ����� ���� �������.
 * ������� ���������� ����������� ��������� num_word, ���� ����� �� ���� �������.
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

/* ������� ��������� ����� token � ������ �������� word ������������ ����������� array_size � ���������� �� ���������
 * ����� ���������� ������� num_word, ���� ��� ���, ��� ���������� 1 � ����������� ��� ���������, ���� ��� ����.
 * ������� ���������� NULL, ���� word ��� num_word �� ���� �������� ��� num_word ��������� �� ������ ��� ����� �������
 * ��� ��������� ������ � ������� word_have.
 * ������� ���������� ��������� num_word � ��������� �������.
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

/* ������� ��������� ������ str �� �����, ��������� �� ������� � ����� ��������� ������� ������������
 * � ������ �������� word ������������ ����������� array_size.
 * ������� ���������� -1, ���� ������ str ��� ������ word �� ���� �������� ��� ��������� ������ ��� ���������� �������� � ������.
 * ������� ���������� ��������������� �������� num_word-word � ��������� �������.
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

/* ������� ��������� ���������� ���� � ������� �������� word ������� num_different_word � ������������ ����������� array_size.
 * ������� ���������� -1, ���� ������ word �� ���� �������� ��� ������ ������� ����������� ��� ������ ������������ �����������.
 * ������� ���������� ��������������� �������� num_all_word � ��������� �������.
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
