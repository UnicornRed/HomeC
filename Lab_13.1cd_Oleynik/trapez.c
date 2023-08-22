/* ������������ ������ 13.1c.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ��������� ����������� �������� (solve_int) ������� ������� ���������������
 * ���������� ������� fun (� ����������� � ������� param) � ��������� a � b � ���������� �� num �����.
 */

#include <stdio.h>
#include <stdlib.h>
#include "integral.h"

/* ������� ��������� ����������� �������� (solve_int) ������� ��������
 * ���������� ������� fun (� ����������� � ������� param) � ��������� a � b � ���������� �� num �����.
 * ������� ���������� NaN, ���� ������� ������� ������ ����������� ��� ���������� ����� ��������� ������ 2.
 * ������� ���������� �����, ���� ������ ������ ���������.
 */
double trapez (double a, double b, int num, double *param, fun_type fun)
{
    if (b < a || num < 2)
        return 0.0 / 0.0;

    double solve_int, step = (b - a) / num;

    for (int i = 0; i < num - 2; i ++)
    {
        solve_int += (fun(a, param) + fun(a + step, param)) / 2 * step;
        a += step;
    }

    solve_int += (fun(a, param) + fun(b, param)) / 2 * (b - a);

    return solve_int;
}
