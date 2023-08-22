/* ������������ ������ 18.2ab.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "words_in_string.h"

#define STRING_SIZE 1001
#define ARRAY_SIZE 100

int main()
{
    setlocale(LC_ALL, "Russian");

    FILE* f = fopen("input.txt", "r");

    if (!f)
    {
        printf("������ �������� �����!\n");

        return 1;
    }

    char str[STRING_SIZE], str_copy[STRING_SIZE];
    words_st word[ARRAY_SIZE];
    int num_different_word, num_all_word;

    if (!(fgets(str, STRING_SIZE, f)))
    {
        printf("������ ������ ������!\n");

        fclose (f);

        return 1;
    }

    fclose (f);

    printf("�������� ������: \"%s\".\n", str);

    strncpy(str_copy, str, STRING_SIZE);

    num_different_word = word_del(str_copy, word, ARRAY_SIZE);

    if (num_different_word == 0)
        printf("� ������ ��� ����.\n");
    else if (num_different_word == -1)
    {
        printf("������ �������� ������ ��� ������� ��� ������ ����������!\n");

        return 1;
    }
    else
    {
        printf("����� ��������� ���� � ������: %d. ����� � ������:\n", num_different_word);

        if ((num_all_word = all_word(word, num_different_word, ARRAY_SIZE)) == -1)
        {
            printf("������ �������� ������� ��� ����� ��������� ���� ������ ����������� �������!\n");

            return 1;
        }

        for (words_st *i = word, *e = word + num_different_word; i < e; i ++)
            printf("\"%s\" ����������� %d ���(�), ������� ������������� %.3f%c;\n", i->word, i->num, (double)(i->num) / num_all_word * 100, '%');
    }

    return 0;
}

