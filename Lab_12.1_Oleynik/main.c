/* Лабораторная работа 12.1.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan_print_array.h"

#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    int m[ARRAY_SIZE] = {};
    size_t size_m, size_a;
    double a[ARRAY_SIZE] = {};

    printf("Введите размер целочисленного массива: ");

    if (scanf("%Iu", &size_m) != 1 || size_m > ARRAY_SIZE)
    {
        printf("Ошибка ввода! Необходимо ввести целое число меньше 1001!\n");
        return 1;
    }

    if ((int)size_m > 0)
    {
        printf ("Введите элементы массива: ");

        if(scan_array(size_m, m))
        {
            printf("Ошибка ввода! Необходимо ввести целое число!\n");
            return 1;
        }
    }

    if ((int)size_m > 0)
    {
        printf("Введённые элементы:\n");

        if (print_array(size_m, m))
        {
            printf("Ошибка вывода!\n");
            return 1;
        }
    }

    printf("Введите размер вещественного массива: ");

    if (scanf("%Iu", &size_a) != 1 || size_a > ARRAY_SIZE)
    {
        printf("Ошибка ввода! Необходимо ввести целое число меньше 1001!\n");
        return 1;
    }

    if ((int)size_a > 0)
    {
        printf ("Введите элементы массива: ");

        if(fscan_array(size_a, a))
        {
            printf("Ошибка ввода! Необходимо ввести вещественное число!\n");
            return 1;
        }
    }

    if ((int)size_a > 0)
    {
        printf("Введённые элементы:\n");

        if (fprint_array(size_a, a))
        {
            printf("Ошибка вывода!\n");
            return 1;
        }
    }
    return 0;
}
