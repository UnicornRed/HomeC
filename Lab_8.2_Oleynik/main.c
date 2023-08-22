/*  Лабораторная работа 8.2.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int b_st (int n, int m)
{
    int pr = abs(m) <= 1 ? m : 1;
    while (abs(pr) < abs(n))
    {
        pr *= m;
        if (pr == 1 || pr == 0)
            break;
    }
    if (pr == n || (n == 1 && m == -1))
        return 1;
    else
        return 0;
}

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, m;

    printf("Введите 2 числа: ");
    if (scanf("%d%d", &n, &m) != 2)
    {
        printf("Ошибка ввода! Необходимо ввести 2 целых числа!\n");
        return 1;
    }

    if (b_st(n, m))
        printf("Число %d является натуральной степенью числа %d.\n", n, m);
    else
        printf("Число %d не является натуральной степенью числа %d.\n", n, m);
    return 0;
}
