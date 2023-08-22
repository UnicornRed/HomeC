#include <stdio.h>
#include <stdlib.h>
#include "sum_num.h"

/* ‘ункци€, рекурсивно вычисл€юща€ сумму цифр числа n в системе счислени€ p.*/
int r_sum_num (int p, int n)
{
    if (n / p == 0)
        return n;
    else
        return n % p + r_sum_num(p, n / p);
}

int sum_num(int p, int n)
{
    n = abs(n);
    if (p < 2)
        return -1;

    return r_sum_num(p, n);
}
