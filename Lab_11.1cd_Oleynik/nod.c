#include <stdio.h>
#include <stdlib.h>
#include "nod.h"

/* Функция, рекурсивно вычисляющая НОД чисел n и m.*/
int r_nod (int n, int m)
{
    if (m == 0)
        return n;
    else
        return r_nod(m, n % m);
}

int nod (int n, int m)
{
    int p;

    if (n < m)
        p = n, n = m, m = p;

    return r_nod(n, m);
}

int it_nod (int n, int m)
{
    while (n != 0 && m != 0)
    {
        if (n > m)
            n %= m;
        else
            m %= n;
    }

    return (m + n);
}
