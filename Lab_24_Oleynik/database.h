#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

/* An enumerated data type that indicates the type of exoplanet.
 */
enum type_planet {T_GAS_GIANT, T_NEPTUNE_LIKE, T_SUPER_EARTH, T_TERRESTRIAL, T_UNKNOWN};

typedef enum type_planet type_planet;

/* A structure containing information about an exoplanet.
 * name - name of exoplanet.
 * year_open - year of the discovery of the exoplanet.
 * light_year - distance to the exoplanet.
 * mass - mass of exoplanet.
 * radius - radius of exoplanet.
 */
struct data
{
    int year_open, light_year;
    double mass, radius;
    char *name;
    type_planet type;
};

typedef struct data data;

/* A structure containing information about the exoplanet database.
 * element - pointer to the database elements.
 * min_capacity - the minimum capacity of the base.
 * capacity - current capacity of the base.
 * size_base - current size of the database.
 */
struct database
{
    data *element;
    size_t min_capacity;
    size_t capacity;
    size_t size_base;
};

typedef struct database database;

/* Alias of the database element comparison function.
 */
typedef int (*comparison) (const data *, const data *);

/* The function allocates memory for the database.
 * The function returns NULL if no memory has been allocated.
 * The function returns a pointer to the database in all other cases.
 */
database * database_alloc ();

/* The function frees up the memory allocated for the database "base".
 */
void database_free (database *base);

/* The function changes the database (base) capacity value to "capacity".
 * The function returns 1 if the base was not passed or the capacity was not changed.
 * The function returns 0 in all other cases.
 */
int database_resize (size_t capacity, database *base);

/* The function adds the value of the "element" to the database "base".
 * The function returns 1 if the base was not passed or the capacity was not changed when the size was increased, if necessary.
 * The function returns 0 in all other cases.
 */
int database_incert (database *base, const data *element);

/* The function removes an element (index - num) from the database "base".
 * The function returns 1 if the function was not passed, the index did not belong to the base,
 * or the capacity was not changed when the size was reduced, if necessary.
 * The function returns 0 in all other cases.
 */
int database_delete (database *base, size_t num);

/* The function gets the element (index - num) from the database "base".
 * The function returns NULL if the index does not belongs to the base.
 * The function returns a pointer to the element in all other cases.
 */
data * get_element (size_t i, database *base);

/* The function gets the constant element (index - num) from the database "base".
 * The function returns NULL if the index does not belongs to the base.
 * The function returns a constant pointer to the element in all other cases.
 */
const data * get_element_const (size_t i, const database *base);

/* The function enters the database "base" from a file named "file_name".
 * The function returns 1 if the base was not passed, the file was not found,
 * an error occurred while reading, or the element was not inserted.
 * The function returns 0 in all other cases.
 */
int read_file (char *file_name, database *base);

/* The function outputs the database "base" to a file named "file_name".
 * The function returns 1 if the database was not transferred, the file was not opened, or the size of the database is 0.
 * The function returns 0 in all other cases.
 */
int output_file (char *file_name, database *base);

/* The function sorts the database "base" using the comparison function "f".
 * The function returns 1 if the database or function was not passed.
 * The function returns 0 in all other cases.
 */
int q_sort (database *base, comparison f);

/* The function finds the maximum element in the database "base" using the comparison function "f".
 * The function returns NULL if the database or function was not passed.
 * The function returns a pointer to the maximum element in all other cases.
 */
data * found_max_element (database *base, comparison f);

#endif // DATABASE_H_INCLUDED
