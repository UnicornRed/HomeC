/* Laboratory work 24.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 * The module contains functions for comparing the fields of the exoplanet structure.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "comparison_fun.h"

int comp_light_year_up (const data *a, const data *b)
{
    if (a->light_year < b->light_year)
        return 1;
    else if (a->light_year == b->light_year)
        return 0;
    else
        return -1;
}

int comp_year_open_up (const data *a, const data *b)
{
    if (a->year_open < b->year_open)
        return 1;
    else if (a->year_open == b->year_open)
        return 0;
    else
        return -1;
}

int comp_mass_up (const data *a, const data *b)
{
    if (a->mass < b->mass)
        return 1;
    else if (a->mass == b->mass)
        return 0;
    else
        return -1;
}

int comp_radius_up (const data *a, const data *b)
{
    if (a->radius < b->radius)
        return 1;
    else if (a->radius == b->radius)
        return 0;
    else
        return -1;
}

int comp_name_up (const data *a, const data *b)
{
    if (strcmp(a->name, b->name) == -1)
        return 1;
    else if (strcmp(a->name, b->name) == 0)
        return 0;
    else
        return -1;
}

int comp_type_up (const data *a, const data *b)
{
    if (a->type < b->type)
        return 1;
    else if (a->type == b->type)
        return 0;
    else
        return -1;
}

int comp_light_year_down (const data *a, const data *b)
{
    if (a->light_year > b->light_year)
        return 1;
    else if (a->light_year == b->light_year)
        return 0;
    else
        return -1;
}

int comp_year_open_down (const data *a, const data *b)
{
    if (a->year_open > b->year_open)
        return 1;
    else if (a->year_open == b->year_open)
        return 0;
    else
        return -1;
}

int comp_mass_down (const data *a, const data *b)
{
    if (a->mass > b->mass)
        return 1;
    else if (a->mass == b->mass)
        return 0;
    else
        return -1;
}

int comp_radius_down (const data *a, const data *b)
{
    if (a->radius > b->radius)
        return 1;
    else if (a->radius == b->radius)
        return 0;
    else
        return -1;
}

int comp_name_down (const data *a, const data *b)
{
    if (strcmp(a->name, b->name) == 1)
        return 1;
    else if (strcmp(a->name, b->name) == 0)
        return 0;
    else
        return -1;
}

int comp_type_down (const data *a, const data *b)
{
    if (a->type > b->type)
        return 1;
    else if (a->type == b->type)
        return 0;
    else
        return -1;
}
