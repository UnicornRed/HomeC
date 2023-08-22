/* Лабораторная работа 13.1c.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "integral.h"
#include "cubic_function.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    double a, b, solve_int, coef[10];
    int num_point;

    fun_type F = &cubic_function;

    printf ("Введите границы промежутка интегрирования и количество точек разбиения: \n");

    scanf ("%lf%lf%d", &a, &b, &num_point);

    printf ("Введите коэффициенты кубического уравнения: \n");

    for (int i = 0; i < 4; i ++)
        scanf ("%lf", &coef[i]);

    solve_int = midpoint (a, b, num_point, coef, F);

    printf ("Метод средних прямоугольников. Определённый интеграл функции от %g до %g: %g\n", a, b, solve_int);

    solve_int = trapez (a, b, num_point, coef, F);

    printf ("Метод трапеций. Определённый интеграл функции от %g до %g: %g\n", a, b, solve_int);

    return 0;
}
