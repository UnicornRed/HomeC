/* ������������ ������ 14.3ab.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "scan_print_array.h"
#include "comparison_fun.h"
#include "binary_module.h"


#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    size_t size_a;
    double a[ARRAY_SIZE] = {}, mean;

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

    printf("������� ��������, ������� ���������� ����� � �������: ");

    if (scanf("%lf", &mean) != 1)
    {
        printf("������ �����! ���������� ������ ������������ �����!\n");
        return 1;
    }

    com_fun F = double_comparison;
    const void *res_mean = bin_search(size_a, sizeof(double), &mean, a, F);

    if (res_mean)
        printf ("������ ���������� ��������: %d\n", (int)(res_mean - (void*)a) / (int)sizeof(double*));
    else
        printf ("������� �� ������!\n");

    size_t res_id = bin_place(size_a, sizeof(double), &mean, a, F);

    if ((int)res_id != -1)
        printf ("������ ��������, �� ������� ������� �������� �������: %Iu\n", res_id);
    else
        printf ("������!\n");

    return 0;
}
