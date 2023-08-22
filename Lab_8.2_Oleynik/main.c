/*  ������������ ������ 8.2.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int b_st (int n, int m)
{
    int pr = abs(m) <= 1 ? m : 1;
    while (abs(pr) < abs(n))
    {
        pr *= m;
        if (pr == 1 || pr == 0)
            break;
    }
    if (pr == n || (n == 1 && m == -1))
        return 1;
    else
        return 0;
}

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, m;

    printf("������� 2 �����: ");
    if (scanf("%d%d", &n, &m) != 2)
    {
        printf("������ �����! ���������� ������ 2 ����� �����!\n");
        return 1;
    }

    if (b_st(n, m))
        printf("����� %d �������� ����������� �������� ����� %d.\n", n, m);
    else
        printf("����� %d �� �������� ����������� �������� ����� %d.\n", n, m);
    return 0;
}
