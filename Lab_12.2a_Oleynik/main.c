/* ������������ ������ 12.2a.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "num_sign.h"

#define M_SIZE 1000

int main()
{
    setlocale(LC_ALL, "Russian");

    int m[M_SIZE] = {};
    size_t size_m;

    printf("������� ���������� ��������� �������: ");

    if(scanf("%Iu", &size_m) != 1 || size_m > M_SIZE)
    {
        printf("������ �����! ���������� ������ ����� ����� ������ 1001!\n");
        return 1;
    }

    printf("������� �������� �������: ");

    for (int i = 0; i < size_m; i ++)
    {
        if(scanf("%d", &m[i]) != 1)
        {
            printf("������ �����! ���������� ������ ����� �����!\n");
            return 1;
        }
    }

    int num = num_sign(size_m, m);
    if (num != -1)
        printf("�������� ������� ������ ���� %d ���.\n", num);
    else
    {
        printf("������!\n");
        return 1;
    }
    return 0;
}
