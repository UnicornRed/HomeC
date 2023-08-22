/* Laboratory work 25.4.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stack_alloc (Stack *head)
{
    if (!head)
        return 1;

    head->top = NULL;

    return 0;
}

int stack_is_empty (Stack *head)
{
    return head->top ? 0 : 1;
}

int stack_insert (Stack *head, double data)
{
    if (!head)
        return 1;

    element *el = malloc(sizeof(element));

    if (!el)
        return 1;

    el->data = data;
    el->prev = head->top;
    head->top = el;

    return 0;
}

int stack_delete (Stack *head, double *data)
{
    if (!head)
        return 1;

    element *el = head->top;

    if (!el)
        return 1;

    if (data)
        *data = head->top->data;

    head->top = head->top->prev;

    free(el);

    return 0;
}

int stack_free (Stack *head)
{
    if (!head)
        return 1;

    while (head->top)
        stack_delete(head, NULL);

    return 0;
}
