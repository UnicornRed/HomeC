/* ������������ ������ 14.1abd.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan_print_array.h"
#include "checking_monotony.h"
#include "del_even_noteven_array.h"

#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    int m[ARRAY_SIZE] = {}, bool_check = 0;
    size_t size_m, size_a;
    double a[ARRAY_SIZE] = {};

    printf("������� ������ �������������� �������: ");

    if (scanf("%Iu", &size_m) != 1 || size_m > ARRAY_SIZE)
    {
        printf("������ �����! ���������� ������ ����� ����� ������ 1001!\n");
        return 1;
    }

    printf ("������� �������� �������: ");

    if(scan_array(size_m, m))
    {
        printf("������ �����! ���������� ������ ����� �����!\n");
        return 1;
    }

    printf("������� ������ ������������� �������: ");

    if (scanf("%Iu", &size_a) != 1 || size_a > ARRAY_SIZE)
    {
        printf("������ �����! ���������� ������ ����� ����� ������ 1001!\n");
        return 1;
    }

    printf ("������� �������� �������: ");

    if(fscan_array(size_a, a))
    {
        printf("������ �����! ���������� ������ ������������ �����!\n");
        return 1;
    }

    printf("�������� ��������:\n");

    if (fprint_array(size_a, a))
    {
        printf("������ ������!\n");
        return 1;
    }

    bool_check = checking_monotony_down(size_a, a);

    if (bool_check)
        printf ("������ ���������� �� ��������.\n");
    else if (!bool_check)
        printf ("������ �� ���������� �� ��������.\n");
    else
    {
        printf ("������ �������� �������!\n");
        return 1;
    }

    bool_check = checking_monotony_up(size_a, a);

    if (bool_check)
        printf ("������ ���������� �� �����������.\n");
    else if (!bool_check)
        printf ("������ �� ���������� �� �����������.\n");
    else
    {
        printf ("������ �������� �������!\n");
        return 1;
    }

    int choice = 0, size_del;

    printf ("��������, ����� �������� �������������� ������� ������ ���������: 1 - ������, 2 - ��������:\n");

    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        printf ("������ �����! ���������� ������ 1 ��� 2!\n");
        return 1;
    }

    if (choice == 1)
        size_del = del_even_array(size_m, m);
    else
        size_del = del_noteven_array(size_m, m);

    if (size_del > -1)
    {
        printf("��������� ������:\n");

        if (print_array(size_del, m))
        {
            printf("������ ������!\n");
            return 1;
        }
    }
    else
    {
        printf("������!\n");
        return 1;
    }
    return 0;
}
