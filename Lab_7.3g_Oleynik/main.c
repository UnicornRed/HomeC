/*  ������������ ������ 7.3g.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    const double e = 1e-5;
    double numb, sum = 0, aver;
    int vol = 0;

    printf("������� ������������������ ������������� ������������ �����, �������������� 0:\n");

    while (1)
    {
        if (scanf("%lf", &numb) != 1 || numb < 0.0)
        {
            printf("������ �����! ��������� ������ ������������� ����� ��� ���� ��� ���������� ������������������!\n");
            return 1;
        }
        if (fabs(numb) < e)
            break;
        sum += numb;
        ++ vol;
    }

    aver = sum / vol;

    printf("������� �������������� ������������������: %g", aver);
    return 0;
}
