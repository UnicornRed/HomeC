/* Laboratory work 21.1a.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 * The module displays the "Sierpinski triangle" fractal with the possibility to change the recursion depth.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <graphics.h>
#include "Sierpinski_triangle.h"

/* The function performs graphical input of the string str starting from the coordinates
 * left and top until you press a key ENTER or a character from the string det_char.
 */
void input (int *left, int *top, size_t size_str, char *str, const char *det_char)
{
    char *i = str, key_pass = '\0';
    char letter[] = {'\0', '\0'};
    int left1 = *left, top1 = *top;

    setcolor(WHITE);

    outtextxy(left1, top1, "_");

    do
    {
        if((key_pass = readkey()) == 0)
            key_pass = readkey();

        if (key_pass == KEY_BACK && i > str)
        {
            setviewport(left1, top1, left1 + textwidth("_"), top1 + textheight("_"), 0);
            clearviewport();

            left1 -= textwidth(letter);
            setviewport(left1, top1, left1 + textwidth(letter), top1 + textheight(letter), 0);
            clearviewport();

            outtextxy(left1, top1, "_");

            i --;
        }

        if (key_pass > 31)
        {
            *i = key_pass;
            letter[0] = key_pass;
            i ++;

            setviewport(left1, top1, left1 + textwidth("_"), top1 + textheight("_"), 0);
            clearviewport();

            outtextxy(left1, top1, letter);
            left1 += textwidth(letter);
            outtextxy(left1, top1, "_");
        }
    } while(key_pass != KEY_ENTER && i - str < size_str && (!(strchr(det_char, key_pass)) || key_pass == '\0'));

    if (i == str)
    {
        if (key_pass == KEY_ENTER)
        {
            *i = '\0';
            *top += textheight("E");
        }
    }
    else
    {
        if (strchr(det_char, *(i - 1)))
        {
            *(i - 1) = '\0';
            *left = left1;
        }
        else
        {
            *i = '\0';
            *top += textheight("E");
        }
    }

    setviewport(left1, top1, left1 + textwidth("_"), top1 + textheight("_"), 0);
    clearviewport();
}

/* The function outputs an error message from the string str_error, starting with the coordinates
 * left and top, and waits for the key ENTER to be pressed.
 */
void error_put (int left, int top, char *str_error)
{
    cleardevice();

    setcolor(WHITE);
    outtextxy(left, top, str_error);
    outtextxy(left, top + textheight(str_error), "ENTER - terminate the program.");

    char key_pass;

    do
    {
        if((key_pass = readkey()) == 0)
            key_pass = readkey();
    } while (key_pass != KEY_ENTER);
}

/* The function draws the internal structure of the fractal by the boundary points from the array a,
 * making num_it iterations.
 */
void r_fract (int num_it, int *a)
{
    if (num_it > 0)
    {
        int b[8];

        for(int i = 0; i < 3; i ++)
        {
            b[2 * i] = (a[2 * i] + a[2 * i + 2] + 1) / 2;
            b[2 * i + 1] = (a[2 * i + 1] + a[2 * i + 3] + 1) / 2;
        }

        b[6] = b[0], b[7] = b[1];


        fillpoly(4, b);

        int c[3][8];

        for (int i = 0; i < 3; i ++)
        {
            c[i][0] = a[2 * i], c[i][1] = a[2 * i + 1];
            c[i][2] = b[2 * i], c[i][3] = b[2 * i + 1];
            c[i][4] = b[(2 * i + 4) % 6], c[i][5] = b[(2 * i + 4) % 6 + 1];
            c[i][6] = c[i][0], c[i][7] = c[i][1];

            r_fract(num_it - 1, c[i]);
        }
    }
}

/* The function displays (h - screen height, w - screen width) the "Sierpinski triangle" fractal with the possibility to change the recursion depth.
 * The function returns 1 if an error occurred during the input or the resolution is too small.
 * The function returns 0 in all other cases.
 */
int fract (int h, int w)
{
    if (w < 639 || h < 479)
        return 1;

    int gd = CUSTOM, gm = CUSTOM_MODE(w, h), num_it = 0, num_it_p = -1, a_int[8];
    char str[100], in_str[] = "Enter the coordinates of the points: ";
    double a[8] = {};

    initgraph(&gd, &gm, "");

    int  x_m = getmaxx(), y_m = getmaxy();
    int x_win_l = (int)(0.05 * x_m), y_win_t = (int)(0.05 * y_m), x_win_r = (int)(0.95 * x_m), y_win_b = (int)(0.90 * y_m);

    for(int i = 0; i < 11; i ++)
    {
        settextstyle(DEFAULT_FONT, HORIZ_DIR , i);

        if(textwidth(in_str) > (int)(0.25 * x_m) && i > 0)
        {
            settextstyle(DEFAULT_FONT, HORIZ_DIR , i - 1);
            break;
        }
    }

    outtextxy(x_win_l, y_win_t, in_str);

    int left = textwidth(in_str) + x_win_l, top = y_win_t, bool_enter = 0;

    for(int i = 0; i < 6 || !bool_enter; i ++)
    {
        int top_p = top;
        bool_enter = 0;

        if (left + textwidth("E") >= x_m || top + textheight("E") > y_m)
        {
            error_put(x_win_l, y_win_t, "Error input!");
            closegraph();
            return 1;
        }

        input(&left, &top, 100, str, " ");

        if (top != top_p)
        {
            left = textwidth(in_str) + x_win_l;
            bool_enter = 1;
        }

        if (str[0] == '\0')
            i --;

        char *j = str;
        int flag_point = 0, flag_sing = 0, place = 10;

        while (*j != '\0')
        {
            if ((*j < '0' && (*j != '.' || flag_point) && (*j != '-' || flag_sing || (j != str && *j == '-'))) || *j > '9')
            {
                error_put(x_win_l, y_win_t, "Error input!");
                closegraph();
                return 1;
            }

            if (*j == '-')
                flag_sing = 1;
            else if (*j == '.')
                flag_point = 1;
            else
            {
                if (flag_point)
                    a[i] = a[i] + (double)((int)(*j) - (int)('0')) / place, place *= 10;
                else
                    a[i] = a[i] * 10 + (int)(*j) - (int)('0');
            }

            j ++;
        }

        if (flag_sing)
            a[i] *= (-1);
    }

    for(int i = 0; i < 3; i ++)
        a[2 * i + 1] *= (-1);

    a[6] = a[0], a[7] = a[1];

    cleardevice();

    rectangle(x_win_l, y_win_t, x_win_r, y_win_b);

    char legend[] = "UP - increase the recursion, DOWN - decrease the recursion, ENTER - terminate the program.";

    for(int i = 0; i < 11; i ++)
    {
        settextstyle(DEFAULT_FONT, HORIZ_DIR , i);

        if((textheight(legend) > (int)(0.9 * y_win_t) || textwidth(legend) > (int)(0.98 * x_m)) && i > 0)
        {
            settextstyle(DEFAULT_FONT, HORIZ_DIR , i - 1);
            break;
        }
    }

    setcolor(WHITE);
    outtextxy((x_m - textwidth(legend)) / 2, y_m - 4 - textheight(legend), legend);

    double max_x = fmax(fmax(a[0], a[2]), a[4]), min_x = fmin(fmin(a[0], a[2]), a[4]), max_y = fmax(fmax(a[1], a[3]), a[5]), min_y = fmin(fmin(a[1], a[3]), a[5]);
    double mid[2] = {(max_x + min_x) / 2, (max_y + min_y) / 2};
    double multi_size = fmin((double)(0.97 * (x_win_r - x_win_l)) / (max_x - min_x), (double)(0.97 * (y_win_b - y_win_t)) / (max_y - min_y));
    int mid_it[2] = {x_m / 2 - (int)(multi_size * mid[0]), (0.95 * y_m) / 2 - (int)(multi_size * mid[1])};

    for(int i = 0; i < 8; i ++)
        a_int[i] = (int)(multi_size * a[i]) + mid_it[i % 2];

    char key_pass;
    int max_num_it = (int)(log(fmin(x_win_r - x_win_l, y_win_b - y_win_t)) / log(2)) - 3;

    do
    {
        setvisualpage(1);
        if (num_it != num_it_p)
        {
            setviewport(x_win_l + 1, y_win_t + 1, x_win_r - 1, y_win_b - 1, 0);
            clearviewport();

            setfillstyle(SOLID_FILL, WHITE);

            fillpoly(4, a_int);

            setcolor(BLACK);
            setfillstyle(SOLID_FILL, BLACK);

            r_fract(num_it, a_int);
        }
        setvisualpage(0);

        num_it_p = num_it;

        if((key_pass = readkey()) == 0)
            key_pass = readkey();

        if (key_pass == KEY_UP && num_it < max_num_it)
            num_it ++;
        if (key_pass == KEY_DOWN && num_it > 0)
            num_it --;
    } while(key_pass != KEY_ENTER);

    closegraph();

    return 0;
}
