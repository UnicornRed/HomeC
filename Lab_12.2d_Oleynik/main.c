/* Лабораторная работа 12.2d.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "array_monotone.h"

#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    int length_m;
    size_t size_a;
    double a[ARRAY_SIZE] = {};

    printf ("Введите размер вещественного массива: ");

    if (scanf("%Iu", &size_a) != 1 || size_a > ARRAY_SIZE)
    {
        printf("Ошибка ввода! Необходимо ввести целое число меньше 1001!\n");
        return 1;
    }

    printf ("Введите элементы массива: ");

    for (int i = 0; i < size_a; i ++)
    {
        if (scanf("%lf", &a[i]) != 1)
        {
            printf("Ошибка ввода! Необходимо ввести вещественное число!\n");
            return 1;
        }
    }

    length_m = array_monotone(size_a, a);

    if (length_m == -1)
    {
        printf ("Ошибка вычисления длины монотонной последовательности.\n");
        return 1;
    }
    else
        printf ("Длина наибольшего монотонного промежутка в массиве: %d\n", length_m);
    return 0;
}
