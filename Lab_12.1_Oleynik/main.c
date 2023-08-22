/* ������������ ������ 12.1.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan_print_array.h"

#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    int m[ARRAY_SIZE] = {};
    size_t size_m, size_a;
    double a[ARRAY_SIZE] = {};

    printf("������� ������ �������������� �������: ");

    if (scanf("%Iu", &size_m) != 1 || size_m > ARRAY_SIZE)
    {
        printf("������ �����! ���������� ������ ����� ����� ������ 1001!\n");
        return 1;
    }

    if ((int)size_m > 0)
    {
        printf ("������� �������� �������: ");

        if(scan_array(size_m, m))
        {
            printf("������ �����! ���������� ������ ����� �����!\n");
            return 1;
        }
    }

    if ((int)size_m > 0)
    {
        printf("�������� ��������:\n");

        if (print_array(size_m, m))
        {
            printf("������ ������!\n");
            return 1;
        }
    }

    printf("������� ������ ������������� �������: ");

    if (scanf("%Iu", &size_a) != 1 || size_a > ARRAY_SIZE)
    {
        printf("������ �����! ���������� ������ ����� ����� ������ 1001!\n");
        return 1;
    }

    if ((int)size_a > 0)
    {
        printf ("������� �������� �������: ");

        if(fscan_array(size_a, a))
        {
            printf("������ �����! ���������� ������ ������������ �����!\n");
            return 1;
        }
    }

    if ((int)size_a > 0)
    {
        printf("�������� ��������:\n");

        if (fprint_array(size_a, a))
        {
            printf("������ ������!\n");
            return 1;
        }
    }
    return 0;
}
