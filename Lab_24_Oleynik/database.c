/* Laboratory work 24.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 * The module processes a database of exoplanets.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "database.h"

database * database_alloc ()
{
    database *base = malloc(sizeof(database));

    if (!base)
        return NULL;

    base->min_capacity = 10;
    base->capacity = base->min_capacity;
    base->size_base = 0;
    base->element = NULL;

    if (database_resize(base->capacity, base))
        return NULL;

    return base;
}

void database_free (database *base)
{
    if (!base)
        return;

    for (int i = 0; i < base->size_base; i ++)
        if (!(get_element(i, base)->name))
            free(get_element(i, base)->name);
    free(base->element);
    free(base);
}

int database_resize (size_t capacity, database *base)
{
    if (!base)
        return 1;

    data *element_clone = (data*)(realloc(base->element, capacity * sizeof(data)));

    if (!element_clone)
        return 1;

    base->element = element_clone;
    base->capacity = capacity;

    return 0;
}

int database_incert (database *base, const data *element)
{
    if (!base)
        return 1;

    if ((base->size_base + 1) >= base->capacity - 1)
        if (database_resize(2 * base->capacity, base))
            return 1;

    if (!element->name)
        return 1;

    char *name = malloc(strlen(element->name) * sizeof(char));

    strcpy(name, element->name);

    memcpy((char*)(base->element + base->size_base), (const char*)(element), sizeof(data));

    base->size_base ++;

    get_element(base->size_base - 1, base)->name = name;

    return 0;
}

int database_delete_element (database *base, size_t num)
{
    free(get_element(num, base)->name);

    memcpy((void*)(base->element + num), (void*)(base->element + num + 1), (base->size_base - num - 1) * sizeof(data));

    if ((base->size_base --) < base->capacity / 4 && base->capacity / 4 > base->min_capacity)
        if (database_resize(base->capacity / 4, base))
            return 1;

    return 0;
}

int database_delete (database *base, size_t num)
{
    if (!base || num > base->size_base)
        return 1;

    if (base->size_base > 0)
    {
        if (num)
        {
            if(database_delete_element(base, num - 1))
                return 1;
        }
        else
            for (int i = 0, e = base->size_base; i < e; i ++)
                if(database_delete_element(base, 0))
                    return 1;
    }

    return 0;
}

data * get_element (size_t i, database *base)
{
    if (!base || i >= base->size_base || i < 0)
        return NULL;

    return base->element + i;
}

const data * get_element_const (size_t i, const database *base)
{
    if (!base || i >= base->size_base)
        return NULL;

    return base->element + i;
}

int read_file (char *file_name, database *base)
{
    FILE *f = fopen(file_name, "r");
    if (!f || !base)
        return 1;

    data b;
    char type[14];

    b.name = malloc(30 * sizeof(char));

    while(fgets(b.name, 30, f))
    {
        b.name[strlen(b.name) - 1] = '\0';

        if(fscanf(f, "%d%lf%lf%d", &b.year_open, &b.mass, &b.radius, &b.light_year) != 4)
        {
            free(b.name);

            fclose(f);

            return 1;
        }

        fgets(type, 2, f);

        if (!fgets(type, 14, f))
        {
            free(b.name);

            fclose(f);

            return 1;
        }

        type[strlen(type) - 1] = '\0';

        if (!strcmp(type, "Gas giant"))
            b.type = T_GAS_GIANT;
        else if (!strcmp(type, "Neptune like"))
            b.type = T_NEPTUNE_LIKE;
        else if (!strcmp(type, "Super Earth"))
            b.type = T_SUPER_EARTH;
        else if (!strcmp(type, "Terrestrial"))
            b.type = T_TERRESTRIAL;
        else if (!strcmp(type, "Unknown"))
            b.type = T_UNKNOWN;
        else
        {
            free(b.name);

            fclose(f);

            return 1;
        }

        if (database_incert(base, &b))
        {
            free(b.name);

            fclose(f);

            return 1;
        }
    }

    free(b.name);

    fclose(f);

    return 0;
}

int output_file (char *file_name, database *base)
{
    if (!base || !base->size_base)
        return 1;

    FILE *f = fopen(file_name, "w");
    if (!f)
        return 1;

    char type[13];

    for (data *i = get_element(0, base), *e = get_element(base->size_base - 1, base); i <= e; i ++)
    {
        switch (i->type)
        {
            case T_GAS_GIANT:
                strcpy(type, "Gas giant");
                break;

            case T_NEPTUNE_LIKE:
                strcpy(type, "Neptune like");
                break;

            case T_SUPER_EARTH:
                strcpy(type, "Super Earth");
                break;

            case T_TERRESTRIAL:
                strcpy(type, "Terrestrial");
                break;

            case T_UNKNOWN:
                strcpy(type, "Unknown");
                break;
        }

        fprintf(f, "%s\n%d %f %f %d\n%s\n", i->name, i->year_open, i->mass, i->radius, i->light_year, type);
    }

    fclose(f);

    return 0;
}

int q_sort (database *base, comparison f)
{
    if (!base || !f)
        return 1;

    data **stack_r, **stack_l;
    size_t size_stack = 1;
    data *right, *left;

    stack_r = malloc((base->size_base + 1) * sizeof(data*));
    stack_l = malloc((base->size_base + 1) * sizeof(data*));

    *(stack_r + size_stack) = base->element + base->size_base - 1;
    *(stack_l + size_stack) = base->element;

    while (size_stack)
    {
        right = *(stack_r + size_stack);
        left = *(stack_l + size_stack);
        size_stack --;

        while (left < right)
        {
            data *i = left, *j = right, *mid = malloc(sizeof(data));

            memcpy(mid, left + (right - left) / 2, sizeof(data));

            while (i < j)
            {
                while (f(i, mid) == 1)
                    i ++;

                while (f(mid, j) == 1)
                    j --;

                if (i <= j)
                {
                    data per;

                    memcpy(&per, i, sizeof(data));
                    memcpy(i, j, sizeof(data));
                    memcpy(j, &per, sizeof(data));

                    i ++, j --;
                }
            }

            if (i < right)
            {
                size_stack ++;
                *(stack_r + size_stack) = right;
                *(stack_l + size_stack) = i;
            }

            right = j;

            free(mid);
        }
    }

    free(stack_r);
    free(stack_l);

    return 0;
}

data * found_max_element (database *base, comparison f)
{
    if (!base || !base->size_base)
        return NULL;

    data *max_el = get_element(0, base);

    for (data *i = get_element(0, base), *e = get_element(base->size_base - 1, base); i <= e; i ++)
        if (f(max_el, i) == 1)
            max_el = i;

    return max_el;
}
