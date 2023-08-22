/* Лабораторная работа 12.3b.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "del_norepeat.h"

#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    size_t size_m;
    double m[ARRAY_SIZE] = {};
    int size_del;

    printf ("Введите размер вещественного массива: ");

    if (scanf("%Iu", &size_m) != 1 || size_m > ARRAY_SIZE)
    {
        printf("Ошибка ввода! Необходимо ввести целое число меньше 1001!\n");
        return 1;
    }

    printf ("Введите элементы массива: ");

    for (int i = 0; i < size_m; i ++)
    {
        if (scanf("%lf", &m[i]) != 1)
        {
            printf("Ошибка ввода! Необходимо ввести вещественное число!\n");
            return 1;
        }
    }

    size_del = del_norepeat(size_m, m);

    if (size_del > -1)
    {
        printf ("Изменённый массив:\n");

        for (int i = 0; i < size_m; i ++)
            printf ("%f\n", m[i]);
    }
    else
    {
        printf("Ошибка!\n");
        return 1;
    }
    return 0;
}
