#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

/* The function prints a reminder of the operations recognized by the calculator.
 */
void reminder ();

/* The function enters a string "str" with a maximum length of "max_size" up to the line break character.
 * The function returns 1 if the string was not passed.
 * The function returns 0 in all other cases.
 */
int input_str (char *str, size_t max_size);

/* The function evaluates the value of the arithmetic expression passed in the string "str_calc".
 * error - error message:
 * 0 - no error;
 * 1 - error passing the pointer;
 * 2 - memory error;
 * 3 - string format error;
 * 4 - operation behavior error.
 * The function returns the calculated number.
 */
double calculate (char *str_calc, int *error);

#endif // CALC_H_INCLUDED
