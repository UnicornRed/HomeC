/* Лабораторная работа 17.1.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "space_del.h"

#define STRING_SIZE 1001

int main()
{
    setlocale(LC_ALL, "Russian");

    FILE* f = fopen("input.txt", "r");

    if (!f)
    {
        printf("Ошибка открытия файла!\n");

        return 1;
    }

    char str[STRING_SIZE];

    if (!(fgets(str, STRING_SIZE, f)))
    {
        printf("Ошибка чтения строки!\n");

        fclose (f);

        return 1;
    }

    fclose (f);

    printf("Введённая строка: \"%s\".\n", str);

    if (space_del(str, STRING_SIZE))
    {
        printf("Ошибка функции!\n");

        return 1;
    }

    printf("Строка без \"лишних\" пробелов: \"%s\".\n", str);

    return 0;
}
