/* ������������ ������ 12.3a.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ������� ��� ������ (��������) �������� ������� m ������� size_m �� �������.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "del_even_noteven_array.h"

/* ������� ������� ��� ������ �������� ������� m ������� size_m �� �������.
 * ������� ���������� 0, ���� ������ ��� ������� �����������.
 * ������� ���������� ������ ���������� �������.
 */
int del_even_array (size_t size_m, int *m)
{
    if (!m)
        return -1;

    int *i_del = m;
    int middle;

    for (int *i = m; i < m + size_m; i ++)
    {
        middle = *i;
        *i = 0;
        if ((middle) % 2)
        {
            *i_del = middle;
            i_del ++;
        }
    }

    return i_del - m;
}

/* ������� ������� ��� �������� �������� ������� m ������� size_m �� �������.
 * ������� ���������� 0, ���� ������ ��� ������� �����������.
 * ������� ���������� ������ ���������� �������.
 */
int del_noteven_array (size_t size_m, int *m)
{
    if (!m)
        return -1;

    int *i_del = m;
    int middle;

    for (int *i = m; i < m + size_m; i ++)
    {
        middle = *i;
        *i = 0;
        if (!((middle) % 2))
        {
            *i_del = middle;
            i_del ++;
        }
    }

    return i_del - m;
}
