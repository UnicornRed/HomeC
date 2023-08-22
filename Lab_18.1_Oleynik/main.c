/* Лабораторная работа 18.1.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "word_del.h"

#define STRING_SIZE 1001
#define ARRAY_SIZE 100

int main()
{
    setlocale(LC_ALL, "Russian");

    FILE* f = fopen("input.txt", "r");

    if (!f)
    {
        printf("Ошибка открытия файла!\n");

        return 1;
    }

    char str[STRING_SIZE], str_copy[STRING_SIZE];
    char *word[ARRAY_SIZE];
    int num_word;

    if (!(fgets(str, STRING_SIZE, f)))
    {
        printf("Ошибка чтения строки!\n");

        fclose (f);

        return 1;
    }

    fclose (f);

    printf("Введённая строка: \"%s\".\n", str);

    strncpy(str_copy, str, STRING_SIZE);

    num_word = word_del(str_copy, word);

    if (num_word == 0)
        printf("В строке нет слов.\n");
    else if (num_word == -1)
    {
        printf("Ошибка передачи строки или массива!\n");

        return 1;
    }
    else
    {
        printf("Слова в строке:\n");

        for (char **i = word, **e = word + num_word; i < e; i ++)
            printf("\"%s\"\n", *i);
    }

    return 0;
}
