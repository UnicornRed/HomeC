/* Лабораторная работа 14.1abd.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan_print_array.h"
#include "checking_monotony.h"
#include "del_even_noteven_array.h"

#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    int m[ARRAY_SIZE] = {}, bool_check = 0;
    size_t size_m, size_a;
    double a[ARRAY_SIZE] = {};

    printf("Введите размер целочисленного массива: ");

    if (scanf("%Iu", &size_m) != 1 || size_m > ARRAY_SIZE)
    {
        printf("Ошибка ввода! Необходимо ввести целое число меньше 1001!\n");
        return 1;
    }

    printf ("Введите элементы массива: ");

    if(scan_array(size_m, m))
    {
        printf("Ошибка ввода! Необходимо ввести целое число!\n");
        return 1;
    }

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

    bool_check = checking_monotony_down(size_a, a);

    if (bool_check)
        printf ("Массив упорядочен по убыванию.\n");
    else if (!bool_check)
        printf ("Массив не упорядочен по убыванию.\n");
    else
    {
        printf ("Ошибка передачи массива!\n");
        return 1;
    }

    bool_check = checking_monotony_up(size_a, a);

    if (bool_check)
        printf ("Массив упорядочен по возрастанию.\n");
    else if (!bool_check)
        printf ("Массив не упорядочен по возрастанию.\n");
    else
    {
        printf ("Ошибка передачи массива!\n");
        return 1;
    }

    int choice = 0, size_del;

    printf ("Выберете, какие элементы целочисленного массива хотите исключить: 1 - чётные, 2 - нечётные:\n");

    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        printf ("Ошибка ввода! Необходимо ввести 1 или 2!\n");
        return 1;
    }

    if (choice == 1)
        size_del = del_even_array(size_m, m);
    else
        size_del = del_noteven_array(size_m, m);

    if (size_del > -1)
    {
        printf("Изменённый массив:\n");

        if (print_array(size_del, m))
        {
            printf("Ошибка вывода!\n");
            return 1;
        }
    }
    else
    {
        printf("Ошибка!\n");
        return 1;
    }
    return 0;
}
