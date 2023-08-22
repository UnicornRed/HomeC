/*  Лабораторная работа 11.1cd.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "nod.h"

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, m, d, it_d;

    printf ("Введите 2 числа: ");

    if (scanf ("%d%d", &n, &m) != 2)
    {
        printf ("Ошибка ввода! Необходимо ввести 2 целых числа!\n");
        return 1;
    }

    d = nod(n, m);
    it_d = it_nod(n, m);

    printf ("Рекурсивно. НОД чисел %d и %d равен: %d\n", n, m, d);
    printf ("Итеративно. НОД чисел %d и %d равен: %d\n", n, m, it_d);
    printf ("НОК чисел %d и %d равен: %d\n", n, m, m / d * n);
    return 0;
}
