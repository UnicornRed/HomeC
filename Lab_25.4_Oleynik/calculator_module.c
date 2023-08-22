/* Laboratory work 25.4.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 * The module treats the string as an arithmetic expression in the Polish notation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "calc.h"

#define PI 3.1415926
#define EXP 2.7182818

/* The string for an integrable function.
 */
char fun[100];

void reminder ()
{
    printf("List of calculator commands:\n"
           "pi - 3.1415926;\n"
           "e - 2.7182818;\n"
           "+ - addition;\n"
           "- - subtraction;\n"
           "* - multiplication;\n"
           "/ - division;\n"
           "^- exponentiation;\n"
           "-- - unary minus;\n"
           "rev - reverse number;\n"
           "sq - square root;\n"
           "exp - exponential function;\n"
           "ln - natural logarithm;\n"
           "lg - decimal logarithm;\n"
           "log - logarithm (the first number is the base of the logarithm);\n"
           "sin - sine;\n"
           "cos - cosine;\n"
           "tg - tangent;\n"
           "ctg - cotangent;\n"
           "sh - hyperbolic sine;\n"
           "ch - hyperbolic cosine;\n"
           "th - hyperbolic tangent;\n"
           "cth - hyperbolic cotangent;\n"
           "asin - inverse sine;\n"
           "acos - inverse cosine;\n"
           "atg - inverse tangent;\n"
           "actg - inverse cotangent;\n"
           "ash - inverse hyperbolic sine;\n"
           "ach - inverse hyperbolic cosine;\n"
           "ath - inverse hyperbolic tangent;\n"
           "acth - inverse hyperbolic cotangent;\n"
           "armean2 - arithmetic mean of two numbers;\n"
           "armean - arithmetic mean of n numbers (the last number is the quantity of numbers);\n"
           "sqdev - mean square deviation (the last number is the quantity of numbers);\n"
           "integ - integral (the first number is the number of partitions of the segment,\n"
           "the second number is the beginning of the segment, and the third number is the end.);\n"
           "{...} - integrated function;\n\n");
}

int input_str (char *str, size_t max_size)
{
    if (!str)
        return 1;

    char letter;
    int counter = 0;

    do
    {
        if (counter > max_size - 2)
            return 1;

        letter = getchar();

        str[counter] = letter;

        counter ++;
    } while (letter != '\n');

    str[counter - 1] = '\0';

    return 0;
}

/* The function copies part of the string "str" to the string "fun" before the character '}'.
 * The function returns 0 if the character '}' was not encountered.
 * The function returns the length of the string in all other cases.
 */
int str_fun (const char *str)
{
    const char *i = str;

    while (*i != '}' && *i != '\0')
    {
        *(fun + (i - str)) = *i;
        i ++;

        if (i - str > 99)
            return 0;
    }

    if (*i != '}')
        return 0;

    *(fun + (i - str)) = '\0';

    return (int)(i - str);
}

/* The function selects the first word from the string "str" using a string of delimiters "dec".
 * error - error message.
 * The function returns 0 if no strings were passed, the word had a character '{' but no character '}', or the passed string was null.
 * The function returns a pointer to the word in other cases.
 */
char * my_strtok (char *str, const char *dec, int *error)
{
    if  (!str || !dec)
        return NULL;

    if (*str == '{')
    {
        int next_flag;

        str ++;

        if (!(next_flag = str_fun(str)))
        {
            if (error)
                *error = 2;

            return NULL;
        }

        str += next_flag + 1;
    }

    char *begin = str, *end;

    while (strchr(dec, *begin) && *begin != '\0')
        begin ++;

    end = begin;

    while (!(strchr(dec, *end)) && *end != '\0')
        end ++;

    if (begin == end)
        return NULL;

    *end = '\0';

    return begin;
}

/* The function substitutes a number "num" instead of a character 'x' in the string "str".
 * The function returns 1 if the number is NaN or infinity.
 * The function returns 0 in all other cases.
 */
int substitution (double num, char *str)
{
    if (num != num || fabs(num) == 1.0 / 0.0)
        return 1;

    strcpy(str, fun);

    char *i = str, buf[100], num_str[11];
    int count_int = 0, count_real = 5, num_copy, bool_minus = 0;

    if (num < 0)
    {
        count_int ++;
        num = fabs(num);
        num_str[0] = '-';
        bool_minus = 1;
    }

    int num_int = (int)num, num_real = (int)((num - (int)num) * 100000);

    num_copy = num_int;

    while (num_copy)
    {
        count_int ++;
        num_copy /= 10;
    }

    count_int = count_int - bool_minus ? count_int : bool_minus + 1;

    char *j = num_str + count_int - 1;

    for (int t = count_int - bool_minus; t; t --)
    {
        *j = (char)(num_int % 10 + 48);
        num_int /= 10;
        j --;
    }

    j = num_str + count_int;
    *j = '.';
    j += count_real;

    for (; count_real; count_real --)
    {
        *j = (char)(num_real % 10 + 48);
        num_real /= 10;
        j --;
    }

    j = num_str + count_int + 6;
    *j = '\0';

    while (*i != '\0')
    {
        if (*i == 'x')
        {
            strcpy(buf, i + 1);
            *i = '\0';
            strcat(str, num_str);
            *(i + strlen(num_str)) = '\0';
            strcat(i + strlen(num_str), buf);
        }

        i ++;
    }

    return 0;
}

/* The function converts a string "str" to a number.
 * The function returns NaN if the string cannot be converted to a number.
 * The function returns the converted number in all other cases.
 */
double string_to_double (char *str)
{
    double a = 0;
    char *j = str;
    int flag_point = 0, flag_sing = 0, place = 10;

    if (*j == '\0')
        return 0.0 / 0.0;

    while (*j != '\0')
    {
        if ((*j < '0' && (*j != '.' || flag_point) && (*j != '-' || flag_sing || (j != str && *j == '-'))) || *j > '9')
            return 0.0 / 0.0;

        if (*j == '-')
            flag_sing = 1;
        else if (*j == '.')
            flag_point = 1;
        else
        {
            if (flag_point)
                a = a + (double)((int)(*j) - (int)('0')) / place, place *= 10;
            else
                a = a * 10 + (int)(*j) - (int)('0');
        }

        j ++;
    }

    if (flag_sing)
        a *= (-1);

    return a;
}

/* The function calculates the arithmetic mean of "n" numbers.
 * The function returns NaN if there were less than "n" numbers in the stack "s".
 * The function returns a number in all other cases.
 */
double armean (Stack *s, int n)
{
    double x, sum = 0;

    for (int i = 0; i < n; i ++)
    {
        if (stack_delete(s, &x))
            return 0.0 / 0.0;

        sum += x;
    }

    return sum / n;
}

/* The function calculates the average square of "n" numbers.
 * The function returns a non-number if there were less than "n" numbers in the stack "s".
 * The function returns a number in all other cases.
 */
double sqdev (Stack *s, int n)
{
    double x, sum = 0, result = 0;
    Stack s_p;

    stack_alloc(&s_p);

    for (int i = 0; i < n; i ++)
    {
        if (stack_delete(s, &x))
        {
            stack_free(&s_p);

            return 0.0 / 0.0;
        }

        if (stack_insert(&s_p, x))
        {
            stack_free(&s_p);

            return 0.0 / 0.0;
        }

        sum += x;
    }

    sum = sum / n;

    for (int i = 0; i < n; i ++)
    {
        if (stack_delete(&s_p, &x))
        {
            stack_free(&s_p);

            return 0.0 / 0.0;
        }

        result += (x - sum) * (x - sum);
    }

    return sqrt(result / n);
}

/* The function calculates a certain integral on the interval ["a", "b"].
 * The function returns NaN if there was no number in the stack "s" or an error occurred during the substitution.
 * The function returns a number in all other cases.
 */
double integ (Stack *s, double a, double b)
{
    if (b < a || *fun == '\0')
        return 0.0 / 0.0;

    char str[1000];
    int error = 0;
    double num;

    if (stack_delete(s, &num))
        return 0.0 / 0.0;

    double solve_int = 0, step = (b - a) / (int)(num - 1);

    for (int i = 0; i < (int)(num - 1); i ++)
    {
        if (substitution(a + step / 2, str))
            return 0.0 / 0.0;

        solve_int += calculate(str, &error) * step;
        a += step;
    }

    return solve_int;
}

/* The function calculates the value of the operation passed in the string "token".
 * The function returns 2 if there was no number in the stack "s".
 * The function returns 3 if it is not possible to add a number to the stack "s".
 * The function returns 4 if the result of the operation is undefined.
 * The function returns 0 in all other cases.
 */
int oper (Stack *s, char *token)
{
    if (!(strcmp(token, "pi")))
    {
        if (stack_insert(s, PI))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "e")))
    {
        if (stack_insert(s, EXP))
            return 3;

        return 0;
    }

    double x1, x2;

    if (stack_delete(s, &x1))
        return 2;

    if (!(strcmp(token, "--")))
    {
        if (stack_insert(s, (-1.0) * x1))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "rev")))
    {
        if (x1 == 0.0)
            return 4;

        if (stack_insert(s, 1.0 / x1))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "sq")))
    {
        if (x1 < 0.0)
            return 4;

        if (stack_insert(s, sqrt(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "exp")))
    {
        if (stack_insert(s, pow(EXP, x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "ln")))
    {
        if (x1 <= 0.0)
            return 4;

        if (stack_insert(s, log(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "lg")))
    {
        if (x1 <= 0.0)
            return 4;

        if (stack_insert(s, log10(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "sin")))
    {
        if (stack_insert(s, sin(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "cos")))
    {
        if (stack_insert(s, cos(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "tg")))
    {
        if (tan(x1) != tan(x1))
            return 4;

        if (stack_insert(s, tan(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "ctg")))
    {
        if (tan(x1) == 0)
            return 4;


        if (stack_insert(s, 1.0 / tan(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "sh")))
    {
        if (stack_insert(s, sinh(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "ch")))
    {
        if (stack_insert(s, cosh(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "th")))
    {
        if (stack_insert(s, tanh(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "cth")))
    {
        if (x1 == 0.0)
            return 4;

        if (stack_insert(s, 1.0 / tanh(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "asin")))
    {
        if (asin(x1) != asin(x1))
            return 4;

        if (stack_insert(s, asin(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "acos")))
    {
        if (acos(x1) != acos(x1))
            return 4;

        if (stack_insert(s, acos(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "atg")))
    {
        if (stack_insert(s, atan(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "actg")))
    {
        if (stack_insert(s, PI / 2 - atan(x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "ash")))
    {
        if (stack_insert(s, log(x1 + sqrt(x1 * x1 + 1))))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "ach")))
    {
        if (x1 < 1)
            return 4;

        if (stack_insert(s, log(x1 + sqrt(x1 * x1 - 1))))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "ath")))
    {
        if (fabs(x1) >= 1)
            return 4;

        if (stack_insert(s, 0.5 * log((1 + x1) / (1 - x1))))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "acth")))
    {
        if (fabs(x1) <= 1)
            return 4;

        if (stack_insert(s, 1.0 / 0.5 * log((x1 - 1) / (x1 + 1))))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "armean")))
    {
        if ((double)((int)x1) != x1 || x1 < 1.0)
            return 4;

        x1 = armean(s, (int)x1);

        if (x1 != x1)
            return 2;

        if (stack_insert(s, x1))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "sqdev")))
    {
        if ((double)((int)x1) != x1 || x1 < 1.0)
            return 4;

        x1 = sqdev(s, (int)x1);

        if (x1 != x1)
            return 2;

        if (stack_insert(s, x1))
            return 3;

        return 0;
    }

    if (stack_is_empty(s))
        return 2;

    if (stack_delete(s, &x2))
        return 2;

    if (!(strcmp(token, "+")))
    {
        if (stack_insert(s, x1 + x2))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "-")))
    {
        if (stack_insert(s, x2 - x1))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "*")))
    {
        if (stack_insert(s, x2 * x1))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "/")))
    {
        if (stack_insert(s, x2 / x1))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "^")))
    {
        if (stack_insert(s, pow(x2, x1)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "log")))
    {
        if (x1 <= 0.0 || x2 <= 0 || x2 == 1.0)
            return 4;

        if (stack_insert(s, log(x1) / log(x2)))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "armean2")))
    {
        if (stack_insert(s, (x1 + x2) / 2))
            return 3;

        return 0;
    }

    if (!(strcmp(token, "integ")))
    {
        x1 = integ(s, x2, x1);

        if (x1 != x1)
            return 2;

        if (stack_insert(s, x1))
            return 3;

        return 0;
    }

    return 2;
}

double calculate (char *str_calc, int *error)
{
    if (!str_calc)
    {
        *error = 1;

        return 0.0 / 0.0;
    }

    char *token = str_calc;
    double num, result = 0;
    Stack s;
    size_t len_str = 0, size_str = strlen(str_calc);

    if (stack_alloc(&s))
    {
        *error = 1;

        return 0.0 / 0.0;
    }

    while (size_str >= token - str_calc + len_str)
    {
        token = my_strtok(token + len_str, " \n", error);

        if (*error == 2)
        {
            stack_free(&s);

            return 0.0 / 0.0;
        }

        if (!token)
            break;

        if ((*token >= '0' && *token <= '9') || (*token == '-' && *(token + 1) >= '0' && *(token + 1) <= '9'))
        {
            num = string_to_double(token);

            if (num != num)
            {
                *error = 2;

                stack_free(&s);

                return 0.0 / 0.0;
            }

            if (stack_insert(&s, num))
            {
                *error = 3;

                stack_free(&s);

                return 0.0 / 0.0;
            }
        }
        else
        {
            if ((*error = oper(&s, token)))
            {
                stack_free(&s);

                return 0.0 / 0.0;
            }
        }

        len_str = strlen(token) + 1;
    }

    if (s.top->prev)
    {
        *error = 2;

        stack_free(&s);

        return 0.0 / 0.0;
    }

    *error = 0;

    result = s.top->data;

    stack_free(&s);

    return result;
}
