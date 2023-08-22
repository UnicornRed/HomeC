/* ������������ ������ 17.3.
 * �����: ������� ������. ������: 20.�05-��
 * ������ ��������� ������� F �� ������ �� ����� input.txt � �������� ��������� ������ � ������� ��������� �� ����� input_test.txt.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "check_test.h"

#define STRING_SIZE 1001

/* ������� ���������� ������ str1 � str2.
 * ������� ���������� -1, ���� ������ �� ���� ��������.
 * ������� ���������� 1, ���� ������ �� �����.
 * ������� ���������� 0, ���� ������ �����.
 */
int str_comp (char *str1, char *str2)
{
    if (!str1 || !str2)
        return -1;

    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
            return 1;

        str1 ++;
        str2 ++;
    }

    if (*str1 != *str2)
        return 1;

    return 0;
}

/* ������� ��������� ������� F �� ������, �������� ��������� ������ � ������� ��������� �� ����� input_test.txt.
 * ������� ���������� 2, ���� �� ������� F ��� ������� �������� �����.
 * ������� ���������� 1, ���� ����� �� ���� �������, ��������� ������ � ������� F ��� str_comp ��� ������ � ������� ����� ��� ������ ��� ������� ���������.
 * ������� ���������� 0 � ��������� �������.
 */
int check_test (check_fun F)
{
    FILE* f_test = fopen("input_test.txt", "r");

    if (!f_test)
    {
        printf("������ �������� �����!\n");

        fclose (f_test);

        return 1;
    }

    char str[STRING_SIZE], dst[STRING_SIZE], true_str[STRING_SIZE];
    int pos, num, bool_check, bool_comp;

    while ((bool_check = (fscanf(f_test, "%1001s", str) != -1)))
    {
        if (!bool_check)
        {
            printf("������ ������ ������!\n");

            fclose (f_test);

            return 1;
        }

        printf("�������� ������: \"%s\".\n\n", str);

        if (fscanf(f_test, "%d%d", &pos, &num) != 2)
        {
            printf("������ ������ ������ ��� ����� ���������!\n");

            fclose (f_test);

            return 1;
        }

        printf("�������� ������� ������ � ����� ���������: %d %d.\n", pos, num);

        if (fscanf(f_test, "%1001s", true_str) == -1)
        {
            printf("������ ������ ������!\n");

            fclose (f_test);

            return 1;
        }

        if (true_str[0] == '\\' && true_str[1] == '0')
            true_str[0] = '\0';

        printf("���������� ���������: \"%s\".\n", true_str);

        if (F(str, pos, num, dst, STRING_SIZE))
        {
            printf("������ ���������� �������!");

            fclose (f_test);

            return 1;
        }

        printf("���������� ���������: \"%s\".\n", dst);

        bool_comp = str_comp(true_str, dst);

        if (!bool_comp)
            printf ("����� �����!\n\n");
        else if (bool_comp == -1)
            return 1;
        else
        {
            printf ("\n����� �������!\n");

            fclose (f_test);

            return 2;
        }
    }

    fclose (f_test);

    return 0;
}
