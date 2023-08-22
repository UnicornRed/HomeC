/* ������������ ������ 13.23.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ��������� ����������� �������� (res_num_p) ���������� ������� fun (� ����������� � ������� param)
 * � ��������� a � b � ���������� �� num ����� ����� ������� midpoint � ��������� ����� ��������� �� �������� accuracy.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "partition_integral.h"

/* ������� ��������� ����������� �������� (res_num_p) ���������� ������� fun (� ����������� � ������� param)
 * � ��������� a � b � ���������� �� num ����� ����� ������� midpoint � ��������� ����� ��������� �� �������� accuracy.
 * ������� ���������� NaN, ���� ������� ������� ������ ����������� ��� ���������� ����� ��������� ������ 2.
 * ������� ���������� �����, ���� ������ ������ ���������.
 */
double partition_integral (double a, double b, double accuracy, double *param, fun_type fun, int_fun integral_fun)
{
    if (b < a)
        return 0.0 / 0.0;

    int num = 2;
    double res_num, res_num_p = midpoint(a, b, num, param, fun);

    do
    {
        res_num = res_num_p;
        num *= 2;
        res_num_p = integral_fun(a, b, num, param, fun);
    }
    while (fabs((res_num - res_num_p) / res_num_p) > accuracy);

    return res_num_p;
}
