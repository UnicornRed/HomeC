#ifndef SCAN_PRINT_ARRAY_H_INCLUDED
#define SCAN_PRINT_ARRAY_H_INCLUDED

/* ������� ������������ ���� �������������� ������� m ������� size_m.
 * ������� ���������� 1, ���� �������� ����� �� ������������� ���� ������ �������, ������ �� �������.
 * ������� ���������� 0, ���� �������� ������� ���� ��������� �������.
 */
int scan_array (size_t size_m, int *m);

/* ������� ������������ ����� �������������� ������� m ������� size_m.
 * ������� ���������� 1, ���� ������ �� ��� �������.
 * ������� ���������� 0, ���� �������� ������� ���� ��������� ��������.
 */
int print_array (size_t size_m, const int *m);

/* ������� ������������ ���� ������������� ������� a ������� size_a.
 * ������� ���������� 1, ���� �������� ����� �� ������������� ���� ������ �������, ������ �� �������.
 * ������� ���������� 0, ���� �������� ������� ���� ��������� �������.
 */
int fscan_array (size_t size_a, double *a);

/* ������� ������������ ����� ������������� ������� a ������� size_a.
 * ������� ���������� 1, ���� ������ �� ��� �������.
 * ������� ���������� 0, ���� �������� ������� ���� ��������� ��������.
 */
int fprint_array (size_t size_a, const double *a);

#endif // SCAN_PRINT_ARRAY_H_INCLUDED
