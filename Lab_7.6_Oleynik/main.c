/*  ������������ ������ 7.6.
 *  �������: y = (x^2-p^2)/(x-p)-p.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    double a, b, h, y, p;

    printf("������� ������� ����������, ��� � ��������: ");
    if (scanf("%lf%lf%lf%lf", &a, &b, &h, &p) != 4)
    {
        printf("������ �����! ���������� ������ 4 ������������ �����!\n");
        return 1;
    }

    printf("\n---------------------------------------------------------\n"
           "|              X            |              Y            |\n"
           "---------------------------------------------------------\n");

    for (double i = a; i <= b; i += h)
    {
        int mark = 1;
        y = (i * i - p * p) / (i - p) - p;
        if (fabs(y - i) > 1e-17)
            mark = 0;
        printf("| %025.16f | %025.16f |%d\n", i, y, mark);
    }

    printf("---------------------------------------------------------\n");
    return 0;
}

