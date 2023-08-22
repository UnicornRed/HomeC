/* ������������ ������ 12.2a.
 * �����: ������� ������. ������: 20.�05-��
 * ������, ��������� ������� ��� �������� ������� ������ ���� ��� ��������� �� ��� ������.
 */

#include <stdio.h>
#include <stdlib.h>
#include "num_sign.h"

int num_sign (size_t size_m, const int *m)
{
    if (m == 0)
        return -1;
    int num = 0;
    for (int i = 1; i < size_m; i ++)
    {
        if (m[i] * m[i -1] < 0)
            num ++;
    }
    return num;
}
