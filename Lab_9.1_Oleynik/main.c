/*  Лабораторная работа 9.1.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*функция, вычисляющая сумму (sum) и число (num) p-ичных цифр числа n*/
int sum_and_num (int p, int n, int *s)
{
    int sum = 0, num = 0;
    if (n == 0)
        num = 1;
    if (p < 2)
        return 0;
    n = abs(n);
    while (n > 0)
    {
        num ++;
        sum += n % p;
        n /= p;
    }
    if (s) *s = sum;
    return num;
}

int main()
{
    setlocale (LC_ALL, "Russian");

    int p, n, sum, num;

    printf("Введите систему счисления и число: ");
    if (scanf("%d%d", &p, &n) != 2)
    {
        printf("Ошибка ввода! Необходимо ввести 2 целых числа!\n");
        return 1;
    }

    num = sum_and_num(p, abs(n), &sum);

    printf("Сумма и число %d-ичных цифр числа %d: %d и %d\n", p, n, sum, num);
    return 0;
}

