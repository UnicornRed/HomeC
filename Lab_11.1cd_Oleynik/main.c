/*  ������������ ������ 11.1cd.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "nod.h"

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, m, d, it_d;

    printf ("������� 2 �����: ");

    if (scanf ("%d%d", &n, &m) != 2)
    {
        printf ("������ �����! ���������� ������ 2 ����� �����!\n");
        return 1;
    }

    d = nod(n, m);
    it_d = it_nod(n, m);

    printf ("����������. ��� ����� %d � %d �����: %d\n", n, m, d);
    printf ("����������. ��� ����� %d � %d �����: %d\n", n, m, it_d);
    printf ("��� ����� %d � %d �����: %d\n", n, m, m / d * n);
    return 0;
}
