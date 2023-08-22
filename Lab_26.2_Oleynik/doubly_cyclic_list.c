/* Laboratory work 26.2.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 * The module processes a doubly linked cyclic list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_str.h"
#include "doubly_cyclic_list.h"

#define MAX_STR 100
#define MAX_LIST 10

/* The function defines the first NULL pointer in the array "list".
 * The function returns MAX_LIST if the NULL pointer was not found.
 * The function returns the number of the NULL pointer in all other cases.
 */
int first_list_null (cyclic_list **list)
{
    for (cyclic_list **i = list, **e = list + MAX_LIST; i < e; i ++)
    {
        if (!(*i))
            return i - list;
    }

    return MAX_LIST;
}

/* The function defines the first not NULL pointer in the array "list".
 * The function returns -1 if the not NULL pointer was not found.
 * The function returns the number of the not NULL pointer in all other cases.
 */
int first_list (cyclic_list **list)
{
    for (cyclic_list **i = list, **e = list + MAX_LIST; i < e; i ++)
    {
        if (*i)
            return i - list;
    }

    return -1;
}

int list_interface ()
{
    char str[MAX_STR];
    int cont = 1, error = 0, data, actual_list = -1;
    cyclic_list * list[MAX_LIST];
    cyclic_list *head = NULL;

    for(cyclic_list **i = list, **e = list + MAX_LIST; i < e; i ++)
        *i = NULL;

    list_alloc(head);

    while (cont)
    {
        printf(">: ");

        if (input_str(str, MAX_STR))
            error = 1;

        if (!(strcmp(str, "alloc")))
        {
            int num_list = first_list_null(list);

            if (num_list == MAX_LIST)
                printf("Unable to create a list.\n");
            else
            {
                list[num_list] = malloc(sizeof(cyclic_list));

                if (!(list[num_list]))
                    printf("Unable to create a list.\n");
                else
                {
                    list_alloc(list[num_list]);

                    printf("The number of the created list: %d\n", num_list);
                }
            }
        }

        if (!(strcmp(str, "copy")))
        {
            printf("Enter the list number: ");

            int num_list;

            if (scanf("%d", &num_list) != 1)
            {
                error = 1;

                break;
            }

            if (num_list == actual_list || num_list < 0 || num_list >= MAX_LIST)
                printf("Unavailable list number.\n");
            else
            {
                if (actual_list == -1 || list[num_list])
                    printf("The list was not copied.\n");
                else
                {
                    list[num_list] = list_copy(head);

                    if (!(list[num_list]))
                        printf("The list was not copied.\n");
                    else
                        printf("The list is copied.\n");
                }
            }
        }

        if (!(strcmp(str, "del")))
        {
            if (list_delete(head, &data))
                printf("The element was not deleted.\n");
            else
                printf("The element \"%d\" was deleted.\n", data);
        }

        if (!(strcmp(str, "insertn")))
        {
            printf("Enter the value of the element to insert: ");

            if (scanf("%d", &data) != 1)
            {
                error = 1;

                break;
            }

            if (list_insert_next(head, data))
                printf("The element was not inserted.\n");
            else
                printf("The element was inserted.\n");
        }

        if (!(strcmp(str, "insertp")))
        {
            printf("Enter the value of the element to insert: ");

            if (scanf("%d", &data) != 1)
            {
                error = 1;

                break;
            }

            if (list_insert_prev(head, data))
                printf("The element was not inserted.\n");
            else
                printf("The element was inserted.\n");
        }

        if (!(strcmp(str, "screen")))
            list_screen(head);

        if (!(strcmp(str, "tolist")))
        {
            printf("Enter the list number: ");

            int num_list;

            if (scanf("%d", &num_list) != 1)
            {
                error = 1;

                break;
            }

            if (num_list < 0 || num_list >= MAX_LIST)
                printf("Unavailable list number.\n");
            else
            {
                if (list[num_list])
                {
                    head = list[num_list];
                    actual_list = num_list;

                    printf("The current list: %d\n", actual_list);
                }
                else
                    printf("There is no list with the entered number.\n");
            }
        }

        if (!(strcmp(str, "lists")))
        {
            printf("Available lists: ");

            for (cyclic_list **i = list, **e = list + MAX_LIST; i < e; i ++)
            {
                if (*i)
                    printf ("%Iu ", i - list);
            }

            printf("\n");
        }

        if (!(strcmp(str, "free")))
        {
            if (!head)
                printf("There is no available list.\n");
            else
            {
                list_free(head);
                free(list[actual_list]);

                list[actual_list] = NULL;
                actual_list = first_list(list);

                if (actual_list == -1)
                {
                    head = NULL;

                    printf("There is no available list.\n");
                }
                else
                {
                    head = list[actual_list];

                    printf("The current list is cleared. The current list: %d\n", actual_list);
                }
            }
        }

        if (!(strcmp(str, "next")))
        {
            if (head->num)
            {
                list_to_next(head);

                printf("The pointer to the current element is moved forward.\n");
            }
            else
                printf("The list is empty.\n");
        }

        if (!(strcmp(str, "prev")))
        {
            if (head->num)
            {
                list_to_prev(head);

                printf("The pointer to the current element is moved back.\n");
            }
            else
                printf("The list is empty.\n");
        }

        if (!(strcmp(str, "actual")))
        {
            if (head->num)
                printf("The current element: %d\n", head->actual->data);
            else
                printf("The list is empty.\n");
        }

        if (!(strcmp(str, "actuall")))
        {
            if (actual_list == -1)
                printf("There is no available list.\n");
            else
                printf("Current list: %d\n", actual_list);
        }

        if (!(strcmp(str, "help")))
        {
            printf("alloc - create a list. The first free list will be selected;\n"
                   "tolist - go to the selected list;\n"
                   "lists - display the available lists;\n"
                   "copy - copy the current list to the selected one.;\n"
                   "actuall - display the current list.;\n"
                   "insertn - insert an element after the current one;\n"
                   "insertp - insert an element before the current one;\n"
                   "screen - display the list on the screen;\n"
                   "free - delete all list elements;\n"
                   "help - display a reminder;\n"
                   "actual - print the current element;\n"
                   "next - move the pointer to the current element forward;\n"
                   "prev - move the pointer to the current element back;\n"
                   "exit - end the program.\n");
        }

        if (!(strcmp(str, "exit")))
            cont = 0;

        *str = '\0';
    }

    for (cyclic_list **i = list, **e = list + MAX_LIST; i < e; i ++)
    {
        if (*i)
        {
            list_free(*i);

            free(*i);

            *i = NULL;
        }
    }

    if (error)
        return 1;

    return 0;
}

int list_alloc (cyclic_list *head)
{
    if (!head)
        return 1;

    head->actual = NULL;
    head->num = 0;

    return 0;
}

int list_to_next (cyclic_list *head)
{
    if (!head || !(head->actual))
        return 1;

    head->actual = head->actual->next;

    return 0;
}

int list_to_prev (cyclic_list *head)
{
    if (!head || !(head->actual))
        return 1;

    head->actual = head->actual->prev;

    return 0;
}

int list_insert_next (cyclic_list *head, int data)
{
    if (!head)
        return 1;

    element *el = malloc(sizeof(element));

    if (!el)
        return 1;

    el->data = data;

    if (!(head->actual))
    {
        head->actual = el;
        el->next = el;
        el->prev = el;
    }
    else
    {
        el->next = head->actual->next;
        el->prev = head->actual;
        head->actual->next->prev = el;
        head->actual->next = el;
    }

    head->num ++;

    return 0;
}

int list_insert_prev (cyclic_list *head, int data)
{
    if (!head)
        return 1;

    element *el = malloc(sizeof(element));

    if (!el)
        return 1;

    el->data = data;

    if (!(head->actual))
    {
        head->actual = el;
        el->next = el;
        el->prev = el;
    }
    else
    {
        el->next = head->actual;
        el->prev = head->actual->prev;
        head->actual->prev->next = el;
        head->actual->prev = el;
    }

    head->num ++;

    return 0;
}

int list_delete (cyclic_list *head, int *data)
{
    if (!head || !(head->actual))
        return 1;

    if (data)
        *data = head->actual->data;

    if (head->num == 1)
    {
        free(head->actual);

        head->actual = NULL;
    }
    else
    {
        element *prev = head->actual->prev;

        list_to_next(head);

        free(head->actual->prev);

        head->actual->prev = prev;
        prev->next = head->actual;
    }

    head->num --;

    return 0;
}

cyclic_list * list_copy (cyclic_list *head)
{
    if (!head)
        return NULL;

    cyclic_list *head_copy = malloc(sizeof(cyclic_list));

    if (!head_copy)
        return NULL;

    list_alloc(head_copy);

    for (int i = 0; i < head->num; i ++)
    {
        if (list_insert_next(head_copy, head->actual->data))
        {
            list_free(head_copy);

            return NULL;
        }

        list_to_prev(head);
    }

    return head_copy;
}

int list_screen (cyclic_list *head)
{
    if (!head)
        return 1;

    if (!(head->num))
    {
        printf("The list is empty.\n");

        return 0;
    }

    printf(" v\n-");

    for (int i = 0; i < head->num; i ++)
    {
        printf("%d-", head->actual->data);

        list_to_next(head);
    }

    printf("\n");

    return 0;
}

void list_free (cyclic_list *head)
{
    if (!head || !(head->actual))
        return;

    while (!(list_delete(head, NULL)));
}
