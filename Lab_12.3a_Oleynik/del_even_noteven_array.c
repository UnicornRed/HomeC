/* ������������ ������ 12.3a.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ������� ��� ������ (��������) �������� ������� m ������� size_m �� �������.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "del_even_noteven_array.h"

int del_even_array (size_t size_m, int *m)
{
    if (m == 0)
        return -1;

    int i_del = 0, middle;

    for (int i = 0; i < size_m; i ++)
    {
        middle = m[i];
        m[i] = 0;
        if (abs(middle) % 2 == 1)
        {
            m[i_del] = middle;
            i_del ++;
        }
    }

    return i_del;
}

int del_noteven_array (size_t size_m, int *m)
{
    if (m == 0)
        return -1;

    int i_del = 0, middle;

    for (int i = 0; i < size_m; i ++)
    {
        middle = m[i];
        m[i] = 0;
        if (middle % 2 == 0)
        {
            m[i_del] = middle;
            i_del ++;
        }
    }

    return i_del;
}
