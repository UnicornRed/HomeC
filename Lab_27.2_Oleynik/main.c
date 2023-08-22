/* Laboratory work 27.2.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_str.h"
#include "br_tree.h"

int main()
{
    int e, key, k = 0, bh, cont = 1;
    char command[100];
    br_tree *tree = br_tree_alloc();

    while (cont)
    {
        printf(">: ");

        input_str(command, 100);

        if (!(strcmp(command, "insert")))
        {
            printf("Enter a value: ");

            if (scanf("%d", &e) != 1)
                printf("Error input!\n");
            else
            {
                k ++;

                if (br_tree_insert(tree, &e, k))
                    printf("Element was not inserted.\n");
                else
                    printf("Element was inserted. Key = %d.\n", k);
            }
        }

        if (!(strcmp(command, "del")))
        {
            printf("Enter a key: ");

            if (scanf("%d", &key) != 1)
                printf("Error input!\n");
            else
            {
                if (br_tree_delete(tree, key))
                    printf("Error!\n");
                else
                    printf("Element deleted.\n");
            }
        }

        if (!(strcmp(command, "search")))
        {
            printf("Enter a key: ");

            if (scanf("%d", &key) != 1)
                printf("Error input!\n");
            else
            {
                element *l;

                if ((l = br_tree_search(tree, key)))
                    printf("Element was found. Value = %d\n", *(l->data));
                else
                    printf("Element was not found.\n");
            }
        }

        if (!(strcmp(command, "next")))
        {
            printf("Enter a key: ");

            if (scanf("%d", &key) != 1)
                printf("Error input!\n");
            else
            {
                element *l;

                if (!(l = br_tree_search(tree, key)))
                    printf("Element was not found.\n");
                else
                {
                    if ((l = br_tree_search_next(l)))
                        printf("Next element - %d.\n", *(l->data));
                    else
                        printf ("Next element was not found.\n");
                }
            }
        }

        if (!(strcmp(command, "prev")))
        {
            printf("Enter a key: ");

            if (scanf("%d", &key) != 1)
                printf("Error input!\n");
            else
            {
                element *l;

                if (!(l = br_tree_search(tree, key)))
                    printf("Element was not found.\n");
                else
                {
                    if ((l = br_tree_search_prev(l)))
                        printf("Previous element - %d.\n", *(l->data));
                    else
                        printf ("Previous element was not found.\n");
                }
            }
        }

        if (!(strcmp(command, "print")))
            br_tree_print(tree);

        if (!(strcmp(command, "check")))
        {
            if ((bh = br_tree_check(tree)))
                printf("The tree is red-black. bh = %d\n", bh);
            else
                printf("The tree is not red-black.\n");
        }

        if (!(strcmp(command, "help")))
            printf("insert - insert an element;\n"
                   "del - delete an element;\n"
                   "search - determine if there is an element in the tree.;\n"
                   "next - define the next element.;\n"
                   "prev - define the previous element.;\n"
                   "print - print the tree.;\n"
                   "check - check the red-black tree and determine the black height;\n"
                   "help - display a reminder;\n"
                   "exit - end the program.\n");

        if (!(strcmp(command, "exit")))
            cont = 0;
    }

    br_tree_free(tree);

    return 0;
}
