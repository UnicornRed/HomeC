#include <stdio.h>
#include <stdlib.h>
#include "print_num.h"

/* Функция, рекурсивно печатающая на экране число n в p-ичной системе счисления в прямом порядке.*/
void r_print_num (int p, int n)
{
    if (n > 0)
    {
        int remain = n % p;
        r_print_num(p, n / p);
        printf("(%d)", remain);
    }
}

void print_num (int p, int n)
{
    if (p < 2 || n < 0)
        printf ("Error!");
    else if (n == 0)
        printf ("0");
    else
        r_print_num(p, n);
}

/* Функция, рекурсивно печатающая на экране число n в p-ичной системе счисления в обратном порядке.*/
void r_print_num_r (int p, int n)
{
    if (n > 0)
    {
        int remain = n % p;
        printf("(%d)", remain);
        r_print_num_r(p, n / p);
    }
}

void print_num_r (int p, int n)
{
    if (p < 2 || n < 0)
        printf ("Error!");
    else if (n == 0)
        printf ("0");
    else
        r_print_num_r(p, n);
}
