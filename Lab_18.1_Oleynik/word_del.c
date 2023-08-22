/* ������������ ������ 18.1.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ��������� ������ str �� �����, ��������� �� ������� ������������ � ������ word.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_del.h"

/* ������� ��������� ������ str �� �����, ��������� �� ������� ������������ � ������ word.
 * ������� ���������� -1, ���� ������ str ��� ������ word �� ���� ��������.
 * ������� ���������� ������������� �������� num_word � ��������� �������.
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
