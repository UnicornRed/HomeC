/* Лабораторная работа 12.2a.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "num_sign.h"

#define M_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    int m[M_SIZE] = {};
    size_t size_m;

    printf("Введите количество элементов массива: ");

    if(scanf("%Iu", &size_m) != 1 || size_m > M_SIZE)
    {
        printf("Ошибка ввода! Необходимо ввести целое число меньше 1001!\n");
        return 1;
    }

    printf("Введите элементы массива: ");

    for (int i = 0; i < size_m; i ++)
    {
        if(scanf("%d", &m[i]) != 1)
        {
            printf("Ошибка ввода! Необходимо ввести целое число!\n");
            return 1;
        }
    }

    int num = num_sign(size_m, m);
    if (num != -1)
        printf("Элементы массива меняют знак %d раз.\n", num);
    else
    {
        printf("Ошибка!\n");
        return 1;
    }
    return 0;
}
