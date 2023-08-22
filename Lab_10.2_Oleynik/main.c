/*  ������������ ������ 11.2.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "f_analysis.h"

int main()
{
    setlocale (LC_ALL, "Russian");

    double a, b, c, x_1, x_2;
    enum fun condition;

    printf("������� ������������ ����������� ���������: ");
    if (scanf("%lf%lf%lf", &a, &b, &c) != 3)
    {
        printf("������ �����! ���������� ������ 3 ������������ �����!\n");
        return 1;
    }

    condition = f_analysis_f(a, b, c, &x_1, &x_2);

    switch (condition)
    {
        case FUN_TWO_R:
            printf("��������� ����� ��� ������������ �����: %.6f � %.6f.\n", x_1, x_2);
            break;
        case FUN_ONE_R:
            printf("��������� ����� ������� ������: %.6f.\n", x_1);
            break;
        case FUN_TWO_C:
            printf("��������� ����� ��� ����������� �����.\n");
            break;
        case FUN_LINE:
            printf("��������� ��������� ����. ������: %.6f.\n", x_1);
            break;
        case FUN_NOROOT:
            printf("��������� �� ����� ������.\n");
            break;
        case FUN_INFROOT:
            printf("������� ��������� �������� ����� ������������ �����.\n");
            break;
        case FUN_NOCOEF:
            printf("����� ������������� ���� ������������� ��� ��-�����.\n");
            break;
        default:
            printf("Error!\n");
            break;
    }
    return 0;
}
