/*  Лабораторная работа 3.2.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    int sec_all, sec_1, min_1;

    printf("Введите количество секунд, "
           "прошедших с начала суток: ");
    if (scanf("%d", &sec_all) != 1 || sec_all < 0)
    {
        printf("Ошибка ввода! Необходимо ввести целое положительное число!\n");
        return 1;
    }

    min_1 = sec_all / 60 % 60;
    sec_1 = sec_all % 60;

    printf("Количество минут и секунд, "
           "прошедших с начала последнего часа: %02d:%02d", min_1, sec_1);
    return 0;
}
