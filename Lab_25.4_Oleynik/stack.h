#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/* The structure contains information about the stack element.
 * data - meaning;
 * prev - pointer to the next element.
 */
struct element
{
    double data;
    struct element *prev;
};

typedef struct element element;

/* The structure contains a pointer "top" to the last element of the stack.
 */
struct Stack
{
    element *top;
};

typedef struct Stack Stack;

/* The function initializes a pointer to the stack "head".
 * The function returns 1 if the pointer is null.
 * The function returns 0 in all other cases.
 */
int stack_alloc (Stack *head);

/* The function determines the empty stack "head".
 * The function returns 1 if the stack is empty.
 * The function returns 0 in all other cases.
 */
int stack_is_empty (Stack *head);

/* The function adds an element "data" to the stack "head".
 * The function returns 1 if the stack was not passed or the memory for the new element was not allocated.
 * The function returns 0 in all other cases.
 */
int stack_insert (Stack *head, double data);

/* The function deletes the last element (an entry in the pointer "data") of the stack "head".
 * The function returns 1 if the stack was not passed or the stack is empty.
 * The function returns 0 in all other cases.
 */
int stack_delete (Stack *head, double *data);

/* The function clears the stack "head".
 * The function returns 1 if the stack was not passed.
 * The function returns 0 in all other cases.
 */
int stack_free (Stack *head);

#endif // STACK_H_INCLUDED
