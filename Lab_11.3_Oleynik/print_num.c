#include <stdio.h>
#include <stdlib.h>
#include "print_num.h"

/* �������, ���������� ���������� �� ������ ����� n � p-����� ������� ��������� � ������ �������.*/
void r_print_num (int p, int n)
{
    if (n > 0)
    {
        int remain = n % p;
        r_print_num(p, n / p);
        if (remain < 10)
            printf("%d", remain);
        else if (remain < 36)
            printf("%c", (char)(remain + 87));
        else
            printf("%c", (char)(remain + 29));
    }
}

void print_num (int p, int n)
{
    if (p < 2 || n < 0 || p > 62)
        printf ("Error!");
    else if (n == 0)
        printf ("0");
    else
        r_print_num(p, n);
}

/* �������, ���������� ���������� �� ������ ����� n � p-����� ������� ��������� � �������� �������.*/
void r_print_num_r (int p, int n)
{
    if (n > 0)
    {
        int remain = n % p;
        if (remain < 10)
            printf("%d", remain);
        else if (remain < 36)
            printf("%c", (char)(remain + 87));
        else
            printf("%c", (char)(remain + 29));
        r_print_num_r(p, n / p);
    }
}

void print_num_r (int p, int n)
{
    if (p < 2 || n < 0 || p > 62)
        printf ("Error!");
    else if (n == 0)
        printf ("0");
    else
        r_print_num_r(p, n);
}
