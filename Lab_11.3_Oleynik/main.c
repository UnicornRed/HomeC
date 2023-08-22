/*  Лабораторная работа 11.3.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "print_num.h"

int main()
{
    setlocale (LC_ALL, "Russian");

    int p, n;

    printf ("Введите систему счисления и число: ");

    while (scanf ("%d%d", &p, &n) != 2)
    {
        printf ("Ошибка ввода! Необходимо ввести 2 целых числа!");
        return 1;
    }

    printf ("Число %d в системе счисления %d в прямом порядке: ", n, p);
    print_num(p, n);
    printf ("\nЧисло %d в системе счисления %d в обратном порядке: ", n, p);
    print_num_r(p, n);
    printf ("\n");
    return 0;
}
