/* Лабораторная работа 23.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль находит обратную матрицу и решение СЛУ методом Гауса и вычисляет матричную экспоненту.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Matrix_module.h"
#include "Matrix_processing.h"

/* Функция находит обратную матрицу кваднратной матрицы matrix_a.
 * Функция возвращает NULL, если матрица не была передана, она не квадратна,
 * вспомогательная матрицы matrix_b или matrix_rev не сооздана или определитель матрицы равен 0.
 * Функция возвращает указатель на матрицу matrix_rev в остальных случаях.
 */
matrix * matrix_reverse (const matrix *matrix_a)
{
    if (!matrix_a || matrix_a->height != matrix_a->width)
        return NULL;

    size_t size_matrix = matrix_a->height;

    matrix *matrix_b = matrix_copy(matrix_a);
    matrix *matrix_rev = matrix_alloc_id(size_matrix);

    if (!matrix_b || !matrix_rev)
        return NULL;

    double element_t;

    for (size_t t = 0; t < size_matrix; t ++)
    {
        if (!(*(matrix_get_const(matrix_b, t, t))))
        {
            int bool_have = 0;

            for (size_t j = t + 1; j < size_matrix; j ++)
            {
                if (*(matrix_get_const(matrix_b, j, t)))
                {
                    matrix_rearranging_strings(matrix_rev, t, j);
                    matrix_rearranging_strings(matrix_b, t, j);

                    bool_have = 1;

                    break;
                }
            }

            if (!bool_have)
            {
                matrix_free(matrix_b);

                return NULL;
            }
        }

        element_t = *(matrix_get_const(matrix_b, t, t));

        for (size_t i = t + 1; i < size_matrix; i ++)
        {
            if (*(matrix_get_const(matrix_b, i, t)))
            {
                matrix_sum_string_multi_number(matrix_rev, i, t, (-1) * (*(matrix_get_const(matrix_b, i, t))) / element_t);
                matrix_sum_string_multi_number(matrix_b, i, t, (-1) * (*(matrix_get_const(matrix_b, i, t))) / element_t);
            }
        }
    }

    for (size_t t = size_matrix - 1; t < size_matrix; t --)
    {
        element_t = *(matrix_get_const(matrix_b, t, t));

        for (size_t i = t - 1; i < size_matrix; i --)
        {
            if (*(matrix_get_const(matrix_b, i, t)))
            {
                matrix_sum_string_multi_number(matrix_rev, i, t, (-1) * (*(matrix_get_const(matrix_b, i, t))) / element_t);
                matrix_sum_string_multi_number(matrix_b, i, t, (-1) * (*(matrix_get_const(matrix_b, i, t))) / element_t);
            }
        }
    }

    for (size_t i = 0; i < size_matrix; i ++)
    {
        matrix_multi_string_number(matrix_rev, i, 1.0 / (*(matrix_get_const(matrix_b, i, i))));
        matrix_multi_string_number(matrix_b, i, 1.0 / (*(matrix_get_const(matrix_b, i, i))));
    }

    double norm = matrix_norm(matrix_rev);

    for (size_t i = 0; i < size_matrix; i ++)
    {
        for (size_t j = 0; j < size_matrix; j ++)
            if (fabs(*(matrix_get_const(matrix_rev, i, j)) / norm) < 1e-6)
                *(matrix_get(matrix_rev, i, j)) = 0;
    }

    matrix_free(matrix_b);

    return matrix_rev;
}

/* Функция вычисляет матричную экспоненту от матрицы matrix_a с погрешностью e.
 * Функция возвращает NULL, если матрица не была передана, она не квадратна, вспомогательные
 * матрицы matrix_b, matrix_exp_sol или matrix_c не созданы или возникла ошибка в функциях
 * matrix_sum, matrix_assign, matrix_multi_scalar или matrix_norm.
 * Функция возвращает указатель на матрицу matrix_exp_sol в остальных случаях.
 */
matrix * matrix_exp (const matrix *matrix_a, const double e)
{
    if (!matrix_a || matrix_a->height != matrix_a->width)
        return NULL;

    size_t size_matrix = matrix_a->height;

    matrix *matrix_b = matrix_copy(matrix_a);
    matrix *matrix_c;
    matrix *matrix_exp_sol = matrix_alloc_id(size_matrix);

    if (!matrix_b || !matrix_exp_sol)
        return NULL;

    double norm = matrix_norm(matrix_b);
    int counter = 1;

    while(norm > e)
    {
        if (matrix_sum(matrix_exp_sol, matrix_b))
            return NULL;

        counter ++;

        matrix_c = matrix_alloc_multi(matrix_b, matrix_a);

        if (!matrix_c)
            return NULL;

        if (matrix_assign(matrix_b, matrix_c))
            return NULL;

        if (matrix_multi_scalar(matrix_b, 1.0 / counter))
            return NULL;

        matrix_free(matrix_c);

        if ((norm = matrix_norm(matrix_b)) == -1)
            return NULL;
    }

    matrix_free(matrix_b);

    return matrix_exp_sol;
}

/* Функция проверяет решение matrix_sol на матрице СЛУ matrix_a с погрешностью e.
 * Функция возвращает -1, если матрицы не были переданы, произошла ошибка в функции matrix_norm или
 * количество строк матрицы matrix_sol и количество столбцов матрицы matrix_a минус 1 не совпадает.
 * Функция возвращает 1, если матрица matrix_sol не является решением.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_gauss_test (const matrix *matrix_a, const matrix *matrix_sol, const double e)
{
    if (!matrix_a || !matrix_sol || matrix_a->width - 1 != matrix_sol->height)
        return -1;

    size_t height = matrix_a->height, width = matrix_a->width - 1;

    double sol_string, norm;

    if ((norm = matrix_norm(matrix_a)) == -1)
            return -1;

    for (size_t i = 0; i < height; i ++)
    {
        sol_string = 0;

        for (size_t j = 0; j < width; j ++)
            sol_string += (*(matrix_get_const(matrix_a, i, j))) * (*(matrix_get_const(matrix_sol, j, 0)));

        if (fabs((*(matrix_get_const(matrix_a, i, width)) - sol_string) / norm) > e)
            return 1;
    }

    return 0;
}

/* Функция решает СЛУ, заданную матрицей matrix_a.
 * Функция возвращает NULL, если матрица не была передана, вспомогательная матрица matrix_b не создана,
 * бесконечное количество решений или решений нет.
 * Функция возвращает указатель на матрицу matrix_sol в остальных случаях.
 */
matrix * matrix_gauss_solution (const matrix *matrix_a)
{
    if (!matrix_a || matrix_a->height < matrix_a->width - 1)
        return NULL;

    size_t height = matrix_a->height, width = matrix_a->width - 1;

    matrix *matrix_b = matrix_copy(matrix_a);

    if (!matrix_b)
        return NULL;

    double element_t;
    size_t num_sol = width;

    for (size_t t = 0; t < width; t ++)
    {
        if (!(*(matrix_get_const(matrix_b, t, t))))
        {
            int bool_have = 0;

            for (size_t j = t + 1; j < height; j ++)
            {
                if (*(matrix_get_const(matrix_b, j, t)))
                {
                    matrix_rearranging_strings(matrix_b, t, j);

                    bool_have = 1;

                    break;
                }
            }

            if (!bool_have)
            {
                matrix_free(matrix_b);

                return NULL;
            }
        }

        element_t = *(matrix_get_const(matrix_b, t, t));

        for (size_t i = t + 1; i < height; i ++)
        {
            if (*(matrix_get_const(matrix_b, i, t)))
                matrix_sum_string_multi_number(matrix_b, i, t, (-1) * (*(matrix_get_const(matrix_b, i, t))) / element_t);

            if (t == width - 1 && *(matrix_get_const(matrix_b, i, width)) != 0)
                return NULL;
        }
    }

    for (size_t t = width - 1; t < width; t --)
    {
        element_t = *(matrix_get_const(matrix_b, t, t));

        for (size_t i = t - 1; i < height; i --)
        {
            if (*(matrix_get_const(matrix_b, i, t)))
                matrix_sum_string_multi_number(matrix_b, i, t, (-1) * (*(matrix_get_const(matrix_b, i, t))) / element_t);
        }
    }

    matrix *matrix_sol = matrix_alloc(num_sol, 1);

    if (!matrix_sol)
        return NULL;

    for (size_t i = 0; i < width; i ++)
    {
        matrix_multi_string_number(matrix_b, i, 1.0 / (*(matrix_get_const(matrix_b, i, i))));
        *(matrix_get(matrix_sol, i, 0)) = *(matrix_get_const(matrix_b, i, matrix_b->width - 1));
    }

    matrix_free(matrix_b);

    return matrix_sol;
}
