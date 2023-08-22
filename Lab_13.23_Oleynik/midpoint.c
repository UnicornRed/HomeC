/* ������������ ������ 13.23.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ��������� ����������� �������� (solve_int) ������� ������� ���������������
 * ���������� ������� fun (� ����������� � ������� param) � ��������� a � b � ���������� �� num �����.
 */

#include <stdio.h>
#include <stdlib.h>
#include "integral.h"

/* ������� ��������� ����������� �������� (solve_int) ������� ������� ���������������
 * ���������� ������� fun (� ����������� � ������� param) � ��������� a � b � ���������� �� num �����.
 * ������� ���������� NaN, ���� ������� ������� ������ ����������� ��� ���������� ����� ��������� ������ 2.
 * ������� ���������� �����, ���� ������ ������ ���������.
 */
double midpoint (double a, double b, int num, double *param, fun_type fun)
{
    if (b < a || num < 2)
        return 0.0 / 0.0;

    double solve_int = 0, step = (b - a) / (num - 1);

    for (int i = 0; i < num - 1; i ++)
    {
        double a_mid = a + step * (i + 0.5);
        solve_int += fun(a_mid, param) * step;
    }

    return solve_int;
}
