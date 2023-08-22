/*  Лабораторная работа 7.1a.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    int p, sum = 0, numb;

    printf("Введите систему счисления и положительное число: ");
    if (scanf("%d%d", &p, &numb) != 2 || numb < 1 || p < 2)
    {
        printf("Ошибка ввода! Требуется ввести 2 целых положительных числа! Система счисления не может быть меньше 2.\n");
        return 1;
    }

    while (numb > 0)
    {
        sum += numb % p;
        numb /= p;
    }

    printf("Сумма цифр в %d системе счисления: %d", p, sum);
    return 0;
}
