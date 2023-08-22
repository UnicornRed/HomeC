/*  Лабораторная работа 8.3b.
 *  Автор: Олейник Михаил. Группа: 20.Б05-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*функция, которая выводит рамку из * высотой n, шириной m и толщиной d*/
void frame (int m, int n, int d)
{
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            if (i < d || i > n - d - 1 || j < d || j > m - d - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    setlocale (LC_ALL, "Russian");

    int m, n, d;

    printf("Введите длину, ширину и толщину рамки: ");
    if (scanf("%d%d%d", &m, &n, &d) != 3 || m < 0 || n < 0 || d < 0)
    {
        printf("Ошибка ввода! Необходимо ввести 3 натуральных числа!\n");
        return 1;
    }

    frame(m, n, d);
    return 0;
}
