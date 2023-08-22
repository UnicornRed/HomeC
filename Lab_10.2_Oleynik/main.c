/*  Лабораторная работа 11.2.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "f_analysis.h"

int main()
{
    setlocale (LC_ALL, "Russian");

    double a, b, c, x_1, x_2;
    enum fun condition;

    printf("Введите коэффициенты квадратного уравнения: ");
    if (scanf("%lf%lf%lf", &a, &b, &c) != 3)
    {
        printf("Ошибка ввода! Необходимо ввести 3 вещественных числа!\n");
        return 1;
    }

    condition = f_analysis_f(a, b, c, &x_1, &x_2);

    switch (condition)
    {
        case FUN_TWO_R:
            printf("Уравнение имеет два вещественных корня: %.6f и %.6f.\n", x_1, x_2);
            break;
        case FUN_ONE_R:
            printf("Уравнение имеет кратный корень: %.6f.\n", x_1);
            break;
        case FUN_TWO_C:
            printf("Уравнение имеет два комплексных корня.\n");
            break;
        case FUN_LINE:
            printf("Уравнение линейного вида. Корень: %.6f.\n", x_1);
            break;
        case FUN_NOROOT:
            printf("Уравнение не имеет корней.\n");
            break;
        case FUN_INFROOT:
            printf("Корнями уравнения являются любые вещественные числа.\n");
            break;
        case FUN_NOCOEF:
            printf("Среди коэффициентов есть бесконечность или не-число.\n");
            break;
        default:
            printf("Error!\n");
            break;
    }
    return 0;
}
