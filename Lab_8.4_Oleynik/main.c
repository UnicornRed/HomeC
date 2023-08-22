/*  Лабораторная работа 8.4.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*функция, вычисляющая количество p-ичных разрядов в числе n*/
int discharge (int p, int n)
{
    int k;
    if (n == 0)
        k = 1;
    while (abs(n) > 0)
    {
        k ++;
        n /= p;
    }
    return k;
}

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, p;

    printf("Введите систему счисления и целое число: ");
    if (scanf("%d%d", &p, &n) != 2)
    {
        printf("Ошибка ввода! Необходимо ввести 2 целых числа! Система счисления не меньше 2!\n");
        return 1;
    }

    printf("Количество p-ичных разрядов в числе %d: %d",n,discharge(p, n));
    return 0;
}

