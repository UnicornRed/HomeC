#ifndef CHECK_TEST_H_INCLUDED
#define CHECK_TEST_H_INCLUDED

/* �������� ����������� �������.
 */
typedef int (*check_fun) (const char *, int, int, char *, size_t);

/* ������� ��������� ������� F �� ������, �������� ��������� ������ � ������� ��������� �� ����� input_test.txt.
 * ������� ���������� 2, ���� �� ������� F ��� ������� �������� �����.
 * ������� ���������� 1, ���� ����� �� ���� �������, ��������� ������ � ������� F ��� str_comp ��� ������ � ������� ����� ��� ������ ��� ������� ���������.
 * ������� ���������� 0 � ��������� �������.
 */
int check_test (check_fun F);

#endif // CHECK_TEST_H_INCLUDED