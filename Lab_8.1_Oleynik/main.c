/*  ������������ ������ 8.1.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*�������, ����������� �������� ������ ����� ������������ ����*/
int dr (int n, int p)
{
    int sum = 0;
    while (n >= p)
    {
        sum = 0;
        while (n > 0)
        {
            sum += n % p;
            n /= p;
        }
        n = sum;
    }
    return n;
}

int main()
{
    setlocale (LC_ALL, "Russian");

    int n, p;

    printf("������� ������� ��������� � �����: ");
    if (scanf("%d%d", &p, &n) != 2 || p < 2 || n < 1)
    {
        printf("������ �����! ���������� ������ 2 ����������� �����! ������� ��������� �� ������ 2!\n");
        return 1;
    }

    printf("�������� ������ ����� %d � ������� ��������� %d �����: %d\n", n, p, dr(n, p));
    return 0;
}
