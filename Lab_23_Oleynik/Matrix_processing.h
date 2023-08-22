#ifndef MATRIX_PROCESSING_H_INCLUDED
#define MATRIX_PROCESSING_H_INCLUDED

/* ������� ������� �������� ������� ����������� ������� matrix_a.
 * ������� ���������� NULL, ���� ������� �� ���� ��������, ��� �� ���������,
 * ��������������� ������� matrix_b �� �������� ��� ������������ ������� ����� 0.
 * ������� ���������� ��������� �� ������� matrix_rev � ��������� �������.
 */
matrix * matrix_reverse (const matrix *matrix_a);

/* ������� ��������� ��������� ���������� �� ������� matrix_a � ������������ e.
 * ������� ���������� NULL, ���� ������� �� ���� ��������, ��� �� ���������, ���������������
 * ������� matrix_b, matrix_exp_sol ��� matrix_c �� ������� ��� �������� ������ � ��������
 * matrix_sum, matrix_assign, matrix_multi_scalar ��� matrix_norm.
 * ������� ���������� ��������� �� ������� matrix_exp_sol � ��������� �������.
 */
matrix * matrix_exp (const matrix *matrix_a, const double e);

/* ������� ��������� ������� matrix_sol �� ������� ��� matrix_a � ������������ e.
 * ������� ���������� -1, ���� ������� �� ���� ��������, ��������� ������ � ������� matrix_norm ��� ���������� �����
 * � ���������� �������� ����� 1 ������� matrix_a ��� ���������� ����� ������ matrix_a � matrix_sol �� ���������.
 * ������� ���������� 1, ���� ������� matrix_sol �� �������� ��������.
 * ������� ���������� 0 � ��������� �������.
 */
int matrix_gauss_test (const matrix *matrix_a, const matrix *matrix_sol, const double e);

/* ������� ������ ���, �������� �������� matrix_a.
 * ������� ���������� NULL, ���� ������� �� ���� ��������, ��������������� ������� matrix_b �� �������,
 * ����������� ���������� ������� ��� ������� ���.
 * ������� ���������� ��������� �� ������� matrix_sol � ��������� �������.
 */
matrix * matrix_gauss_solution (const matrix *matrix_a);

#endif // MATRIX_PROCESSING_H_INCLUDED
