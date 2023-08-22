/*  ������������ ������ 5.3.
 *  �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, "Russian");

    int n_rub;

    printf("������� ����� � ������ �� 1 �� 99: ");

    if (scanf("%d", &n_rub) != 1)
    {
        printf("������ �����! ��������� ������ ����� �����!\n");
        return 1;
    }

    if (n_rub > 99 || n_rub < 1)
    {
        printf("�������� ����� �� �������� � �������� ��������!");
        return 1;
    }

    printf("����� � ������ �������: ");

    switch (n_rub / 10)
    {
        case 2:
            printf("�������� ");
            break;
        case 3:
            printf("�������� ");
            break;
        case 4:
            printf("����� ");
            break;
        case 5:
            printf("��������� ");
            break;
        case 6:
            printf("���������� ");
            break;
        case 7:
            printf("��������� ");
            break;
        case 8:
            printf("����������� ");
            break;
        case 9:
            printf("��������� ");
            break;
    }

    switch (n_rub)
    {
        case 10:
            printf("������ ");
            break;
        case 11:
            printf("����������� ");
            break;
        case 12:
            printf("���������� ");
            break;
        case 13:
            printf("���������� ");
            break;
        case 14:
            printf("������������ ");
            break;
        case 15:
            printf("���������� ");
            break;
        case 16:
            printf("����������� ");
            break;
        case 17:
            printf("���������� ");
            break;
        case 18:
            printf("������������ ");
            break;
        case 19:
            printf("������������ ");
            break;
    }

    if (n_rub / 10 != 1)
    {
        switch (n_rub % 10)
        {
            case 1:
                printf("���� ");
                break;
            case 2:
                printf("��� ");
                break;
            case 3:
                printf("��� ");
                break;
            case 4:
                printf("������ ");
                break;
            case 5:
                printf("���� ");
                break;
            case 6:
                printf("����� ");
                break;
            case 7:
                printf("���� ");
                break;
            case 8:
                printf("������ ");
                break;
            case 9:
                printf("������ ");
                break;
        }
    }

    if (n_rub % 10 == 0 || n_rub % 10 > 4 || (n_rub > 10 && n_rub < 20))
        printf("������\n");
    else if (n_rub % 10 > 1 && n_rub % 10 < 5)
        printf("�����\n");
    else
        printf("�����\n");

    return 0;
}
