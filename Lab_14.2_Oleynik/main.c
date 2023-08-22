/* ������������ ������ 14.2.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan_print_array.h"
#include "search_misses.h"

#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    size_t size_a;
    double a[ARRAY_SIZE] = {}, miss_array[ARRAY_SIZE] = {};

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

    size_t num_miss = all_miss(size_a, a, miss_array);

    if (!num_miss)
        printf("�������� ���.\n");
    else if ((int)num_miss != -1)
    {
        printf("�������:\n");
        fprint_array(num_miss, miss_array);
    }
    else
    {
        printf("������!\n");
        return 1;
    }

    return 0;
}
