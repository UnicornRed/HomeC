/*  ������������ ������ 8.4.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*�������, ����������� ���������� p-����� �������� � ����� n*/
int discharge (int p, int n)
{
    int k;
    if (n == 0)
        k = 1;
    while (abs(n) > 0)
    {
        k ++;
        n /= p;
    }
    return k;
}

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, p;

    printf("������� ������� ��������� � ����� �����: ");
    if (scanf("%d%d", &p, &n) != 2)
    {
        printf("������ �����! ���������� ������ 2 ����� �����! ������� ��������� �� ������ 2!\n");
        return 1;
    }

    printf("���������� p-����� �������� � ����� %d: %d",n,discharge(p, n));
    return 0;
}

