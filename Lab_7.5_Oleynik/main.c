/*  ������������ ������ 7.5.
 *  �������: y = x*sin(2x).
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    double a, b, h, y;

    printf("������� ������� ���������� � ���: ");
    if (scanf("%lf%lf%lf", &a, &b, &h) != 3)
    {
        printf("������ �����! ���������� ������ 3 ������������ �����!\n");
        return 1;
    }

    printf("\n---------------------\n"
           "|    X    |    Y    |\n"
           "---------------------\n");

    for (double i = a; i <= b; i += h)
    {
        y = i * sin(2 * i);
        printf("| %07.3f | %07.3f |\n", i, y);
    }

    printf("---------------------\n");
    return 0;
}
