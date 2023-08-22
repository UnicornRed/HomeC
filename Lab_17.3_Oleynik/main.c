/* ������������ ������ 17.3.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "substring.h"
#include "check_test.h"

#define STRING_SIZE 1001

int main()
{
    setlocale(LC_ALL, "Russian");

    /* �������������� ��������.*/

    check_fun F = substring;

    int bool_check = check_test(F);

    if (bool_check == 2)
        return 1;
    else if (bool_check == 1)
    {
        printf("������ �����!\n\n");
        return 1;
    }
    else
        printf("�������� ��������!\n\n");

    /* ���� �������������.*/

    FILE* f = fopen("input.txt", "r");

    if (!f)
    {
        printf("������ �������� �����!\n");

        fclose (f);

        return 1;
    }

    char str[STRING_SIZE], dst[STRING_SIZE];
    int pos, num;

    if (!(fgets(str, STRING_SIZE, f)))
    {
        printf("������ ������ ������!\n");

        fclose (f);

        return 1;
    }

    fclose (f);

    printf("�������� ������: \"%s\".\n"
           "������� ������ ������� �������� ��������� � � ������: ", str);

    if (scanf("%d%d", &pos, &num) != 2)
    {
        printf ("������ �����! ���������� ������ 2 ����� �����!\n");

        return 1;
    }

    if (substring(str, pos, num, dst, STRING_SIZE))
    {
        printf("������!\n");

        return 1;
    }

    printf("��������� � ������� %d ������� %d: \"%s\".\n", pos, num, dst);

    return 0;
}
