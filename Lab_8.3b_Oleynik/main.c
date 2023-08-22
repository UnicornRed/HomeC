/*  ������������ ������ 8.3b.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*�������, ������� ������� ����� �� * ������� n, ������� m � �������� d*/
void frame (int m, int n, int d)
{
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            if (i < d || i > n - d - 1 || j < d || j > m - d - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    setlocale (LC_ALL, "Russian");

    int m, n, d;

    printf("������� �����, ������ � ������� �����: ");
    if (scanf("%d%d%d", &m, &n, &d) != 3 || m < 0 || n < 0 || d < 0)
    {
        printf("������ �����! ���������� ������ 3 ����������� �����!\n");
        return 1;
    }

    frame(m, n, d);
    return 0;
}
