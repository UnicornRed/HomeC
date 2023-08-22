#ifndef MATRIX_PROCESSING_H_INCLUDED
#define MATRIX_PROCESSING_H_INCLUDED

/* Функция находит обратную матрицу кваднратной матрицы matrix_a.
 * Функция возвращает NULL, если матрица не была передана, она не квадратна,
 * вспомогательная матрица matrix_b не сооздана или определитель матрицы равен 0.
 * Функция возвращает указатель на матрицу matrix_rev в остальных случаях.
 */
matrix * matrix_reverse (const matrix *matrix_a);

/* Функция вычисляет матричную экспоненту от матрицы matrix_a с погрешностью e.
 * Функция возвращает NULL, если матрица не была передана, она не квадратна, вспомогательные
 * матрицы matrix_b, matrix_exp_sol или matrix_c не созданы или возникла ошибка в функциях
 * matrix_sum, matrix_assign, matrix_multi_scalar или matrix_norm.
 * Функция возвращает указатель на матрицу matrix_exp_sol в остальных случаях.
 */
matrix * matrix_exp (const matrix *matrix_a, const double e);

/* Функция проверяет решение matrix_sol на матрице СЛУ matrix_a с погрешностью e.
 * Функция возвращает -1, если матрицы не были переданы, произошла ошибка в функции matrix_norm или количество строк
 * и количество столбцов минус 1 матрицы matrix_a или количество строк матриц matrix_a и matrix_sol не совпадает.
 * Функция возвращает 1, если матрица matrix_sol не является решением.
 * Функция возвращает 0 в остальных случаях.
 */
int matrix_gauss_test (const matrix *matrix_a, const matrix *matrix_sol, const double e);

/* Функция решает СЛУ, заданную матрицей matrix_a.
 * Функция возвращает NULL, если матрица не была передана, вспомогательная матрица matrix_b не создана,
 * бесконечное количество решений или решений нет.
 * Функция возвращает указатель на матрицу matrix_sol в остальных случаях.
 */
matrix * matrix_gauss_solution (const matrix *matrix_a);

#endif // MATRIX_PROCESSING_H_INCLUDED
