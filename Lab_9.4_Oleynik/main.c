/*  ������������ ������ 9.4.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*��� ������, ������������ ��������� ����������� ���������*/
enum fun {FUN_TWO_R, FUN_ONE_R, FUN_TWO_C, FUN_LINE, FUN_NOROOT, FUN_INFROOT, FUN_NOCOEF};

/*�������, ������������� ���������� ��������� �� ������������� a, b � c � �� ����������� ����������� ��� ����� (x1 � x2)*/
enum fun f_analysis (double a, double b, double c, double *x1, double *x2)
{
    if (a != a || b != b || c != c || fabs(a) == 1.0 / 0.0 || fabs(b) == 1.0 / 0.0 || fabs(c) == 1.0 / 0.0)
        return FUN_NOCOEF;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                return FUN_INFROOT;
            else
                return FUN_NOROOT;
        }
        else
        {
            if (x1) *x1 = -c / b;
            return FUN_LINE;
        }
    }
    else
    {
        double dis = b * b - 4 * a * c;
        if (dis < 0)
            return FUN_TWO_C;
        else if (dis == 0)
        {
            if (x1) *x1 = -b / (2 * a);
            return FUN_ONE_R;
        }
        else
        {
            double sqrtdis = sqrt(dis);
            if (x1) *x1 = (-b - sqrtdis) / (2 * a);
            if (x1) *x2 = (-b + sqrtdis) / (2 * a);
            return FUN_TWO_R;
        }
    }
}

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

    condition = f_analysis(a, b, c, &x_1, &x_2);

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

