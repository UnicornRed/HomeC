/*  ������������ ������ 11.3.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "print_num.h"

int main()
{
    setlocale (LC_ALL, "Russian");

    int p, n;

    printf ("������� ������� ��������� � �����: ");

    while (scanf ("%d%d", &p, &n) != 2)
    {
        printf ("������ �����! ���������� ������ 2 ����� �����!");
        return 1;
    }

    printf ("����� %d � ������� ��������� %d � ������ �������: ", n, p);
    print_num(p, n);
    printf ("\n����� %d � ������� ��������� %d � �������� �������: ", n, p);
    print_num_r(p, n);
    printf ("\n");
    return 0;
}
