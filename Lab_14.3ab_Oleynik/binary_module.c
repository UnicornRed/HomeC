/* ������������ ������ 14.3ab.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ������� ������� � ����� ������� �� ��������� mean � ������� a ������� size_t.
 * ��������� ����� ������� com_F. ������ ���� s_type.
 */

#include <stdio.h>
#include <stdlib.h>
#include "binary_module.h"

/* ������� ������� ������� �� ��������� mean � ������� a ������� size_t.
 * ��������� ����� ������� com_F. ������ ���� s_type.
 * ������� ���������� NULL, ���� ������ �� ��� ������� ��� ������� �� ������.
 * ������� ���������� ��������� �� �������, ���� �� ������.
 */
const void* bin_search (size_t size_a, size_t s_type, const void *mean, const void *a, com_fun com_F)
{
    if (!a)
        return NULL;

    const void *r = a, *l = a + (size_a - 1) * s_type, *flag_m;

    if (com_F(l, mean) == 1 || com_F(r, mean) == -1)
        return NULL;

    int bool_mean, bool_mean1;

    while (r < l)
    {
        flag_m = r + ((l - r) / s_type) / 2 * s_type;
        bool_mean = com_F(flag_m, mean);

        if (bool_mean == -1)
            l = flag_m;
        else if (bool_mean == 1)
        {
            bool_mean1 = com_F(flag_m + s_type, mean);
            if (bool_mean1 == -1)
                return NULL;
            else if (bool_mean1 == 0)
                return flag_m + s_type;
            else
                r = flag_m;
        }
        else
            return flag_m;
    }

    return NULL;
}

/* ������� ������� ����� ������� �� ��������� mean � ������� a ������� size_t.
 * ��������� ����� ������� com_F. ������ ���� s_type.
 * ������� ���������� -1, ���� ������ �� ��� �������.
 * ������� ���������� ������ ��������, ���� ������ ��� �������.
 */
size_t bin_place (size_t size_a, size_t s_type, const void *mean, const void *a, com_fun com_F)
{
    if (!a)
        return -1;

    const void *r = a, *l = a + (size_a - 1) * s_type, *flag_m;

    if (com_F(l, mean) == 1)
        return size_a;
    else if (com_F(r, mean) == -1)
        return 0;
    else
    {
        int bool_mean, bool_mean1;

        while (r < l)
        {
            flag_m = r + ((l - r) / s_type) / 2 * s_type;
            bool_mean = com_F(flag_m, mean);

            if (bool_mean == -1)
                l = flag_m;
            else if (bool_mean == 1)
            {
                bool_mean1 = com_F(flag_m + s_type, mean);
                if (bool_mean1 == -1)
                {
                    flag_m += s_type;
                    break;
                }
                else if (bool_mean1 == 0)
                {
                    flag_m += s_type;
                    break;
                }
                else
                    r = flag_m;
            }
            else
                break;
        }

        while (!com_F(flag_m, mean))
            flag_m += s_type;

        return (flag_m - a) / s_type;
    }
}
