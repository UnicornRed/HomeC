/*  ������������ ������ 11.1b.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dig_sqrt.h"

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, p;

    printf ("������� ������� ��������� � �����: ");

    if (scanf("%d%d", &p, &n) != 2)
    {
        printf ("������ �����! ���������� ������ 2 ����� �����!\n");
        return 1;
    }

    printf ("�������� ������ ����� %d � ������� ��������� %d �����: %d\n", n, p, dig_sqrt(p, n));
    return 0;
}
