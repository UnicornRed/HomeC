#ifndef SEARCH_MISSES_H_INCLUDED
#define SEARCH_MISSES_H_INCLUDED

/* ������� ��������� ������� �������������� ��������� ������� a ������� size_a.
 * ������� ���������� NaN, ���� ������ �� ��� �������.
 * ������� ���������� �������� mean, ���� ������ ������� ���������.
 */
double arithmetic_mean (size_t size_a, const double *a);

/* ������� ��������� ����������� ������ ������������������� ���������� ��������� ������� a ������� size_a.
 * ������� ���������� NaN, ���� ������ �� ��� �������.
 * ������� ���������� �������� sqrt(mean), ���� ������ ������� ���������.
 */
double unbiased_root_mean_square (size_t size_a, const double *a);

/* ������� ������� ������ ��������� �������� miss, �������� �������� ����������� �� ����������� �������� mean
 * �� ��������� �������� variance, � ������ ������� a ������� size_a_tail.
 * ������� ���������� NULL, ���� ������ �� ��� ������� ��� ����� ������� �� ��� ���������.
 * ������� ���������� ��������� miss, ���� ������ ������� ��������� � ����� ������� ��� ���������.
 */
const double* search_miss (size_t size_a_tail, double variance, double mean, const double *a);

/* ������� ������� ��� ������� ��������� � ������� a ������� size_a � ���������� �� � ������ miss_array.
 * ������� ���������� -1, ���� ������ a ��� ������ miss_array �� ���� ��������.
 * ������� ���������� �������� counter, ���� ������� ���� �������� ���������.
 */
size_t all_miss (size_t size_a, const double *a, double *miss_array);

#endif // SEARCH_MISSES_H_INCLUDED
