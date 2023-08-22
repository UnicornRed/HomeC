/* ������������ ������ 23.
 * �����: ������� ������. ������: 20.�05-��
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Matrix_module.h"
#include "Matrix_processing.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    size_t h, w;

    printf("������� ���������� ����� � �������� �������: ");

    if (scanf("%Iu%Iu", &h, &w) != 2)
    {
        printf("\n������ �����! ���������� ������ 2 ����� �����!\n");

        return 1;
    }

    matrix *m1 = NULL, *m = NULL;

    if (!(m1 = matrix_alloc(h, w)))
    {
        printf("\n������ �������� �������!\n");

        return 1;
    }

    printf("\n������� �������� �������:\n\n");

    if(matrix_scan(m1))
    {
        printf("\n������ ����� �������!\n");

        matrix_free(m1);

        return 1;
    }

    printf("\n�������� �������:\n\n");

    if (matrix_print(m1))
    {
        printf("\n������ ������ �������!\n");

        matrix_free(m1);

        return 1;
    }

    m = matrix_gauss_solution(m1);

    int bool_sol = matrix_gauss_test(m1, m, 1e-4);

    if (bool_sol == 1)
        printf("\n������� ��� �� �����\n");
    else if (bool_sol == -1)
        printf("\n������ ������������ ������� ��� ��� ��� �� ����� �������!\n");
    else
    {
        printf("\n������� ������� ���:\n\n");

        if (matrix_print(m))
        {
            printf("\n������ ������ �������!\n");

            matrix_free(m);
            matrix_free(m1);

            return 1;
        }
    }

    matrix_free(m);

    matrix *m2 = matrix_reverse(m1);

    if (!m2)
        printf("\n������ ���������� �������� �������!\n");
    else
    {
        printf("\n�������� �������:\n\n");

        if (matrix_print(m2))
        {
            printf("\n������ ������ �������!\n");

            matrix_free(m1);
            matrix_free(m2);

            return 1;
        }
    }

    matrix_free(m2);

    m2 = matrix_alloc(m1->height, m1->width);

    double e;

    printf("\n������� �����������: ");

    if (scanf("%lf", &e) != 1)
    {
        printf("\n������ �����! ���������� ������ ������������ �����!\n");

        matrix_free(m1);
        matrix_free(m2);

        return 1;
    }

    if (matrix_assign(m2, m1))
    {
        printf("\n������ ���������� �������!\n");

        matrix_free(m1);
        matrix_free(m2);

        return 1;
    }

    if (!(m = matrix_exp(m2, e)))
        printf("\n������ ���������� ���������� �������!\n");

    if (matrix_print(m))
    {
        printf("\n������ ������ �������!\n");

        matrix_free(m);
        matrix_free(m1);
        matrix_free(m2);

        return 1;
    }

    matrix_free(m);

    if (matrix_transpose(m2))
        printf("\n������ ������������ �������!\n");
    else
    {
        printf("\n����������������� �������:\n\n");

        if (matrix_print(m2))
        {
            printf("\n������ ������ �������!\n");

            matrix_free(m1);
            matrix_free(m2);

            return 1;
        }
    }

    double determinant = matrix_determinant(m1);

    if (determinant != determinant)
        printf("\n������ ���������� ������������ �������!\n");
    else
        printf("\n������������ �������: %f.\n", determinant);

    matrix_free(m1);
    matrix_free(m2);

    return 0;
}
