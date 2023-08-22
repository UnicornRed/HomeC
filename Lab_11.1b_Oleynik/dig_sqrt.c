#include <stdlib.h>
#include <stdio.h>
#include "dig_sqrt.h"

/* ‘ункци€, вычисл€юща€ сумму цифр числа n в системе счислени€ p.*/
int sum_num (int p, int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum += n % p;
        n /= p;
    }

    return sum;
}

/* ‘ункци€, рекурсивно вычисл€юща€ цифровой корень числа n в системе счислени€ p.*/
int r_dig_sqrt (int p, int n)
{
    if (n < p)
        return n;
    else
        return r_dig_sqrt(p, sum_num(p, n));
}

int dig_sqrt (int p, int n)
{
    n = abs(n);

    if (p < 2)
        return -1;
    else
        return r_dig_sqrt(p, n);
}
