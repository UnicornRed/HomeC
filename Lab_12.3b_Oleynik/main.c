/* ������������ ������ 12.3b.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "del_norepeat.h"

#define ARRAY_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    size_t size_m;
    double m[ARRAY_SIZE] = {};
    int size_del;

    printf ("������� ������ ������������� �������: ");

    if (scanf("%Iu", &size_m) != 1 || size_m > ARRAY_SIZE)
    {
        printf("������ �����! ���������� ������ ����� ����� ������ 1001!\n");
        return 1;
    }

    printf ("������� �������� �������: ");

    for (int i = 0; i < size_m; i ++)
    {
        if (scanf("%lf", &m[i]) != 1)
        {
            printf("������ �����! ���������� ������ ������������ �����!\n");
            return 1;
        }
    }

    size_del = del_norepeat(size_m, m);

    if (size_del > -1)
    {
        printf ("��������� ������:\n");

        for (int i = 0; i < size_m; i ++)
            printf ("%f\n", m[i]);
    }
    else
    {
        printf("������!\n");
        return 1;
    }
    return 0;
}
