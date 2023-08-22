#ifndef MAX_LINE_ARRAY_H_INCLUDED
#define MAX_LINE_ARRAY_H_INCLUDED

#define ARRAY_SIZE 100

/* ������� ���������� ����� ������ ������� a ������� size_a_h �� size_a_w � ���������� ������ ���������.
 * ������� ���������� 0, ���� ������ ��� ������� �������.
 * ������� ���������� ����� ������ (������� � 1), ���� ���������� ������ ���������.
 */
int max_line_array (size_t size_a_h, size_t size_a_w, const double a[][ARRAY_SIZE]);

#endif // MAX_LINE_ARRAY_H_INCLUDED
