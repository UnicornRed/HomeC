/* ������������ ������ 13.23.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "integral.h"
#include "partition_integral.h"
#include "collection_of_functions.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    double a, b, accuracy, solve_int, coef[10];
    int num_coef, type_f;
    fun_type F;
    int_fun int_F = &midpoint;

    printf ("- ���������� ������� - 1\n- ������������ ������� - 2\n- ����� - 3\n- ���������� - 4\n������� ��� �������:\n");

    if (scanf ("%d", &type_f) != 1)
    {
        printf("������ �����! ���������� ������ ����� �����!\n");
        return 1;
    }

    switch (type_f)
    {
        case 1:
            F = &cub_function;
            num_coef = 4;
            break;
        case 2:
            F = &squ_function;
            num_coef = 3;
            break;
        case 3:
            F = &sin_function;
            num_coef = 2;
            break;
        case 4:
            F = &exp_function;
            num_coef = 2;
            break;
    }

    printf ("������� ������� ���������� �������������� � �����������: \n");

    if (scanf ("%lf%lf%lf", &a, &b, &accuracy) != 3)
    {
        printf("������ �����! ���������� ������ 3 ������������ �����!\n");
        return 1;
    }

    printf ("������� ������������ ���������: \n");

    for (int i = 0; i < num_coef; i ++)
    {
        if (scanf ("%lf", &coef[i]) != 1)
        {
            printf("������ �����! ���������� ������ ������������ �����!\n");
            return 1;
        }
    }

    solve_int = partition_integral (a, b, accuracy, coef, F, int_F);

    printf ("����� ������� ���������������. ����������� �������� ������� �� %g �� %g � ��������� %g: %g\n", a, b, accuracy, solve_int);

    return 0;
}
