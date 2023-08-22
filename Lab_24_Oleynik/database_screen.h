#ifndef DATABASE_SCREEN_H_INCLUDED
#define DATABASE_SCREEN_H_INCLUDED

/* The main function of database processing is via a "h" by "w" pixel graphical interface.
 * The function returns 1 if the width is less than 640 and the height is 480, or the screen ratio is less than 4/3 or more than 16/9.
 * The function returns 0 in all other cases.
 */
int data_interface (int h, int w);

#endif // DATABASE_SCREEN_H_INCLUDED
