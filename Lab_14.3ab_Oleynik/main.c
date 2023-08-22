/* Лабораторная работа 14.3ab.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan_print_array.h"
#include "comparison_fun.h"
#include "binary_module.h"


#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    size_t size_a;
    double a[ARRAY_SIZE] = {}, mean;

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

    printf("Введите значение, которое необходимо найти в массиве: ");

    if (scanf("%lf", &mean) != 1)
    {
        printf("Ошибка ввода! Необходимо ввести вещественное число!\n");
        return 1;
    }

    com_fun F = double_comparison;
    const void *res_mean = bin_search(size_a, sizeof(double), &mean, a, F);

    if (res_mean)
        printf ("Индекс найденного элемента: %d\n", (int)(res_mean - (void*)a) / (int)sizeof(double*));
    else
        printf ("Элемент не найден!\n");

    size_t res_id = bin_place(size_a, sizeof(double), &mean, a, F);

    if ((int)res_id != -1)
        printf ("Индекс элемента, на который следует вставить искомый: %Iu\n", res_id);
    else
        printf ("Ошибка!\n");

    return 0;
}
