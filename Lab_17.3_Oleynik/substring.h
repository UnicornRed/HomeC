#ifndef SUBSTRING_H_INCLUDED
#define SUBSTRING_H_INCLUDED

/* ������� �������� ��������� dst � ������� � pos � ������� num �� ������ str ������������� ������� size_string.
 * ������� ���������� 1, ���� ������ ��� ��������� �� ��������� �� ���� �������� ��� �� ���� � ������ �������� � ������� �����.
 * ������� ���������� 0 � ��������� �������.
 */
int substring (const char *str, int pos, int num, char *dst, size_t size_string);

#endif // SUBSTRING_H_INCLUDED
