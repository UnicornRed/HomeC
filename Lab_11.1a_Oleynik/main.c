/*  Лабораторная работа 11.1a.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "sum_num.h"

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, p;

    printf("Введите систему счисления и число: ");
    if (scanf("%d%d", &p, &n) != 2)
    {
        printf("Ошибка ввода! Необходимо ввести 2 целых числа!\n");
        return 1;
    }

    printf("Сумма цифр числа %d в системе счисления %d равна: %d\n", n, p, sum_num(p, n));
    return 0;
}
