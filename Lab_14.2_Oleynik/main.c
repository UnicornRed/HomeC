/* Лабораторная работа 14.2.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan_print_array.h"
#include "search_misses.h"

#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    size_t size_a;
    double a[ARRAY_SIZE] = {}, miss_array[ARRAY_SIZE] = {};

    printf("Введите размер вещественного массива: ");

    if (scanf("%Iu", &size_a) != 1 || size_a > ARRAY_SIZE)
    {
        printf("Ошибка ввода! Необходимо ввести целое число меньше 1001!\n");
        return 1;
    }

    printf ("Введите элементы массива: ");

    if(fscan_array(size_a, a))
    {
        printf("Ошибка ввода! Необходимо ввести вещественное число!\n");
        return 1;
    }

    printf("Введённые элементы:\n");

    if (fprint_array(size_a, a))
    {
        printf("Ошибка вывода!\n");
        return 1;
    }

    size_t num_miss = all_miss(size_a, a, miss_array);

    if (!num_miss)
        printf("Промахов нет.\n");
    else if ((int)num_miss != -1)
    {
        printf("Промахи:\n");
        fprint_array(num_miss, miss_array);
    }
    else
    {
        printf("Ошибка!\n");
        return 1;
    }

    return 0;
}
