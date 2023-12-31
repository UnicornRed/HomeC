#ifndef INTEGRAL_H_INCLUDED
#define INTEGRAL_H_INCLUDED

/* ��������� ���� ������ ��� �������� ������������� �������.
 */
typedef double (*fun_type) (double, double *);

/* ������� ��������� ����������� �������� (solve_int) ������� ������� ���������������
 * ���������� ������� fun (� ����������� � ������� param) � ��������� a � b � ���������� �� num �����.
 * ������� ���������� NaN, ���� ������� ������� ������ ����������� ��� ���������� ����� ��������� ������ 2.
 * ������� ���������� �����, ���� ������ ������ ���������.
 */
double midpoint (double a, double b, int num, double *param, fun_type fun);

#endif // INTEGRAL_H_INCLUDED
