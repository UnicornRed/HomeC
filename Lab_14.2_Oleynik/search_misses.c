/* ������������ ������ 14.2.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ��������� ������� ��������������, ����������� ������ ������������������� ����������,
 * ������� ������ ��������� ��������, �������� �������� ����������� �� ����������� ��������
 * �� ��������� �������� � ��� ������� ���������.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_misses.h"

/* ������� ��������� ������� �������������� ��������� ������� a ������� size_a.
 * ������� ���������� NaN, ���� ������ �� ��� �������.
 * ������� ���������� �������� mean, ���� ������ ������� ���������.
 */
double arithmetic_mean (size_t size_a, const double *a)
{
    if (!a)
        return 0.0 / 0.0;

    double mean = 0;

    for (const double *i = a; i < a + size_a; i ++)
        mean += (*i) / size_a;

    return mean;
}

/* ������� ��������� ����������� ������ ������������������� ���������� ��������� ������� a ������� size_a.
 * ������� ���������� NaN, ���� ������ �� ��� �������.
 * ������� ���������� �������� sqrt(mean), ���� ������ ������� ���������.
 */
double unbiased_root_mean_square (size_t size_a, const double *a)
{
    if (!a)
        return 0.0 / 0.0;

    double mean = 0, ar_mean = arithmetic_mean(size_a, a);

    for (const double *i = a; i < a + size_a; i ++)
        mean += pow(*i - ar_mean, 2) / (size_a - 1);

    return sqrt(mean);
}

/* ������� ������� ������ ��������� �������� miss, �������� �������� ����������� �� ����������� �������� mean
 * �� ��������� �������� variance, � ������ ������� a ������� size_a_tail.
 * ������� ���������� NULL, ���� ������ �� ��� ������� ��� ����� ������� �� ��� ���������.
 * ������� ���������� ��������� miss, ���� ������ ������� ��������� � ����� ������� ��� ���������.
 */
const double* search_miss (size_t size_a_tail, double variance, double mean, const double *a)
{
    if (!a)
        return NULL;

    for (const double *i = a; i < a + size_a_tail; i ++)
    {
        if (fabs(mean - *i) > variance)
        {
            return i;
        }
    }

    return NULL;
}

/* ������� ������� ��� ������� ��������� � ������� a ������� size_a � ���������� �� � ������ miss_array.
 * ������� ���������� -1, ���� ������ a ��� ������ miss_array �� ���� ��������.
 * ������� ���������� �������� counter, ���� ������� ���� �������� ���������.
 */
size_t all_miss (size_t size_a, const double *a, double *miss_array)
{
    if ((!a) || (!miss_array))
        return -1;

    const double *end_a = a + size_a, *element_a = a - 1;
    double *counter = miss_array;
    double mean, var;

    mean = arithmetic_mean(size_a, a);
    var = unbiased_root_mean_square(size_a, a);

    if (mean != mean || var != var)
        return -1;

    do
    {
        element_a = search_miss(size_a, var, mean, element_a + 1);

        if (element_a != NULL && element_a != end_a)
        {
            *counter = *element_a;
            counter ++;
            size_a = end_a - element_a;
        }
    } while (element_a != end_a && element_a != NULL);

    return counter - miss_array;
}
