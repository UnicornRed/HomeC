/*  Лабораторная работа 11.1b.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dig_sqrt.h"

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, p;

    printf ("Введите систему счисления и число: ");

    if (scanf("%d%d", &p, &n) != 2)
    {
        printf ("Ошибка ввода! Необходимо ввести 2 целых числа!\n");
        return 1;
    }

    printf ("Цифровой корень числа %d в системе счисления %d равен: %d\n", n, p, dig_sqrt(p, n));
    return 0;
}
