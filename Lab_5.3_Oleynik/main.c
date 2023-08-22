/*  Лабораторная работа 5.3.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    int n_rub;

    printf("Введите сумму в рублях от 1 до 99: ");

    if (scanf("%d", &n_rub) != 1)
    {
        printf("Ошибка ввода! Требуется ввести целое число!\n");
        return 1;
    }

    if (n_rub > 99 || n_rub < 1)
    {
        printf("Значение суммы не попадает в заданный интервал!");
        return 1;
    }

    printf("Сумма в рублях словами: ");

    switch (n_rub / 10)
    {
        case 2:
            printf("двадцать ");
            break;
        case 3:
            printf("тридцать ");
            break;
        case 4:
            printf("сорок ");
            break;
        case 5:
            printf("пятьдесят ");
            break;
        case 6:
            printf("шестьдесят ");
            break;
        case 7:
            printf("семьдесят ");
            break;
        case 8:
            printf("восемьдесят ");
            break;
        case 9:
            printf("девяносто ");
            break;
    }

    switch (n_rub)
    {
        case 10:
            printf("десять ");
            break;
        case 11:
            printf("одиннадцать ");
            break;
        case 12:
            printf("двенадцать ");
            break;
        case 13:
            printf("тринадцать ");
            break;
        case 14:
            printf("четырнадцать ");
            break;
        case 15:
            printf("пятнадцать ");
            break;
        case 16:
            printf("шестнадцать ");
            break;
        case 17:
            printf("семнадцать ");
            break;
        case 18:
            printf("восемнадцать ");
            break;
        case 19:
            printf("девятнадцать ");
            break;
    }

    if (n_rub / 10 != 1)
    {
        switch (n_rub % 10)
        {
            case 1:
                printf("один ");
                break;
            case 2:
                printf("два ");
                break;
            case 3:
                printf("три ");
                break;
            case 4:
                printf("четыре ");
                break;
            case 5:
                printf("пять ");
                break;
            case 6:
                printf("шесть ");
                break;
            case 7:
                printf("семь ");
                break;
            case 8:
                printf("восемь ");
                break;
            case 9:
                printf("девять ");
                break;
        }
    }

    if (n_rub % 10 == 0 || n_rub % 10 > 4 || (n_rub > 10 && n_rub < 20))
        printf("рублей\n");
    else if (n_rub % 10 > 1 && n_rub % 10 < 5)
        printf("рубля\n");
    else
        printf("рубль\n");

    return 0;
}
