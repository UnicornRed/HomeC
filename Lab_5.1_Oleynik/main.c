/*  ������������ ������ 5.1.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    int n_year, n_day;

    printf("������� ����� ����: ");
    if (scanf("%d", &n_year) != 1 || n_year < 1)
    {
        printf("������ �����! ���������� ������ ����� ������������� �����!\n");
        return 1;
    }

    if (n_year % 4 == 0 && n_year % 100 !=0 || n_year % 400 == 0)
        n_day = 366;
    else
        n_day = 365;

    printf("���������� ���� � %d ����: %d", n_year, n_day);
    return 0;
}
