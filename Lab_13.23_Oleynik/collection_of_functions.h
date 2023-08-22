#ifndef COLLECTION_OF_FUNCTIONS_H_INCLUDED
#define COLLECTION_OF_FUNCTIONS_H_INCLUDED

/* ������� ��������� �������� ���������� ������� y = a * x ^ 3 + b * x ^ 2 + c * x + d
 * � ����������� ����������� ����� ������ param � �������� ����� x.
 * ������� ���������� ����� - �������� � �����.
 */
double cub_function (double x, double *param);

/* ������� ��������� �������� ������������ ������� y = a * x ^ 2 + b * x + c
 * � ����������� ����������� ����� ������ param � �������� ����� x.
 * ������� ���������� ����� - �������� � �����.
 */
double squ_function (double x, double *param);

/* ������� ��������� �������� ������� ������ y = a * sin(b * x)
 * � ����������� ����������� ����� ������ param � �������� ����� x.
 * ������� ���������� ����� - �������� � �����.
 */
double sin_function (double x, double *param);

/* ������� ��������� �������� ���������������� ������� y = a * e ^ (b * x)
 * � ����������� ����������� ����� ������ param � �������� ����� x.
 * ������� ���������� ����� - �������� � �����.
 */
double exp_function (double x, double *param);

#endif // COLLECTION_OF_FUNCTIONS_H_INCLUDED
