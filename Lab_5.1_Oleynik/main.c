/*  Лабораторная работа 5.1.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    int n_year, n_day;

    printf("Введите номер года: ");
    if (scanf("%d", &n_year) != 1 || n_year < 1)
    {
        printf("Ошибка ввода! Необходимо ввести целое положительное число!\n");
        return 1;
    }

    if (n_year % 4 == 0 && n_year % 100 !=0 || n_year % 400 == 0)
        n_day = 366;
    else
        n_day = 365;

    printf("Количество дней в %d году: %d", n_year, n_day);
    return 0;
}
