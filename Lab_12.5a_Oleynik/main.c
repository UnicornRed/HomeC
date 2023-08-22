/* Лабораторная работа 12.5a.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "max_line_array.h"

#define ARRAY_SIZE 100

int main()
{
    setlocale(LC_ALL, "Russian");

    double a[ARRAY_SIZE][ARRAY_SIZE];
    size_t size_a_w, size_a_h;
    int max_line;

    printf ("Введите размеры целочисленного массива: ");

    if (scanf("%Iu%Iu", &size_a_h, &size_a_w) != 2 || size_a_h > ARRAY_SIZE || size_a_w > ARRAY_SIZE)
    {
        printf("Ошибка ввода! Необходимо ввести целые числа меньше 100!\n");
        return 1;
    }

    printf ("Введите элементы массива: \n");

    for (int i = 0; i < size_a_h; i ++)
    {
        for (int j = 0; j < size_a_w; j ++)
            if (scanf("%lf", &a[i][j]) != 1)
            {
                printf("Ошибка ввода! Необходимо ввести вещественное число!\n");
                return 1;
            }
    }

    max_line = max_line_array(size_a_h, size_a_w, a);

    if (max_line > 0)
        printf ("Номер строки двухмерного массива с наибольшей суммой элементов: %d\n", max_line);
    else
    {
        printf ("Ошибка!\n");
        return 1;
    }
    return 0;
}
