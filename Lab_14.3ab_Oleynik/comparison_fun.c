/* ������������ ������ 14.3ab.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ���������� �������� a � b.
 */

#include <stdio.h>
#include <stdlib.h>
#include "comparison_fun.h"

/* ������� ���������� �������� a � b.
 * ������� ���������� -1, ���� a > b.
 * ������� ���������� 0, ���� a = b.
 * ������� ���������� 1, ���� a < b.
 */
int double_comparison (const void *a, const void *b)
{
    if (*((double*)a) > *((double*)b))
        return -1;
    else if (*((double*)a) == *((double*)b))
        return 0;
    else
        return 1;
}
