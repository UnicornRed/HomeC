/* Лабораторная работа 15.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "array_monotone.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    int length_m;
    size_t size_a;
    double *a;

    printf ("Введите размер вещественного массива: ");

    if (scanf("%Iu", &size_a) != 1)
    {
        printf("Ошибка ввода! Необходимо ввести целое число меньше 1001!\n");
        return 1;
    }

    a = malloc(size_a * sizeof(double));

    if (!a)
    {
        printf("Ошибка выделения памяти!");
        return 1;
    }

    printf ("Введите элементы массива: ");

    for (int i = 0; i < size_a; i ++)
    {
        if (scanf("%lf", &a[i]) != 1)
        {
            printf("Ошибка ввода! Необходимо ввести вещественное число!\n");
            free(a);
            return 1;
        }
    }

    length_m = array_monotone(size_a, a);

    if (length_m == -1)
    {
        printf ("Ошибка вычисления длины монотонной последовательности.\n");
        free(a);
        return 1;
    }
    else
        printf ("Длина наибольшего монотонного промежутка в массиве: %d\n", length_m);
    free(a);
    return 0;
}
