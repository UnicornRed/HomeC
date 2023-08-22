/*  ������������ ������ 7.1a.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    int p, sum = 0, numb;

    printf("������� ������� ��������� � ������������� �����: ");
    if (scanf("%d%d", &p, &numb) != 2 || numb < 1 || p < 2)
    {
        printf("������ �����! ��������� ������ 2 ����� ������������� �����! ������� ��������� �� ����� ���� ������ 2.\n");
        return 1;
    }

    while (numb > 0)
    {
        sum += numb % p;
        numb /= p;
    }

    printf("����� ���� � %d ������� ���������: %d", p, sum);
    return 0;
}
