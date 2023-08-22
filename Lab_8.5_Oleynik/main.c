/*  Лабораторная работа 8.5.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*функция, вычисляющая корень числа n*/
double approxsqrt (double a)
{
    double sq = a, psq;
    const double e = 1e-7 * a;
    if (a < 0)
        return 0.0 / 0.0;
    if (a == 0)
        return 0;
    if (a == 1.0 / 0.0)
        return 1.0 / 0.0;
    do
    {
        psq = sq;
        sq = 0.5 * (psq + a / psq);
    }
    while (fabs((sq - psq) / sq) > e);
    return sq;
}

int main()
{
    setlocale (LC_ALL, "Russian");

    double a, sqrt;

    printf("Введите вещественное число: ");
    if (scanf("%lf", &a) != 1)
    {
        printf("Ошибка ввода! Необходимо ввести вещественное число!\n");
        return 1;
    }

    sqrt = approxsqrt(a);

    if (sqrt == 1.0 / 0.0)
        printf("Корень числа INF: INF\n");
    else if (sqrt != sqrt)
        printf("Корень числа %g: NaN\n",a);
    else
        printf("Корень числа %g: %.6f\n",a,approxsqrt(a));
    return 0;
}
