/*  ������������ ������ 8.5.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*�������, ����������� ������ ����� n*/
double approxsqrt (double a)
{
    double sq = a, psq;
    const double e = 1e-7 * a;
    if (a < 0)
        return 0.0 / 0.0;
    if (a == 0)
        return 0;
    if (a == 1.0 / 0.0)
        return 1.0 / 0.0;
    do
    {
        psq = sq;
        sq = 0.5 * (psq + a / psq);
    }
    while (fabs((sq - psq) / sq) > e);
    return sq;
}

int main()
{
    setlocale (LC_ALL, "Russian");

    double a, sqrt;

    printf("������� ������������ �����: ");
    if (scanf("%lf", &a) != 1)
    {
        printf("������ �����! ���������� ������ ������������ �����!\n");
        return 1;
    }

    sqrt = approxsqrt(a);

    if (sqrt == 1.0 / 0.0)
        printf("������ ����� INF: INF\n");
    else if (sqrt != sqrt)
        printf("������ ����� %g: NaN\n",a);
    else
        printf("������ ����� %g: %.6f\n",a,approxsqrt(a));
    return 0;
}
