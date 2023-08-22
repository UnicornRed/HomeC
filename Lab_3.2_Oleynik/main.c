/*  ������������ ������ 3.2.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    int sec_all, sec_1, min_1;

    printf("������� ���������� ������, "
           "��������� � ������ �����: ");
    if (scanf("%d", &sec_all) != 1 || sec_all < 0)
    {
        printf("������ �����! ���������� ������ ����� ������������� �����!\n");
        return 1;
    }

    min_1 = sec_all / 60 % 60;
    sec_1 = sec_all % 60;

    printf("���������� ����� � ������, "
           "��������� � ������ ���������� ����: %02d:%02d", min_1, sec_1);
    return 0;
}
