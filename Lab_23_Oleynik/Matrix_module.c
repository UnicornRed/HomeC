/* Лабораторная работа 23.
 * Автор: Олейник Михаил. Группа: 20.Б05-мм
 * Модуль создаёт и копирует, вводит и выводит, изменяет и обрабатывет матрицы.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Matrix_module.h"

/* Функция создаёт матрицу с количеством строк height и количеством столбцов width.
 * Функция возвращает NULL, если не была выделена память под указатель на матрицу или под массив данных.
 * Функция возвращает указатель matrix_a на созданную матрицу в остальных случаях.
 */
matrix * matrix_alloc (size_t height, size_t width)
{
    matrix *matrix_a;

    matrix_a = malloc(sizeof(matrix));

    if (!matrix_a)
        return NULL;

    matrix_a->matrix_array = malloc(height * width * sizeof(double));

    if (!(matrix_a->matrix_array))
        return NULL;

    matrix_a->height = height;
    matrix_a->width = width;

    return matrix_a;
}

/* Функция особождает память, выделенную под указатель на матрицу matrix_a или под массив данных.
 */
void matrix_free (matrix *matrix_a)
{
    if (matrix_a)
    {
        free(matrix_a->matrix_array);
        free(matrix_a);
    }
}

/* Функция вводит данные в массив матрицы matrix_a через консоль ввода.
 * Функция возвращает 1, если матрица не была передана.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_scan (matrix *matrix_a)
{
    if (!matrix_a)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            scanf("%lf", matrix_get(matrix_a, i, j));
    }

    return 0;
}

/* Функция выводит данные массива матрицы matrix_a через консоль вывода.
 * Функция возвращает 1, если матрица не была передана.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_print (const matrix *matrix_a)
{
    if (!matrix_a)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            printf("%f ", *(matrix_get_const(matrix_a, i, j)));

        printf("\n");
    }

    return 0;
}

/* Функция вводит данные в массив матрицы matrix_a через файл с названием, переданным в строке file.
 * Функция возвращает 1, если матрица или строка не были передана или файл не был открыт.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_fscan (const char * file, matrix *matrix_a)
{
    if (!file || !matrix_a)
        return 1;

    FILE *f = fopen(file, "r");

    if (!f)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            fscanf(f, "%lf", matrix_get(matrix_a, i, j));
    }

    fclose(f);

    return 0;
}

/* Функция выводит данные массива матрицы matrix_a в файл с названием, переданным в строке file.
 * Функция возвращает 1, если матрица или строка не были передана или файл не был открыт.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_fprint (const char * file, const matrix *matrix_a)
{
    if (!file || !matrix_a)
        return 1;

    FILE *f = fopen(file, "w");

    if (!f)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            fprintf(f, "%f ", *(matrix_get_const(matrix_a, i, j)));

        fprintf(f, "\n");
    }

    fclose(f);

    return 0;
}

/* Функция получает указатель на элемент матрицы matrix_a с индексами i и j.
 * Функция возвращает NULL, если матрица не была передана, индекс i был больше или равен
 * количества строк матрицы или индекс j - количества столбцов.
 * Функция возвращает указатель на найденный элемент в остальных случаях.
 */
double * matrix_get (matrix *matrix_a, size_t i, size_t j)
{
    if (!matrix_a || i >= matrix_a->height || j >= matrix_a->width)
        return NULL;

    return (matrix_a->matrix_array + i * matrix_a->width + j);
}

/* Функция получает константный указатель на элемент матрицы matrix_a с индексами i и j.
 * Функция возвращает NULL, если матрица не была передана, индекс i был больше или равен
 * количества строк матрицы или индекс j - количества столбцов.
 * Функция возвращает константный указатель на найденный элемент в остальных случаях.
 */
const double * matrix_get_const (const matrix *matrix_a, size_t i, size_t j)
{
    if (!matrix_a || i >= matrix_a->height || j >= matrix_a->width)
        return NULL;

    return (matrix_a->matrix_array + i * matrix_a->width + j);
}

/* Функция создаёт матрицу, копируя в неё данные матрицы matrix_a.
 * Функция возвращает NULL, если матрица matrix_a не была предана или новая матрица не была создана.
 * Функция возвращает указатель на новую матрицу в остальных случаях.
 */
matrix * matrix_copy (const matrix *matrix_a)
{
    if (!matrix_a)
        return NULL;

    matrix *matrix_b = matrix_alloc(matrix_a->height, matrix_a->width);

    if (!matrix_b)
        return NULL;

    size_t height = matrix_a->height, width = matrix_a->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_b, i, j)) = *(matrix_get_const(matrix_a, i, j));
    }

    return matrix_b;
}

/* Функция создаёт единичную матрицу размера size_matrix.
 * Функция возвращает NULL, если матрица не была создана.
 * Функция возвращает указатель matrix_a на созданную матрицу в остальных случаях.
 */
matrix * matrix_alloc_id (size_t size_matrix)
{
    matrix *matrix_a = matrix_alloc(size_matrix, size_matrix);

    if (!matrix_a)
        return NULL;

    for (size_t i = 0; i < size_matrix; i ++)
    {
        for (size_t j = 0; j < size_matrix; j ++)
        {
            if (i == j)
                *(matrix_get(matrix_a, i, j)) = 1;
            else
                *(matrix_get(matrix_a, i, j)) = 0;
        }
    }

    return matrix_a;
}

/* Функция создаёт нулевую матрицу с количеством строк height и количеством столбцов width.
 * Функция возвращает NULL, если матрица не была создана.
 * Функция возвращает указатель matrix_a на созданную матрицу в остальных случаях.
 */
matrix * matrix_alloc_zero (size_t height, size_t width)
{
    matrix *matrix_a = matrix_alloc(height, width);

    if (!matrix_a)
        return NULL;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_a, i, j)) = 0;
    }

    return matrix_a;
}

/* Функция копирует значения матрицы matrix_src в матрицу matrix_dst.
 * Функция возвращает 1, если матрицы не были переданы или количество строк или столбцов у матриц не совпадает.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_assign (matrix *matrix_dst, const matrix *matrix_src)
{
    if (!matrix_dst || !matrix_src || matrix_dst->height != matrix_src->height || matrix_dst->width != matrix_src->width)
        return 1;

    size_t height = matrix_dst->height, width = matrix_dst->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_dst, i, j)) = *(matrix_get_const(matrix_src, i, j));
    }

    return 0;
}

/* Функция складывает матрицы matrix_a1 и matrix_a2, записывая результат в матрицу matrix_a1.
 * Функция возвращает 1, если матрицы не были переданы или количество строк или столбцов у матриц не совпадает.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_sum (matrix *matrix_a1, const matrix *matrix_a2)
{
    if (!matrix_a1 || !matrix_a2 || matrix_a1->height != matrix_a2->height || matrix_a1->width != matrix_a2->width)
        return 1;

    size_t height = matrix_a1->height, width = matrix_a1->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_a1, i, j)) = *(matrix_get_const(matrix_a1, i, j)) + *(matrix_get_const(matrix_a2, i, j));
    }

    return 0;
}

/* Функция складывает матрицы matrix_a1 и matrix_a2, записывая результат в матрицу matrix_a.
 * Функция возвращает 1, если матрицы не были переданы или количество строк или столбцов у матриц не совпадает.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_sum_three (const matrix *matrix_a1, const matrix *matrix_a2, matrix *matrix_a)
{
    if (!matrix_a || !matrix_a1 || !matrix_a2 || matrix_a1->height != matrix_a2->height || matrix_a1->width != matrix_a2->width ||
        matrix_a->height != matrix_a1->height || matrix_a->width != matrix_a1->width)
        return 1;

    size_t height = matrix_a1->height, width = matrix_a1->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_a, i, j)) = *(matrix_get_const(matrix_a1, i, j)) + *(matrix_get_const(matrix_a2, i, j));
    }

    return 0;
}

/* Функция создаёт матрицу matrix_b и складывает матрицы matrix_a1 и matrix_a2, записывая результат в матрицу matrix_b.
 * Функция возвращает NULL, если матрицы matrix_a1 или matrix_a2 не были переданы, матрица matrix_b не создана
 * или количество строк или столбцов у матриц не совпадает.
 * Функция возвращает указатель на матрицу matrix_b в остальных случаях.
 */
matrix * matrix_alloc_sum (const matrix *matrix_a1, const matrix *matrix_a2)
{
    if (!matrix_a1 || !matrix_a2 || matrix_a1->height != matrix_a2->height || matrix_a1->width != matrix_a2->width)
        return NULL;

    matrix *matrix_b = matrix_alloc(matrix_a1->height, matrix_a1->width);

    if (!matrix_b)
        return NULL;

    size_t height = matrix_a1->height, width = matrix_a1->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_b, i, j)) = *(matrix_get_const(matrix_a1, i, j)) + *(matrix_get_const(matrix_a2, i, j));
    }

    return matrix_b;
}

/* Функция вычетает матрицу matrix_a2 из матрицы matrix_a1, записывая результат в матрицу matrix_a1.
 * Функция возвращает 1, если матрицы не были переданы или количество строк или столбцов у матриц не совпадает.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_subtract (matrix *matrix_a1, const matrix *matrix_a2)
{
    if (!matrix_a1 || !matrix_a2 || matrix_a1->height != matrix_a2->height || matrix_a1->width != matrix_a2->width)
        return 1;

    size_t height = matrix_a1->height, width = matrix_a1->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_a1, i, j)) = *(matrix_get_const(matrix_a1, i, j)) - *(matrix_get_const(matrix_a2, i, j));
    }

    return 0;
}

/* Функция вычетает матрицу matrix_a2 из матрицы matrix_a1, записывая результат в матрицу matrix_a.
 * Функция возвращает 1, если матрицы не были переданы или количество строк или столбцов у матриц не совпадает.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_subtract_three (const matrix *matrix_a1, const matrix *matrix_a2, matrix *matrix_a)
{
    if (!matrix_a || !matrix_a1 || !matrix_a2 || matrix_a1->height != matrix_a2->height || matrix_a1->width != matrix_a2->width ||
        matrix_a->height != matrix_a1->height || matrix_a->width != matrix_a1->width)
        return 1;

    size_t height = matrix_a1->height, width = matrix_a1->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_a, i, j)) = *(matrix_get_const(matrix_a1, i, j)) - *(matrix_get_const(matrix_a2, i, j));
    }

    return 0;
}

/* Функция создаёт матрицу matrix_b и вычетает матрицу matrix_a2 из матрицы matrix_a1, записывая результат в матрицу matrix_b.
 * Функция возвращает NULL, если матрицы matrix_a1 или matrix_a2 не были переданы, матрица matrix_b не создана
 * или количество строк или столбцов у матриц не совпадает.
 * Функция возвращает указатель на матрицу matrix_b в остальных случаях.
 */
matrix * matrix_alloc_subtract (const matrix *matrix_a1, const matrix *matrix_a2)
{
    if (!matrix_a1 || !matrix_a2 || matrix_a1->height != matrix_a2->height || matrix_a1->width != matrix_a2->width)
        return NULL;

    matrix *matrix_b = matrix_alloc(matrix_a1->height, matrix_a1->width);

    if (!matrix_b)
        return NULL;

    size_t height = matrix_a1->height, width = matrix_a1->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_b, i, j)) = *(matrix_get_const(matrix_a1, i, j)) - *(matrix_get_const(matrix_a2, i, j));
    }

    return matrix_b;
}

/* Функция умножает матрицу matrix_a на скаляр scalar, записывая результат в матрицу matrix_a1.
 * Функция возвращает 1, если матрица не была передана.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_multi_scalar (matrix *matrix_a, double scalar)
{
    if (!matrix_a)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_a, i, j)) = scalar * (*(matrix_get_const(matrix_a, i, j)));
    }

    return 0;
}

/* Функция умножает матрицу matrix_a1 на скаляр scalar, записывая результат в матрицу matrix_a.
 * Функция возвращает 1, если матрицы не были переданы или количество строк или столбцов у матриц не совпадает.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_multi_three_scalar (const matrix *matrix_a1, double scalar, matrix *matrix_a)
{
    if (!matrix_a || !matrix_a1 || matrix_a->height != matrix_a1->height || matrix_a->width != matrix_a1->width)
        return 1;

    size_t height = matrix_a1->height, width = matrix_a1->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_a, i, j)) = scalar * (*(matrix_get_const(matrix_a1, i, j)));
    }

    return 0;
}

/* Функция создаёт матрицу matrix_b и умножает матрицу matrix_a на скаляр scalar, записывая результат в матрицу matrix_b.
 * Функция возвращает NULL, если матрица matrix_a не была передана или матрица matrix_b не создана.
 * Функция возвращает указатель на матрицу matrix_b в остальных случаях.
 */
matrix * matrix_alloc_multi_scalar (const matrix *matrix_a, double scalar)
{
    if (!matrix_a)
        return NULL;

    matrix *matrix_b = matrix_alloc(matrix_a->height, matrix_a->width);

    if (!matrix_b)
        return NULL;

    size_t height = matrix_a->height, width = matrix_a->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            *(matrix_get(matrix_b, i, j)) = scalar * (*(matrix_get_const(matrix_a, i, j)));
    }

    return matrix_b;
}

/* Функция перемножает матрицы matrix_a1 и matrix_a2, записывая результат в матрицу matrix_a.
 * Функция возвращает 1, если матрицы не были переданы или количество столбцов матрицы matrix_a1
 * и строк матрицы matrix_a2, количество строк матриц matrix_a1 и matrix_a или количество столбцов
 * матриц matrix_a1 и matrix_a не совпадает.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_multi_three (const matrix *matrix_a1, const matrix *matrix_a2, matrix *matrix_a)
{
    if (!matrix_a || !matrix_a1 || !matrix_a2 || matrix_a1->width != matrix_a2->height ||
        matrix_a->height != matrix_a1->height || matrix_a->width != matrix_a2->width || matrix_a1 == matrix_a || matrix_a2 == matrix_a)
        return 1;

    size_t height = matrix_a1->height, width = matrix_a2->width, run_element = matrix_a1->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
        {
            *(matrix_get(matrix_a, i, j)) = 0;

            for (size_t t = 0; t < run_element; t ++)
                *(matrix_get(matrix_a, i, j)) += (*(matrix_get_const(matrix_a1, i, t))) * (*(matrix_get_const(matrix_a2, t, j)));
        }
    }

    return 0;
}

/* Функция создаёт матрицу matrix_b и перемножает матрицы matrix_a1 и matrix_a2, записывая результат в матрицу matrix_b.
 * Функция возвращает NULL, если матрицы не были переданы, матрица matrix_b не создана или количество столбцов матрицы matrix_a1
 * и строк матрицы matrix_a2, количество строк матриц matrix_a1 и matrix_a или количество столбцов
 * матриц matrix_a1 и matrix_a не совпадает.
 * Функция возвращает указатель на матрицу matrix_b в остальных случаях.
 */
matrix * matrix_alloc_multi (const matrix *matrix_a1, const matrix *matrix_a2)
{
    if (!matrix_a1 || !matrix_a2 || matrix_a1->width != matrix_a2->height)
        return NULL;

    matrix *matrix_b = matrix_alloc_zero(matrix_a1->height, matrix_a2->width);

    if (!matrix_b)
        return NULL;

    size_t height = matrix_a1->height, width = matrix_a2->width, run_element = matrix_a1->width;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
        {
            for (size_t t = 0; t < run_element; t ++)
                *(matrix_get(matrix_b, i, j)) += (*(matrix_get_const(matrix_a1, i, t))) * (*(matrix_get_const(matrix_a2, t, j)));
        }
    }

    double norm = matrix_norm(matrix_b);

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = 0; j < width; j ++)
            if (fabs(*(matrix_get_const(matrix_b, i, j)) / norm) < 1e-6)
                *(matrix_get(matrix_b, i, j)) = 0;
    }

    return matrix_b;
}

/* Функция вычисляет норму матрицы matrix_a как максимум сумм модулей элементов строк.
 * Функция возвращает -1, если матрица не была передана.
 * Функция возвращает неотрицательное вещественное число max_string в остальных случаях.
 */
double matrix_norm (const matrix *matrix_a)
{
    if (!matrix_a)
        return -1;

    size_t height = matrix_a->height, width = matrix_a->width;
    double max_string = 0, num_string;

    for (size_t i = 0; i < height; i ++)
    {
        num_string = 0;

        for (size_t j = 0; j < width; j ++)
            num_string += fabs(*(matrix_get_const(matrix_a, i, j)));

        max_string = fmax(num_string, max_string);
    }

    return max_string;
}

/* Функция производит транспозицию матрицы matrix_a, изменяя её.
 * Функция возвращает 1, если матрица не была передана или матрица не является квадратной.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_transpose (matrix *matrix_a)
{
    if (!matrix_a || matrix_a->height != matrix_a->width)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;
    double element;

    for (size_t i = 0; i < height; i ++)
    {
        for (size_t j = i + 1; j < width; j ++)
        {
            element = *(matrix_get(matrix_a, i, j));
            *(matrix_get(matrix_a, i, j)) = *(matrix_get(matrix_a, j, i));
            *(matrix_get(matrix_a, j, i)) = element;
        }
    }

    return 0;
}

/* Функция меняет местами строки i и j в матрице matrix_a.
 * Функция возвращает 1, если матрица не была передана или индексы i или j были больше количества строк матрицы.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_rearranging_strings (matrix *matrix_a, size_t i, size_t j)
{
    if (!matrix_a)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;
    double element;

    if (i > height || j > height)
        return 1;

    for (size_t t = 0; t < width; t ++)
    {
        element = *(matrix_get(matrix_a, i, t));
        *(matrix_get(matrix_a, i, t)) = *(matrix_get(matrix_a, j, t));
        *(matrix_get(matrix_a, j, t)) = element;
    }

    return 0;
}

/* Функция умножает i-ую строку в матрице matrix_a на скаляр scalar.
 * Функция возвращает 1, если матрица не была передана или индекс i был больше количества строк матрицы.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_multi_string_number (matrix *matrix_a, size_t i, double scalar)
{
    if (!matrix_a)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;

    if (i > height)
        return 1;

    for (size_t t = 0; t < width; t ++)
        *(matrix_get(matrix_a, i, t)) = scalar * (*(matrix_get(matrix_a, i, t)));

    return 0;
}

/* Функция прибавляет к строке i строку j, домноженную на скаляр scalar, в матрице matrix_a.
 * Функция возвращает 1, если матрица не была передана или индексы i или j были больше количества строк матрицы.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_sum_string_multi_number (matrix *matrix_a, size_t i, size_t j, double scalar)
{
    if (!matrix_a)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;

    if (i > height || j > height)
        return 1;

    for (size_t t = 0; t < width; t ++)
        *(matrix_get(matrix_a, i, t)) = *(matrix_get(matrix_a, i, t)) + scalar * (*(matrix_get(matrix_a, j, t)));

    return 0;
}

/* Функция меняет местами столбцы i и j в матрице matrix_a.
 * Функция возвращает 1, если матрица не была передана или индексы i или j были больше количества столбцов матрицы.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_rearranging_columns (matrix *matrix_a, size_t i, size_t j)
{
    if (!matrix_a)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;
    double element;

    if (i > width || j > width)
        return 1;

    for (size_t t = 0; t < height; t ++)
    {
        element = *(matrix_get(matrix_a, t, i));
        *(matrix_get(matrix_a, t, i)) = *(matrix_get(matrix_a, t, j));
        *(matrix_get(matrix_a, t, j)) = element;
    }

    return 0;
}

/* Функция умножает i-ый столбец в матрице matrix_a на скаляр scalar.
 * Функция возвращает 1, если матрица не была передана или индекс i был больше количества столбцов матрицы.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_multi_column_number (matrix *matrix_a, size_t i, double scalar)
{
    if (!matrix_a)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;

    if (i > width)
        return 1;

    for (size_t t = 0; t < height; t ++)
        *(matrix_get(matrix_a, t, i)) = scalar * (*(matrix_get(matrix_a, t, i)));

    return 0;
}

/* Функция прибавляет к столбцу i столбец j, домноженный на скаляр scalar, в матрице matrix_a.
 * Функция возвращает 1, если матрица не была передана или индексы i или j были больше количества столбцов матрицы.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_sum_column_multi_number (matrix *matrix_a, size_t i, size_t j, double scalar)
{
    if (!matrix_a)
        return 1;

    size_t height = matrix_a->height, width = matrix_a->width;

    if (i > width || j > width)
        return 1;

    for (size_t t = 0; t < height; t ++)
        *(matrix_get(matrix_a, t, i)) = *(matrix_get(matrix_a, t, i)) + scalar * (*(matrix_get(matrix_a, t, j)));

    return 0;
}

/* Функция вычисляет определитель квадратной матрицы matrix_a.
 * Функция возвращает NaN, если матрица matrix_a не была передана, промежуточная
 * матрица matrix_b не создана или матрица matrix_a на является квадратной.
 * Функция возвращает неотрицательное вещественное число в остальных случаях.
 */
double matrix_determinant (matrix *matrix_a)
{
    if (!matrix_a || matrix_a->height != matrix_a->width)
        return 0.0 / 0.0;

    matrix *matrix_b = matrix_copy(matrix_a);

    if (!matrix_b)
        return 0.0 / 0.0;

    size_t size_matrix = matrix_a->height;
    double element_t, determinant = 1, sign = 1;

    for (size_t t = 0; t < size_matrix; t ++)
    {
        if (!(*(matrix_get_const(matrix_b, t, t))))
        {
            int bool_have = 0;

            for (size_t j = t + 1; j < size_matrix; j ++)
            {
                if (*(matrix_get_const(matrix_b, j, t)))
                {
                    matrix_rearranging_strings(matrix_b, t, j);

                    sign *= (-1);

                    bool_have = 1;

                    break;
                }
            }

            if (!bool_have)
            {
                matrix_free(matrix_b);

                return 0;
            }
        }

        element_t = *(matrix_get_const(matrix_b, t, t));

        for (size_t i = t + 1; i < size_matrix; i ++)
        {
            if (*(matrix_get_const(matrix_b, i, t)))
                matrix_sum_string_multi_number(matrix_b, i, t, (-1) * (*(matrix_get_const(matrix_b, i, t))) / element_t);
        }

    }

    for (size_t i = 0; i < size_matrix; i ++)
        determinant *= *(matrix_get_const(matrix_b, i, i));

    matrix_free(matrix_b);

    return sign * determinant;
}
