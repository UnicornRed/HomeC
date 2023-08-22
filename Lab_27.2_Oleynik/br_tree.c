/* Laboratory work 27.2.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 * The module handles the red-black tree.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "br_tree.h"

br_tree * br_tree_alloc ()
{
    br_tree *tree = malloc(sizeof(br_tree));

    if (!tree)
        return NULL;

    tree->head = NULL;

    return tree;
}

int br_tree_rotation_clockwise (br_tree *tree, element *center)
{
    if (!tree)
        return 1;

    if (!center || !(center->left))
        return 2;

    element *mid;

    mid = center->left->right;
    center->left->right = center;

    if (mid)
        mid->parent = center;

    if (center->parent)
    {
        if (center->key < center->parent->key)
            center->parent->left = center->left;
        else
            center->parent->right = center->left;

        center->left->parent = center->parent;
    }

    center->parent = center->left;
    center->left = mid;

    if (tree->head == center)
    {
        center->parent->parent = NULL;
        tree->head = center->parent;
    }

    return 0;
}

int br_tree_rotation_counterclockwise (br_tree *tree, element *center)
{
    if (!tree)
        return 1;

    if (!center || !(center->right))
        return 2;

    element *mid;

    mid = center->right->left;
    center->right->left = center;

    if (mid)
        mid->parent = center;

    if (center->parent)
    {
        if (center->key < center->parent->key)
            center->parent->left = center->right;
        else
            center->parent->right = center->right;

        center->right->parent = center->parent;
    }

    center->parent = center->right;
    center->right = mid;

    if (tree->head == center)
    {
        center->parent->parent = NULL;
        tree->head = center->parent;
    }

    return 0;
}

element * br_tree_search (br_tree *tree, int key)
{
    if (!tree || !(tree->head))
        return NULL;

    element *x = tree->head;

    while (x->key != key)
    {
        if (x->key > key)
            x = x->left;
        else if (x->key < key)
            x = x->right;

        if (!x)
            return NULL;
    }

    return x;
}

element * br_tree_search_next (element *x)
{
    if (!x)
        return NULL;
    else if (x->right)
        return br_tree_min(x->right);
    else
    {
        while (x->parent)
        {
            if (x == x->parent->right)
                x = x->parent;
            else
                return x->parent;
        }

        return NULL;
    }
}

element * br_tree_search_prev (element *x)
{
    if (!x)
        return NULL;
    else if (x->left)
        return br_tree_max(x->left);
    else
    {
        while (x->parent)
        {
            if (x == x->parent->left)
                x = x->parent;
            else
                return x->parent;
        }

        return NULL;
    }
}

element * br_tree_max (element *x)
{
    if (!x)
        return NULL;

    while (x->right)
        x = x->right;

    return x;
}

element * br_tree_min (element *x)
{
    if (!x)
        return NULL;

    while (x->left)
        x = x->left;

    return x;
}

/* The function restores the red-black properties of the tree relative to the element (x) when it is inserted.
 */
void recovery_insert (br_tree *tree, element *x)
{
    if (x == tree->head)
        x->color = BLACK;
    else if (x->parent && x->parent->color == RED)
    {
        if (x->parent->key < x->parent->parent->key)
        {
            if (!(x->parent->parent->right) || x->parent->parent->right->color == BLACK)
            {
                if (x->key > x->parent->key)
                {
                    br_tree_rotation_counterclockwise(tree, x->parent);
                    x = x->left;
                }

                x->parent->color = BLACK;
                x->parent->parent->color = RED;

                br_tree_rotation_clockwise(tree, x->parent->parent);
            }
            else
            {
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                x->parent->parent->right->color = BLACK;

                recovery_insert(tree, x->parent->parent);
            }
        }
        else
        {
            if (!(x->parent->parent->left) || x->parent->parent->left->color == BLACK)
            {
                if (x->key < x->parent->key)
                {
                    br_tree_rotation_clockwise(tree, x->parent);
                    x = x->right;
                }

                x->parent->color = BLACK;
                x->parent->parent->color = RED;

                br_tree_rotation_counterclockwise(tree, x->parent->parent);
            }
            else
            {
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                x->parent->parent->left->color = BLACK;

                recovery_insert(tree, x->parent->parent);
            }
        }
    }
}

int br_tree_insert (br_tree *tree, element_t *x, int key)
{
    if (!tree || !x)
        return 1;

    element *t = malloc(sizeof(element));
    element *now = tree->head;

    if (!t)
        return 1;

    t->left = NULL;
    t->right = NULL;
    t->data = malloc(sizeof(element_t));
    memcpy(t->data, x, sizeof(element_t));
    t->key = key;
    t->color = RED;
    t->parent = NULL;

    if (!now)
    {
        t->color = BLACK;
        tree->head = t;

        return 0;
    }

    do
    {
        if (key < now->key)
        {
            if (!(now->left))
            {
                now->left = t;
                t->parent = now;

                break;
            }

            now = now->left;
        }
        else
        {
            if (!(now->right))
            {
                now->right = t;
                t->parent = now;

                break;
            }

            now = now->right;
        }
    } while(1);

    recovery_insert(tree, t);

    return 0;
}

/* The function restores the red-black properties of the tree relative to the element (x) when it is deleted.
 */
void recovery_delete (br_tree *tree, element *x)
{
    if (x == tree->head || x->color == RED)
    {
        x->color = BLACK;

        return;
    }
    else
    {
        if (x->key < x->parent->key)
        {
            if (x->parent->right->color == RED)
            {
                x->parent->right->color = BLACK;
                x->parent->color = RED;

                br_tree_rotation_counterclockwise(tree, x->parent);
                recovery_delete(tree, x);
            }
            else
            {
                if (!(x->parent->right->right) || x->parent->right->right->color == BLACK)
                {
                    if (!(x->parent->right->left) || x->parent->right->left->color == BLACK)
                    {
                        x->parent->right->color = RED;

                        if (x->parent->color == RED)
                            x->parent->color = BLACK;
                        else
                            recovery_delete(tree, x->parent);
                    }
                    else
                    {
                        x->parent->right->color = RED;
                        x->parent->right->left->color = BLACK;

                        br_tree_rotation_clockwise(tree, x->parent->right);
                        recovery_delete(tree, x);
                    }
                }
                else
                {
                    x->parent->right->color = x->parent->color;
                    x->parent->color = BLACK;
                    x->parent->right->right->color = BLACK;

                    br_tree_rotation_counterclockwise(tree, x->parent);
                }
            }
        }
        else
        {
            if (x->parent->left->color == RED)
            {
                x->parent->left->color = BLACK;
                x->parent->color = RED;

                br_tree_rotation_clockwise(tree, x->parent);
                recovery_delete(tree, x);
            }
            else
            {
                if (!(x->parent->left->left) || x->parent->left->left->color == BLACK)
                {
                    if (!(x->parent->left->right) || x->parent->left->right->color == BLACK)
                    {
                        x->parent->left->color = RED;

                        if (x->parent->color == RED)
                            x->parent->color = BLACK;
                        else
                            recovery_delete(tree, x->parent);
                    }
                    else
                    {
                        x->parent->left->color = RED;
                        x->parent->left->right->color = BLACK;

                        br_tree_rotation_counterclockwise(tree, x->parent->left);
                        recovery_delete(tree, x);
                    }
                }
                else
                {
                    x->parent->left->color = x->parent->color;
                    x->parent->color = BLACK;
                    x->parent->left->left->color = BLACK;

                    br_tree_rotation_clockwise(tree, x->parent);
                }
            }
        }
    }
}

int br_tree_delete (br_tree *tree, int key)
{
    if (!tree)
        return 1;

    element *el, *el_del;

    el = br_tree_search(tree, key);

    if (!el)
        return 2;

    if (!(el->left) || !(el->right))
        el_del = el;
    else
    {
        el_del = br_tree_min(el->right);
        el->key = el_del->key;
        memcpy(el->data, el_del->data, sizeof(element_t));
    }

    element *x, *n = NULL;

    if (el_del->left)
        x = el_del->left;
    else if(el_del->right)
        x = el_del->right;
    else
    {
        n = malloc(sizeof(element));

        if (!n)
            return 1;

        n->key = el_del->key;
        n->color = BLACK;
        n->left = NULL;
        n->right = NULL;
        x = n;
    }

    x->parent = el_del->parent;

    if (el_del == tree->head)
    {
        if (n)
        {
            tree->head = NULL;

            free(n);
        }
        else
        {
            tree->head = x;
            x->color = BLACK;
        }
    }
    else
    {
        if (el_del->key < el_del->parent->key)
            el_del->parent->left = x;
        else
            el_del->parent->right = x;

        if (el_del->color == BLACK)
            recovery_delete(tree, x);

        if (n)
        {
            if (n == n->parent->left)
                n->parent->left = NULL;
            else
                n->parent->right = NULL;

            free(n);
        }
    }

    free(el_del->data);
    free(el_del);

    return 0;
}

/* The function recursively calculates the black height for the element (x).
 * The function returns 0 if the tree is not red-black.
 * The function returns the black height in all other cases.
 */
int check_element (element *x)
{
    if (!x)
        return 1;
    else
    {
        int l = check_element(x->left), r = check_element(x->right);

        if (!l || !r || r != l || (x->color == RED &&
            ((x->left && x->left->color == RED) ||
             (x->right && x->right->color == RED))))
            return 0;

        if (x->color == BLACK)
            l ++;

        return l;
    }
}

int br_tree_check (br_tree *tree)
{
    if (!tree || !(tree->head))
        return 0;
    else
        return check_element(tree->head);
}

/* The function prints the tree recursively (x is the current element).
 */
void print_element (element *x)
{
    if (!x)
        printf("NIL");
    else
    {
        printf("(");

        print_element(x->left);

        printf(")<-[%d(%d, %d)]->(", *(x->data), x->key, x->color);

        print_element(x->right);

        printf(")");
    }
}

void br_tree_print (br_tree *tree)
{
    if (tree)
    {
        if (tree->head)
            print_element(tree->head);
        else
            printf("Empty.");

        printf("\n");
    }
}

/* The function recursively deletes the tree (x is the current element).
 */
void free_element (element *x)
{
    if (x)
    {
        free_element(x->left);
        free_element(x->right);

        free(x->data);
        free(x);
    }
}

void br_tree_free (br_tree *tree)
{
    if (tree)
    {
        if (tree->head)
            free_element(tree->head);

        free(tree);
    }
}
