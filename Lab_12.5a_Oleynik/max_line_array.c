/* ������������ ������ 12.5a.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ���������� ����� ������ ������� a ������� size_a_h �� size_a_w � ���������� ������ ���������.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "max_line_array.h"

#define ARRAY_SIZE 100

int max_line_array (size_t size_a_h, size_t size_a_w, const double a[][ARRAY_SIZE])
{
    if (a == 0)
        return 0;

    double max_line, sum, max_sum;

    for (int i = 0; i < size_a_h; i ++)
    {
        sum = 0;
        for (int j = 0; j < size_a_w; j ++)
        {
            sum += a[i][j];
        }
        if (i == 0)
            max_sum = sum;
        if (sum > max_sum)
        {
            max_sum = sum;
            max_line = i;
        }
    }

    return max_line + 1;
}
