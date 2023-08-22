/*  Лабораторная работа 7.3g.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    const double e = 1e-5;
    double numb, sum = 0, aver;
    int vol = 0;

    printf("Введите последовательность положительных вещественных чисел, оканчивающихся 0:\n");

    while (1)
    {
        if (scanf("%lf", &numb) != 1 || numb < 0.0)
        {
            printf("Ошибка ввода! Требуется ввести положительное число или ноль для завершения последовательности!\n");
            return 1;
        }
        if (fabs(numb) < e)
            break;
        sum += numb;
        ++ vol;
    }

    aver = sum / vol;

    printf("Среднее арифметическое последовательности: %g", aver);
    return 0;
}
