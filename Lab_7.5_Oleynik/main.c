/*  Лабораторная работа 7.5.
 *  Функция: y = x*sin(2x).
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    double a, b, h, y;

    printf("Введите границы промежутка и шаг: ");
    if (scanf("%lf%lf%lf", &a, &b, &h) != 3)
    {
        printf("Ошибка ввода! Необходимо ввести 3 вещественных числа!\n");
        return 1;
    }

    printf("\n---------------------\n"
           "|    X    |    Y    |\n"
           "---------------------\n");

    for (double i = a; i <= b; i += h)
    {
        y = i * sin(2 * i);
        printf("| %07.3f | %07.3f |\n", i, y);
    }

    printf("---------------------\n");
    return 0;
}
