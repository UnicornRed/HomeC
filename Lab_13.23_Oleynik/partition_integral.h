#ifndef PARTITION_INTEGRAL_H_INCLUDED
#define PARTITION_INTEGRAL_H_INCLUDED

#include "integral.h"

/* ��������� ���� ������ ��� �������� ������� ��������������.
 */
typedef double (*int_fun) (double, double, int, double *, fun_type);

/* ������� ��������� ����������� �������� (res_num_p) ���������� ������� fun (� ����������� � ������� param)
 * � ��������� a � b � ���������� �� num ����� ����� ������� integral_fun � ��������� ����� ��������� �� �������� accuracy.
 * ������� ���������� NaN, ���� ������� ������� ������ ����������� ��� ���������� ����� ��������� ������ 2.
 * ������� ���������� �����, ���� ������ ������ ���������.
 */
double partition_integral (double a, double b, double accuracy, double *param, fun_type fun, int_fun integral_fun);

#endif // PARTITION_INTEGRAL_H_INCLUDED
