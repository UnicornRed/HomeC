/* ������������ ������ 17.1.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "space_del.h"

#define STRING_SIZE 1001

int main()
{
    setlocale(LC_ALL, "Russian");

    FILE* f = fopen("input.txt", "r");

    if (!f)
    {
        printf("������ �������� �����!\n");

        return 1;
    }

    char str[STRING_SIZE];

    if (!(fgets(str, STRING_SIZE, f)))
    {
        printf("������ ������ ������!\n");

        fclose (f);

        return 1;
    }

    fclose (f);

    printf("�������� ������: \"%s\".\n", str);

    if (space_del(str, STRING_SIZE))
    {
        printf("������ �������!\n");

        return 1;
    }

    printf("������ ��� \"������\" ��������: \"%s\".\n", str);

    return 0;
}
