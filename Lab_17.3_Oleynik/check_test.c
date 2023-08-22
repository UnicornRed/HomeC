/* Лабораторная работа 17.3.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль проверяет функцию F на строке из файла input.txt и тестовых значениях начала и размера подстроки из файла input_test.txt.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "check_test.h"

#define STRING_SIZE 1001

/* Функция сравнивает строки str1 и str2.
 * Функция возвращает -1, если строки не были переданы.
 * Функция возвращает 1, если строки не равны.
 * Функция возвращает 0, если строки равны.
 */
int str_comp (char *str1, char *str2)
{
    if (!str1 || !str2)
        return -1;

    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
            return 1;

        str1 ++;
        str2 ++;
    }

    if (*str1 != *str2)
        return 1;

    return 0;
}

/* Функция проверяет функцию F на строке, тестовых значениях начала и размера подстроки из файла input_test.txt.
 * Функция возвращает 2, если от функция F был получен неверный ответ.
 * Функция возвращает 1, если файлы не были открыты, произошла ошибка в функции F или str_comp или ошибка с чтением строк или начала или размера подстроки.
 * Функция возвращает 0 в остальных случаях.
 */
int check_test (check_fun F)
{
    FILE* f_test = fopen("input_test.txt", "r");

    if (!f_test)
    {
        printf("Ошибка открытия файла!\n");

        fclose (f_test);

        return 1;
    }

    char str[STRING_SIZE], dst[STRING_SIZE], true_str[STRING_SIZE];
    int pos, num, bool_check, bool_comp;

    while ((bool_check = (fscanf(f_test, "%1001s", str) != -1)))
    {
        if (!bool_check)
        {
            printf("Ошибка чтения строки!\n");

            fclose (f_test);

            return 1;
        }

        printf("Введённая строка: \"%s\".\n\n", str);

        if (fscanf(f_test, "%d%d", &pos, &num) != 2)
        {
            printf("Ошибка чтения начала или длина подстроки!\n");

            fclose (f_test);

            return 1;
        }

        printf("Введённые позиция начала и длина подстроки: %d %d.\n", pos, num);

        if (fscanf(f_test, "%1001s", true_str) == -1)
        {
            printf("Ошибка чтения строки!\n");

            fclose (f_test);

            return 1;
        }

        if (true_str[0] == '\\' && true_str[1] == '0')
            true_str[0] = '\0';

        printf("Правильная подстрока: \"%s\".\n", true_str);

        if (F(str, pos, num, dst, STRING_SIZE))
        {
            printf("Ошибка выполнения функции!");

            fclose (f_test);

            return 1;
        }

        printf("Полученная подстрока: \"%s\".\n", dst);

        bool_comp = str_comp(true_str, dst);

        if (!bool_comp)
            printf ("Ответ верен!\n\n");
        else if (bool_comp == -1)
            return 1;
        else
        {
            printf ("\nОтвет неверен!\n");

            fclose (f_test);

            return 2;
        }
    }

    fclose (f_test);

    return 0;
}
