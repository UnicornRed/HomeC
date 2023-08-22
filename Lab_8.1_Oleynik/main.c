/*  Лабораторная работа 8.1.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*функция, вычисляющая цифровой корень через суммирование цифр*/
int dr (int n, int p)
{
    int sum = 0;
    while (n >= p)
    {
        sum = 0;
        while (n > 0)
        {
            sum += n % p;
            n /= p;
        }
        n = sum;
    }
    return n;
}

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, p;

    printf("Введите систему счисления и число: ");
    if (scanf("%d%d", &p, &n) != 2 || p < 2 || n < 1)
    {
        printf("Ошибка ввода! Необходимо ввести 2 натуральных числа! Система счисления не меньше 2!\n");
        return 1;
    }

    printf("Цифровой корень числа %d в системе счисления %d равен: %d\n", n, p, dr(n, p));
    return 0;
}
