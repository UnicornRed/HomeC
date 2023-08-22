/* Лабораторная работа 23.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
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

    printf("Введите количество строк и столбцов матрицы: ");

    if (scanf("%Iu%Iu", &h, &w) != 2)
    {
        printf("\nОшибка ввода! Необходимо ввести 2 целых числа!\n");

        return 1;
    }

    matrix *m1 = NULL, *m = NULL;

    if (!(m1 = matrix_alloc(h, w)))
    {
        printf("\nОшибка создания матрицы!\n");

        return 1;
    }

    printf("\nВведите элементы матрицы:\n\n");

    if(matrix_scan(m1))
    {
        printf("\nОшибка ввода матрицы!\n");

        matrix_free(m1);

        return 1;
    }

    printf("\nВведённая матрица:\n\n");

    if (matrix_print(m1))
    {
        printf("\nОшибка вывода матрицы!\n");

        matrix_free(m1);

        return 1;
    }

    m = matrix_gauss_solution(m1);

    int bool_sol = matrix_gauss_test(m1, m, 1e-4);

    if (bool_sol == 1)
        printf("\nРешение СЛУ не верно\n");
    else if (bool_sol == -1)
        printf("\nОшибка тестирования решения СЛУ или она не имеет решений!\n");
    else
    {
        printf("\nМатрица решений СЛУ:\n\n");

        if (matrix_print(m))
        {
            printf("\nОшибка вывода матрицы!\n");

            matrix_free(m);
            matrix_free(m1);

            return 1;
        }
    }

    matrix_free(m);

    matrix *m2 = matrix_reverse(m1);

    if (!m2)
        printf("\nОшибка нахождения обратной матрицы!\n");
    else
    {
        printf("\nОбратная матрица:\n\n");

        if (matrix_print(m2))
        {
            printf("\nОшибка вывода матрицы!\n");

            matrix_free(m1);
            matrix_free(m2);

            return 1;
        }
    }

    matrix_free(m2);

    m2 = matrix_alloc(m1->height, m1->width);

    double e;

    printf("\nВведите погрешность: ");

    if (scanf("%lf", &e) != 1)
    {
        printf("\nОшибка ввода! Необходимо ввести вещественное число!\n");

        matrix_free(m1);
        matrix_free(m2);

        return 1;
    }

    if (matrix_assign(m2, m1))
    {
        printf("\nОшибка присвоения матрицы!\n");

        matrix_free(m1);
        matrix_free(m2);

        return 1;
    }

    if (!(m = matrix_exp(m2, e)))
        printf("\nОшибка вычисления экспоненты матрицы!\n");

    if (matrix_print(m))
    {
        printf("\nОшибка вывода матрицы!\n");

        matrix_free(m);
        matrix_free(m1);
        matrix_free(m2);

        return 1;
    }

    matrix_free(m);

    if (matrix_transpose(m2))
        printf("\nОшибка транспозиции матрицы!\n");
    else
    {
        printf("\nТранспонированная матрица:\n\n");

        if (matrix_print(m2))
        {
            printf("\nОшибка вывода матрицы!\n");

            matrix_free(m1);
            matrix_free(m2);

            return 1;
        }
    }

    double determinant = matrix_determinant(m1);

    if (determinant != determinant)
        printf("\nОшибка вычисления определителя матрицы!\n");
    else
        printf("\nОпределителя матрицы: %f.\n", determinant);

    matrix_free(m1);
    matrix_free(m2);

    return 0;
}
