#ifndef COMPARISON_FUN_H_INCLUDED
#define COMPARISON_FUN_H_INCLUDED

#include "database.h"

/* The function compares two elements "a" and "b" by field "light_year" .
 * The function returns 1 if the first element is smaller than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is greater than the second.
 */
int comp_light_year_up (const data *a, const data *b);

/* The function compares two elements "a" and "b" by field "year_open" .
 * The function returns 1 if the first element is smaller than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is greater than the second.
 */
int comp_year_open_up (const data *a, const data *b);

/* The function compares two elements "a" and "b" by field "mass" .
 * The function returns 1 if the first element is smaller than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is greater than the second.
 */
int comp_mass_up (const  data *a, const data *b);

/* The function compares two elements "a" and "b" by field "radius" .
 * The function returns 1 if the first element is smaller than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is greater than the second.
 */
int comp_radius_up (const data *a, const data *b);

/* The function compares two elements "a" and "b" by field "name" .
 * The function returns 1 if the first element is smaller than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is greater than the second.
 */
int comp_name_up (const data *a, const data *b);

/* The function compares two elements "a" and "b" by field "type" .
 * The function returns 1 if the first element is smaller than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is greater than the second.
 */
int comp_type_up (const data *a, const data *b);

/* The function compares two elements "a" and "b" by field "light_year" .
 * The function returns 1 if the first element is greater than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is smaller than the second.
 */
int comp_light_year_down (const data *a, const data *b);

/* The function compares two elements "a" and "b" by field "year_open" .
 * The function returns 1 if the first element is greater than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is smaller than the second.
 */
int comp_year_open_down (const data *a, const data *b);

/* The function compares two elements "a" and "b" by field "mass" .
 * The function returns 1 if the first element is greater than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is smaller than the second.
 */
int comp_mass_down (const  data *a, const data *b);

/* The function compares two elements "a" and "b" by field "radius" .
 * The function returns 1 if the first element is greater than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is smaller than the second.
 */
int comp_radius_down (const data *a, const data *b);

/* The function compares two elements "a" and "b" by field "name" .
 * The function returns 1 if the first element is greater than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is smaller than the second.
 */
int comp_name_down (const data *a, const data *b);

/* The function compares two elements "a" and "b" by field "type" .
 * The function returns 1 if the first element is greater than the second.
 * The function returns 0 if the first element is equal to the second.
 * The function returns -1 if the first element is smaller than the second.
 */
int comp_type_down (const data *a, const data *b);

#endif // COMPARISON_FUN_H_INCLUDED
