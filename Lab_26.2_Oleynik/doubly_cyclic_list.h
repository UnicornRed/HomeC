#ifndef DOUBLY_CYCLIC_LIST_H_INCLUDED
#define DOUBLY_CYCLIC_LIST_H_INCLUDED

/* The structure describes an element of a doubly linked list.
 * data - value of the element;
 * next - pointer to the next element
 * prev - pointer to the previous element
 */
struct element
{
    int data;
    struct element *next, *prev;
};

typedef struct element element;

/* The structure describes a doubly linked cyclic list.
 * actual - pointer to the current element;
 * num - number of elements.
 */
struct cyclic_list
{
    element *actual;
    size_t num;
};

typedef struct cyclic_list cyclic_list;

/* The function processes an array of lists through user-defined commands.
 * The function returns 1 if a read error occurred.
 * The function returns 0 in all other cases.
 */
int list_interface ();

/* The function initializes the list "head".
 * The function returns 1 if no pointer to the list was passed.
 * The function returns 0 in all other cases.
 */
int list_alloc (cyclic_list *head);

/* The function moves the list pointer "head" to the next element.
 * The function returns 1 if no pointer to the list was passed or the list is empty.
 * The function returns 0 in all other cases.
 */
int list_to_next (cyclic_list *head);

/* The function moves the list pointer "head" to the previous element.
 * The function returns 1 if the pointer to the list was not passed or the list is empty.
 * The function returns 0 in all other cases.
 */
int list_to_prev (cyclic_list *head);

/* The function inserts an element "data" into the list "head" after the current one.
 * The function returns 1 if the pointer to the list was not passed or the memory for the new element was not allocated.
 * The function returns 0 in all other cases.
 */
int list_insert_next (cyclic_list *head, int data);

/* The function inserts an element "data" into the list "head" before the current one.
 * The function returns 1 if the pointer to the list was not passed or the memory for the new element was not allocated.
 * The function returns 0 in all other cases.
 */
int list_insert_prev (cyclic_list *head, int data);

/* The function deletes the current element (an entry in the pointer "data") in the list "head".
 * The function returns 1 if the pointer to the list was not passed or the list is empty.
 * The function returns 0 in all other cases.
 */
int list_delete (cyclic_list *head, int *data);

/* The function copies the passed list "head".
 * The function returns 0 if the pointer to the list was not passed or the memory for the new list was not allocated.
 * The function returns a pointer to the copied list in all other cases.
 */
cyclic_list * list_copy (cyclic_list *head);

/* The function displays the passed list "head" on the screen.
 * The function returns 1 if the pointer to the list was not passed.
 * The function returns 0 in all other cases.
 */
int list_screen (cyclic_list *head);

/* The function clears the passed list "head".
 */
void list_free (cyclic_list *head);

#endif // DOUBLY_CYCLIC_LIST_H_INCLUDED
