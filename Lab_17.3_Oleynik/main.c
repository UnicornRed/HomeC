/* Лабораторная работа 17.3.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "substring.h"
#include "check_test.h"

#define STRING_SIZE 1001

int main()
{
    setlocale(LC_ALL, "Russian");

    /* Автоматическая проверка.*/

    check_fun F = substring;

    int bool_check = check_test(F);

    if (bool_check == 2)
        return 1;
    else if (bool_check == 1)
    {
        printf("Ошибка ввода!\n\n");
        return 1;
    }
    else
        printf("Проверка пройдена!\n\n");

    /* Ввод пользователем.*/

    FILE* f = fopen("input.txt", "r");

    if (!f)
    {
        printf("Ошибка открытия файла!\n");

        fclose (f);

        return 1;
    }

    char str[STRING_SIZE], dst[STRING_SIZE];
    int pos, num;

    if (!(fgets(str, STRING_SIZE, f)))
    {
        printf("Ошибка чтения строки!\n");

        fclose (f);

        return 1;
    }

    fclose (f);

    printf("Введённая строка: \"%s\".\n"
           "Введите индекс первого элемента подстроки и её размер: ", str);

    if (scanf("%d%d", &pos, &num) != 2)
    {
        printf ("Ошибка ввода! Необходимо ввести 2 целых числа!\n");

        return 1;
    }

    if (substring(str, pos, num, dst, STRING_SIZE))
    {
        printf("Ошибка!\n");

        return 1;
    }

    printf("Подстрока с позиции %d длинной %d: \"%s\".\n", pos, num, dst);

    return 0;
}
