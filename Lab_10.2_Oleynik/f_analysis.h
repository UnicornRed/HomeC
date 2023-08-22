#ifndef F_ANALYSIS_H_INCLUDED
#define F_ANALYSIS_H_INCLUDED

/* Тип данных, обозначающий состояния квадратного уравнения
 * twoR - имеется два вещественных корня;
 * oneR - имеется один кратный корень;
 * twoC - имеется два комплексных корня;
 * line - уравнение линейного вида;
 * noroot - нет корней;
 * infroot - бесконечное количество корней;
 * nocoef - хотя бы один коэффициент равен бесконечности или NaN.
 */
enum fun {FUN_TWO_R, FUN_ONE_R, FUN_TWO_C, FUN_LINE, FUN_NOROOT, FUN_INFROOT, FUN_NOCOEF};

/* Функция, анализирующая квадратное уравнение по коэффициентам и, по возможности, вычисляющая его корни
 * a, b, c - коэффициенты квадратного уравнения;
 * x1 и x2 - корни квадратного уравнения;
 * функция возвращает анализ функции в виде одного из значений типа данных fun.
 */
enum fun f_analysis_f (double a, double b, double c, double *x1, double *x2);

#endif // F_ANALYSIS_H_INCLUDED
