/*  ������������ ������ 5.8c.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    double a, x, y;
    const double acc = 1e-5;

    printf("������� a, x � y: ");
    if (scanf("%lf%lf%lf", &a, &x, &y) != 3)
    {
        printf("������ �����! ��������� ������ 3 ������������ �����!\n");
        return 1;
    }

    if (!((x > acc) && (y > acc)) && x * x + y * y  - a * a >= -acc * acc && x - a <= acc && x + a >= -acc && y - a <= acc && y + a >= -acc)
        printf("����� ������ � �������");
    else
        printf("����� �� ������ � �������");
    return 0;
}
