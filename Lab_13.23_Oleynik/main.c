/* Лабораторная работа 13.23.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "integral.h"
#include "partition_integral.h"
#include "collection_of_functions.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    double a, b, accuracy, solve_int, coef[10];
    int num_coef, type_f;
    fun_type F;
    int_fun int_F = &midpoint;

    printf ("- Кубическая функция - 1\n- Квадратичная функция - 2\n- Синус - 3\n- Экспонента - 4\nВведите тип функции:\n");

    if (scanf ("%d", &type_f) != 1)
    {
        printf("Ошибка ввода! Необходимо ввести целое число!\n");
        return 1;
    }

    switch (type_f)
    {
        case 1:
            F = &cub_function;
            num_coef = 4;
            break;
        case 2:
            F = &squ_function;
            num_coef = 3;
            break;
        case 3:
            F = &sin_function;
            num_coef = 2;
            break;
        case 4:
            F = &exp_function;
            num_coef = 2;
            break;
    }

    printf ("Введите границы промежутка интегрирования и погрешность: \n");

    if (scanf ("%lf%lf%lf", &a, &b, &accuracy) != 3)
    {
        printf("Ошибка ввода! Необходимо ввести 3 вещественных числа!\n");
        return 1;
    }

    printf ("Введите коэффициенты уравнения: \n");

    for (int i = 0; i < num_coef; i ++)
    {
        if (scanf ("%lf", &coef[i]) != 1)
        {
            printf("Ошибка ввода! Необходимо ввести вещественное число!\n");
            return 1;
        }
    }

    solve_int = partition_integral (a, b, accuracy, coef, F, int_F);

    printf ("Метод средних прямоугольников. Определённый интеграл функции от %g до %g с точностью %g: %g\n", a, b, accuracy, solve_int);

    return 0;
}
