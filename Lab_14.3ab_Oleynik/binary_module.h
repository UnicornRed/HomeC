#ifndef BINARY_MODULE_H_INCLUDED
#define BINARY_MODULE_H_INCLUDED

/* ��������� ���� ������ ��� �������� ������� ��������� ���������.
 */
typedef int (*com_fun) (const void *, const void *);

/* ������� ������� ������� �� ��������� mean � ������� a ������� size_t.
 * ��������� ����� ������� com_F. ������ ���� s_type.
 * ������� ���������� NULL, ���� ������ �� ��� ������� ��� ������� �� ������.
 * ������� ���������� ��������� �� �������, ���� �� ������.
 */
const void* bin_search (size_t size_a, size_t s_type, const void *mean, const void *a, com_fun com_F);

/* ������� ������� ����� ������� �� ��������� mean � ������� a ������� size_t.
 * ��������� ����� ������� com_F. ������ ���� s_type.
 * ������� ���������� -1, ���� ������ �� ��� �������.
 * ������� ���������� ������ ��������, ���� ������ ��� �������.
 */
size_t bin_place (size_t size_a, size_t s_type, const void *mean, const void *a, com_fun com_F);

#endif // BINARY_MODULE_H_INCLUDED
