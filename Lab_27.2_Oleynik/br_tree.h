#ifndef BR_TREE_H_INCLUDED
#define BR_TREE_H_INCLUDED

/* Alias of the data type for the values of the tree elements.
 */
typedef int element_t;

/* The enumerated data type for the color of the tree elements.
 */
enum color_tree {RED, BLACK};

typedef enum color_tree color_tree;

/* Structure for tree elements.
 * key - key of element;
 * data - value of element;
 * color - color for coloring red-black tree;
 * parent - pointer to the parent node;
 * left - pointer to the left child node;
 * right - pointer to the right child node.
 */
struct element
{
    int key;
    element_t *data;
    color_tree color;
    struct element *parent;
    struct element *left, *right;
};

typedef struct element element;

/* Structure with a pointer to the root of the tree (head).
 */
struct br_tree
{
    element *head;
};

typedef struct br_tree br_tree;

/* The function creates a pointer to the tree structure.
 * The function returns NULL if no memory has been allocated.
 * The function returns a pointer to the br_tree structure in all other cases.
 */
br_tree * br_tree_alloc ();

/* The function rotates clockwise around the tree (tree) node (center).
 * The function returns 1 if the tree was not passed.
 * The function returns 2 if the rotation cannot be performed.
 * The function returns 0 in all other cases.
 */
int br_tree_rotation_clockwise (br_tree *tree, element *center);

/* The function rotates counterclockwise around the tree (tree) node (center).
 * The function returns 1 if the tree was not passed.
 * The function returns 2 if the rotation cannot be performed.
 * The function returns 0 in all other cases.
 */
int br_tree_rotation_counterclockwise (br_tree *tree, element *center);

/* The function finds an element in the tree (tree) by the key (key).
 * The function returns NULL if the tree was not passed, it is empty, or the element was not found.
 * The function returns a pointer to the element in all other cases.
 */
element * br_tree_search (br_tree *tree, int key);

/* The function finds the next element after the passed one (x).
 * The function returns NULL if the element was not passed or the next element was not found.
 * The function returns a pointer to the next element in all other cases.
 */
element * br_tree_search_next (element *x);

/* The function finds the previous element after the passed one (x).
 * The function returns NULL if the element was not passed or the previous element was not found.
 * The function returns a pointer to the previous element in all other cases.
 */
element * br_tree_search_prev (element *x);

/* The function finds the maximum element in the tree (tree).
 * The function returns NULL if the tree was not passed or it is empty.
 * The function returns a pointer to the maximum element in all other cases.
 */
element * br_tree_max (element *x);

/* The function finds the minimum element in the tree (tree).
 * The function returns NULL if the tree was not passed or it is empty.
 * The function returns a pointer to the minimum element in all other cases.
 */
element * br_tree_min (element *x);

/* The function inserts an element (x) into the tree (tree) by key (key).
 * The function returns 1 if the tree or element value has not been passed or memory has not been allocated.
 * The function returns 0 in all other cases.
 */
int br_tree_insert (br_tree *tree, element_t *x, int key);

/* The function removes an element from the tree (tree) by key (key).
 * The function returns 1 if the tree was not passed or the memory for the auxiliary node was not allocated.
 * The function returns 2 if the element was not found.
 * The function returns 0 in all other cases.
 */
int br_tree_delete (br_tree *tree, int key);

/* The function checks the tree (tree) for a red-black match.
 * The function returns 0 if the tree was not passed or it is empty.
 * The function returns the black height in all other cases.
 */
int br_tree_check (br_tree *tree);

/* The function prints the tree (tree).
 */
void br_tree_print (br_tree *tree);

/* The function clears the tree (tree).
 */
void br_tree_free (br_tree *tree);

#endif // BR_TREE_H_INCLUDED
