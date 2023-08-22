/*  Лабораторная работа 5.8c.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    double a, x, y;
    const double acc = 1e-5;

    printf("Введите a, x и y: ");
    if (scanf("%lf%lf%lf", &a, &x, &y) != 3)
    {
        printf("Ошибка ввода! Требуется ввести 3 вещественных числа!\n");
        return 1;
    }

    if (!((x > acc) && (y > acc)) && x * x + y * y  - a * a >= -acc * acc && x - a <= acc && x + a >= -acc && y - a <= acc && y + a >= -acc)
        printf("Точка входит в область");
    else
        printf("Точка не входит в область");
    return 0;
}
