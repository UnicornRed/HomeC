/* ������������ ������ 15.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "array_monotone.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    int length_m;
    size_t size_a;
    double *a;

    printf ("������� ������ ������������� �������: ");

    if (scanf("%Iu", &size_a) != 1)
    {
        printf("������ �����! ���������� ������ ����� ����� ������ 1001!\n");
        return 1;
    }

    a = malloc(size_a * sizeof(double));

    if (!a)
    {
        printf("������ ��������� ������!");
        return 1;
    }

    printf ("������� �������� �������: ");

    for (int i = 0; i < size_a; i ++)
    {
        if (scanf("%lf", &a[i]) != 1)
        {
            printf("������ �����! ���������� ������ ������������ �����!\n");
            free(a);
            return 1;
        }
    }

    length_m = array_monotone(size_a, a);

    if (length_m == -1)
    {
        printf ("������ ���������� ����� ���������� ������������������.\n");
        free(a);
        return 1;
    }
    else
        printf ("����� ����������� ����������� ���������� � �������: %d\n", length_m);
    free(a);
    return 0;
}
