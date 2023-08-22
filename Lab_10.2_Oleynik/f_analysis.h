#ifndef F_ANALYSIS_H_INCLUDED
#define F_ANALYSIS_H_INCLUDED

/* ��� ������, ������������ ��������� ����������� ���������
 * twoR - ������� ��� ������������ �����;
 * oneR - ������� ���� ������� ������;
 * twoC - ������� ��� ����������� �����;
 * line - ��������� ��������� ����;
 * noroot - ��� ������;
 * infroot - ����������� ���������� ������;
 * nocoef - ���� �� ���� ����������� ����� ������������� ��� NaN.
 */
enum fun {FUN_TWO_R, FUN_ONE_R, FUN_TWO_C, FUN_LINE, FUN_NOROOT, FUN_INFROOT, FUN_NOCOEF};

/* �������, ������������� ���������� ��������� �� ������������� �, �� �����������, ����������� ��� �����
 * a, b, c - ������������ ����������� ���������;
 * x1 � x2 - ����� ����������� ���������;
 * ������� ���������� ������ ������� � ���� ������ �� �������� ���� ������ fun.
 */
enum fun f_analysis_f (double a, double b, double c, double *x1, double *x2);

#endif // F_ANALYSIS_H_INCLUDED
