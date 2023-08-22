/*  ������������ ������ 9.1.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*�������, ����������� ����� (sum) � ����� (num) p-����� ���� ����� n*/
int sum_and_num (int p, int n, int *s)
{
    int sum = 0, num = 0;
    if (n == 0)
        num = 1;
    if (p < 2)
        return 0;
    n = abs(n);
    while (n > 0)
    {
        num ++;
        sum += n % p;
        n /= p;
    }
    if (s) *s = sum;
    return num;
}

int main()
{
    setlocale (LC_ALL, "Russian");

    int p, n, sum, num;

    printf("������� ������� ��������� � �����: ");
    if (scanf("%d%d", &p, &n) != 2)
    {
        printf("������ �����! ���������� ������ 2 ����� �����!\n");
        return 1;
    }

    num = sum_and_num(p, abs(n), &sum);

    printf("����� � ����� %d-����� ���� ����� %d: %d � %d\n", p, n, sum, num);
    return 0;
}

