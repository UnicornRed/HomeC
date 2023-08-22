#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "f_analysis.h"

enum fun f_analysis_f (double a, double b, double c, double *x1, double *x2)
{
    if (a != a || b != b || c != c || fabs(a) == 1.0 / 0.0 || fabs(b) == 1.0 / 0.0 || fabs(c) == 1.0 / 0.0)
        return FUN_NOCOEF;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                return FUN_INFROOT;
            else
                return FUN_NOROOT;
        }
        else
        {
            if (x1) *x1 = -c / b;
            return FUN_LINE;
        }
    }
    else
    {
        double dis = b * b - 4 * a * c;
        if (dis < 0)
            return FUN_TWO_C;
        else if (dis == 0)
        {
            if (x1) *x1 = -b / (2 * a);
            return FUN_ONE_R;
        }
        else
        {
            double sqrtdis = sqrt(dis);
            if (x1) *x1 = (-b - sqrtdis) / (2 * a);
            if (x1) *x2 = (-b + sqrtdis) / (2 * a);
            return FUN_TWO_R;
        }
    }
}
