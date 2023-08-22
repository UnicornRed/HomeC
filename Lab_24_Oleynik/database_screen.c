/* Laboratory work 24.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 * The module processes the database through a graphical interface.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <graphics.h>
#include "database.h"
#include "comparison_fun.h"
#include "database_screen.h"

/* A structure that contains information about the parameters of the graphical output.
 * x_m and y_m - maximum values for the width and height of the screen.
 * indent_x and indent_y - horizontal and vertical margins between objects displayed on the screen.
 */
struct screen_state
{
    int x_m, y_m, indent_x, indent_y;
} state;

/* Text displayed on the screen by various functions of the module.
 */
const char sel_lines[] = "Name\0"
                         "Year open\0"
                         "Mass\0"
                         "Radius\0"
                         "Distance\0"
                         "Type\0"
                         "Input\0"
                         "Repeat\0"
                         "Gas giant\0"
                         "Neptune like\0"
                         "Super Earth\0"
                         "Terrestrial\0"
                         "Unknown\0"
                         "ENTER - terminate the program.\0"
                         "Enter the element number\0"
                         "Sort\0"
                         "Enter the file name\0"
                         "Quit\0";
const char *script[18] = {sel_lines, sel_lines + 5, sel_lines + 15,
                       sel_lines + 20, sel_lines + 27, sel_lines + 36,
                       sel_lines + 41, sel_lines + 47, sel_lines + 54,
                       sel_lines + 64, sel_lines + 77, sel_lines + 89,
                       sel_lines + 101, sel_lines + 109, sel_lines + 140,
                       sel_lines + 165, sel_lines + 170, sel_lines + 190};

/* The function outputs a message from the string str, starting with the coordinates
 * left and top, and waits for the key ENTER to be pressed.
 */
void output (int left, int top, char *str)
{
    cleardevice();

    setcolor(WHITE);
    outtextxy(left, top, str);
    outtextxy(left, top + textheight(str), script[13]);

    char key_pass;

    do
    {
        if((key_pass = readkey()) == 0)
            key_pass = readkey();
    } while (key_pass != KEY_ENTER);

    cleardevice();
}

/* The function sets the font size for a string "longest" that is limited by the size "max_size_x" and "max_size_y".
 */
void settextsize (size_t max_size_x, size_t max_size_y, const char *longest)
{
    if (!longest)
        return;

    for(int i = 0; i < 100; i ++)
    {
        settextstyle(DEFAULT_FONT, HORIZ_DIR , i);

        if ((textwidth(longest) > max_size_x || textheight("E") > max_size_y) && i > 0)
        {
            settextstyle(DEFAULT_FONT, HORIZ_DIR , i - 1);
            break;
        }
    }
}

/* The function converts an integer "num" to a string "str" (with the specified minimum number "int_part" of characters).
 * The function returns 1 if the string was not passed.
 * The function returns 0 in all other cases.
 */
int int_to_string (int num, int int_part, char *str)
{
    if (!str)
        return 1;

    int count = 0, a = (int)fabs((double)num), bool_minus = 0;

    if (!a)
        count = 1;

    if (num < 0)
    {
        *str = '-';
        bool_minus = 1;
        count ++;
    }

    num = a;

    while (a)
    {
        count ++;
        a /= 10;
    }

    count = count < int_part ? int_part : count;

    for (char *i = str + count - 1, *e = str + bool_minus; i >= e; i --)
        *i = (char)(num % 10 + 48), num /= 10;

    *(str + count) = '\0';

    return 0;
}

/* The function converts a real number "num" to a string "str"
 * (with the specified minimum number "real_part" of characters of the real part)
 * The function returns 1 if the string was not passed.
 * The function returns 0 in all other cases.
 */
int double_to_string (double num, size_t real_part, char *str)
{
    if (!str)
        return 1;

    int_to_string((int)num, 0, str);

    size_t real_part_10 = 1, real_part1 = real_part;

    if (real_part)
    {
        num = fabs(num);

        while (real_part)
        {
            real_part_10 *= 10;
            real_part --;
        }

        int_to_string((int)((num - (int)num) * real_part_10), real_part1, str + strlen(str) + 1);

        *(str + strlen(str)) = '.';
    }

    return 0;
}

/* The function draws a button with dimensions "rect_size_x" and "rect_size_y" starting from the coordinates
 * "x" and "y" on the screen, paints the outline of the rectangle with color "color_rect", and the interior of the rectangle
 * with color "color_bg", and displays text "str" with color "color_rect" in its center.
 */
void draw_button (int x, int y, int rect_size_x, int rect_size_y, int color_bg, int color_text, int color_rect, const char *str)
{
    setviewport(x, y, x + rect_size_x, y + rect_size_y, 0);
    clearviewport();

    setcolor(color_rect);

    rectangle(x, y, x + rect_size_x, y + rect_size_y);

    setfillstyle(SOLID_FILL, color_bg);
    floodfill(x + state.indent_x, y + state.indent_y, color_rect);
    setcolor(color_text);

    outtextxy(x + (rect_size_x - textwidth(str)) / 2 + 1, y + state.indent_y + 1, str);
}

/* The function outputs a screen title "header" that is limited in size "header_size_x" and "header_size_y".
 * The function returns 0 if the string was not passed.
 * The function returns an integer (the lower bound of the header) in all other cases.
 */
int print_header (int header_size_x, int header_size_y, char *header)
{
    if (!header)
        return 0;

    settextsize(header_size_x, header_size_y, header);

    setcolor(WHITE);

    outtextxy((state.x_m - textwidth(header)) / 2, state.indent_y, header);

    return 2 * state.indent_y + textheight("E");
}

/* The function performs graphical input of the string "str" (maximum size - size_str) starting from the coordinates
 * "left" and "top" until you press a key ENTER or a character from the string "det_char".
 */
void input (int left, int top, size_t size_str, char *str, const char *det_char)
{
    char *i = str, key_pass = '\0', letter[] = {'\0', '\0'};
    int left1 = left, top1 = top;

    outtextxy(left1, top1, "_");

    do
    {
        if ((key_pass = readkey()) == 0)
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
    } while (key_pass != KEY_ENTER && i - str < size_str && (!(strchr(det_char, key_pass)) || key_pass == '\0'));

    *i = '\0';

    setviewport(left1, top1, left1 + textwidth("_"), top1 + textheight("_"), 0);
    clearviewport();
}

/* The function performs graphical input of a real number from coordinates "left" and "top".
 * The function returns NaN if nothing was entered or it is not possible to convert the string to a real number.
 * The function returns a real number in all other cases.
 */
double input_double (int left, int top)
{
    double a = 0;
    char str[29];
    char *j = str;
    int flag_point = 0, flag_sing = 0, place = 10;

    input(left, top, 28, str, " ");

    if (*j == '\0')
        return 0.0 / 0.0;

    while (*j != '\0')
    {
        if ((*j < '0' && (*j != '.' || flag_point) && (*j != '-' || flag_sing || (j != str && *j == '-'))) || *j > '9')
        {
            output(state.indent_x, state.indent_y, "Error input!");
            return 0.0 / 0.0;
        }

        if (*j == '-')
            flag_sing = 1;
        else if (*j == '.')
            flag_point = 1;
        else
        {
            if (flag_point)
                a = a + (double)((int)(*j) - (int)('0')) / place, place *= 10;
            else
                a = a * 10 + (int)(*j) - (int)('0');
        }

        j ++;
    }

    if (flag_sing)
        a *= (-1);

    return a;
}

/* The function performs graphical input of an integer (writing to the pointer "b")
 * from the coordinates "left" and "top".
 * The function returns 1 if no real number was entered.
 * The function returns 0 in all other cases.
 */
int input_int (int left, int top, int *b)
{
    double a = input_double(left, top);

    if (a != a)
        return 1;

    *b = (int)a;

    return 0;
}

/* The function performs graphical output of the database "a" in the form of a table.
 */
void database_output_screen (database *a)
{
    if (!(a->size_base))
        return;

    int x_m, y_m, indent_x, indent_y, cont, x, y, page, up_border, dawn_border;
    char key_pass, str[28], longer[61];

    cont = 1;
    page = 0;
    x_m = state.x_m;
    y_m = state.y_m;
    longer[60] = '\0';
    indent_x = state.indent_x;
    indent_y = state.indent_y;

    for (int i = 0; i < 60; i ++)
        longer[i] = 'E';

    settextsize(x_m - 14 * indent_x - 6, (0.8 * y_m - 7 - 11 * indent_y) / 9, longer);

    up_border = 2 * indent_y + 2 * textheight("E") + 1;
    dawn_border = 13 * indent_y + 12 * textheight("E") + 2;

    while (cont && a->size_base)
    {
        cleardevice();
        setcolor(WHITE);

        x = indent_x;

        outtextxy(x, indent_y, "N");

        x += indent_x + textwidth("EEEE") + 1;
        y = dawn_border;

        line(x, 0, x, y);

        outtextxy(x + indent_x, indent_y, script[0]);

        x += 2 * indent_x + textwidth("EEEEEEEEEE") + 1;

        line(x, 0, x, y);

        outtextxy(x + indent_x, indent_y, "Open");
        outtextxy(x + indent_x, indent_y + textheight("E"), "year");

        x += 2 * indent_x + textwidth("EEEE") + 1;

        line(x, 0, x, y);

        outtextxy(x + indent_x, indent_y, script[2]);
        outtextxy(x + indent_x, indent_y + textheight("E"), "10^24kg");

        x += 2 * indent_x + textwidth("EEEEEEEEEEE") + 1;

        line(x, 0, x, y);

        outtextxy(x + indent_x, indent_y, script[3]);
        outtextxy(x + indent_x, indent_y + textheight("E"), "10^4km");

        x += 2 * indent_x + textwidth("EEEEEE") + 1;

        line(x, 0, x, y);

        outtextxy(x + indent_x, indent_y, script[4]);
        outtextxy(x + indent_x, indent_y + textheight("E"), "ly");

        x += 2 * indent_x + textwidth("EEEEEEEE") + 1;

        line(x, 0, x, y);

        outtextxy(x + indent_x, indent_y, script[5]);

        y = 2 * indent_y + 2 * textheight("E") + 1;

        line(0, y, x_m, y);

        y = dawn_border;

        line(0, y, x_m, y);

        char buffer[5];

        int_to_string(page + 1, 0, buffer);

        strcpy(str, "Page ");
        strcat(str, buffer);
        strcat(str, ". ");
        strcat(str, script[13]);

        outtextxy((x_m - textwidth(str)) / 2, dawn_border + indent_y, str);

        for (data *i = get_element(page * 10, a),
             *e = page * 10 + 9 > a->size_base - 1 ? get_element(a->size_base - 1, a) : get_element(page * 10 + 9, a);
             i <= e; i ++)
        {
            y = up_border + indent_y + (i - get_element(page * 10, a)) * (indent_y + textheight("E"));
            x = indent_x;

            int_to_string(i - a->element + 1, 0, str);
            outtextxy(x, y, str);

            x += 2 * indent_x + textwidth("EEEE") + 1;

            char str_name[11];
            int str_size = 10 > strlen(i->name) ? strlen(i->name) : 10;

            strncpy(str_name, i->name, str_size);
            str_name[str_size] = '\0';
            outtextxy(x, y, str_name);

            x += 2 * indent_x + textwidth("EEEEEEEEEE") + 1;

            int_to_string(i->year_open, 0, str);
            outtextxy(x, y, str);

            x += 2 * indent_x + textwidth("EEEE") + 1;

            double_to_string(i->mass, 3, str);
            outtextxy(x, y, str);

            x += 2 * indent_x + textwidth("EEEEEEEEEEE") + 1;

            double_to_string(i->radius, 2, str);
            outtextxy(x, y, str);

            x += 2 * indent_x + textwidth("EEEEEE") + 1;

            int_to_string(i->light_year, 0, str);
            outtextxy(x, y, str);

            x += 2 * indent_x + textwidth("EEEEEEEE") + 1;

            strcpy(str, script[i->type + 8]);

            outtextxy(x, y, str);
        }

        if((key_pass = readkey()) == 0)
            key_pass = readkey();

        if (key_pass == KEY_ENTER)
            cont = 0;

        if (key_pass == KEY_LEFT && page > 0)
            page --;

        if (key_pass == KEY_RIGHT && page * 10 + 10 < a->size_base)
            page ++;
    }

    cleardevice();
}

/* The function performs graphical input of the database "a" element.
 */
void insert_element (database *a)
{
    int x_m, y_m, indent_x, indent_y, up_border, repeat, x, y, rect_size_x, rect_size_y, rect1_size_x;
    char key_pass, str[29], longer[37];
    data b;

    repeat = 1;
    longer[36] = '\0';
    x_m = state.x_m;
    y_m = state.y_m;
    indent_x = state.indent_x;
    indent_y = state.indent_y;
    up_border = print_header(x_m - 2 * indent_x, 5 * indent_y, "DataBase. Inserting an element.");

    for (int i = 0; i < 36; i ++)
        longer[i] = 'E';

    settextsize(x_m - 10 * indent_x - 6, (y_m - up_border - 24 * indent_y - 18) / 9, longer);

    rect_size_y = textheight("E") + 2 * indent_y + 2;
    rect_size_x = 28 * textwidth("E") + 2 * indent_x + 2;
    rect1_size_x = 12 * textwidth("E") + 2 * indent_x + 2;

    while (repeat)
    {
        x = 2 * indent_x + textwidth(script[1]);
        y = up_border - rect_size_y;

        for (int i = 0; i < 5; i ++)
        {
            y += indent_y + rect_size_y;

            setcolor(WHITE);
            outtextxy(indent_x, y + indent_y + 1, script[i]);
            draw_button(x, y, rect_size_x, rect_size_y, BLACK, WHITE, WHITE, "");
        }

        x = indent_x;
        y = up_border + 7 * indent_y + 5 * rect_size_y + 1;

        outtextxy(x, y, script[5]);

        for (int i = 0; i < 5; i ++)
        {
            x = indent_x + (i % 2) * (rect1_size_x + indent_x);
            y = up_border + 7 * indent_y + 6 * rect_size_y + (i / 2) * (indent_y + rect_size_y);

            draw_button(x, y, rect1_size_x, rect_size_y, BLACK, WHITE, WHITE, script[i + 8]);
        }

        x = -rect1_size_x;
        y = up_border + 12 * indent_y + 9 * rect_size_y;

        for (int i = 6; i < 9; i ++)
        {
            int num_script = i == 8 ? 17 : i;

            x += rect1_size_x + indent_x;

            draw_button(x, y, rect1_size_x, rect_size_y, BLACK, WHITE, WHITE, script[num_script]);
        }

        input(3 * indent_x + textwidth(script[1]) + 1, up_border + 2 * indent_y + 1, 28, str, "");
        b.name = malloc(strlen(str) * sizeof(char) + 1);

        if (*str == '\0')
        {
            repeat = 0;
            break;
        }

        strcpy(b.name, str);

        if(input_int(3 * indent_x + textwidth(script[1]) + 1, up_border + textheight("E") + 5 * indent_y + 3, &b.year_open))
        {
            repeat = 0;
            break;
        }

        b.mass = input_double(3 * indent_x + textwidth(script[1]) + 1, up_border + 2 * textheight("E") + 8 * indent_y + 5);

        if (b.mass != b.mass)
        {
            repeat = 0;
            break;
        }

        b.radius = input_double(3 * indent_x + textwidth(script[1]) + 1, up_border + 3 * textheight("E") + 11 * indent_y + 7);

        if (b.radius != b.radius)
        {
            repeat = 0;
            break;
        }

        if(input_int(3 * indent_x + textwidth(script[1]) + 1, up_border + 4 * textheight("E") + 14 * indent_y + 9, &b.light_year))
        {
            repeat = 0;
            break;
        }

        int bool_type = 1, num_but = 0;

        x = indent_x + (num_but % 2) * (rect1_size_x + indent_x);
        y = up_border + 7 * indent_y + 6 * rect_size_y + (num_but / 2) * (indent_y + rect_size_y);

        draw_button(x, y, rect1_size_x, rect_size_y, WHITE, BLACK, WHITE, script[num_but + 8]);

        while (bool_type)
        {
            if((key_pass = readkey()) == 0)
                key_pass = readkey();

            x = indent_x + (num_but % 2) * (rect1_size_x + indent_x);
            y = up_border + 7 * indent_y + 6 * rect_size_y + (num_but / 2) * (indent_y + rect_size_y);

            draw_button(x, y, rect1_size_x, rect_size_y, BLACK, WHITE, WHITE, script[num_but + 8]);

            if (key_pass == KEY_ENTER)
            {
                switch (num_but)
                {
                    case 0:
                        b.type = T_GAS_GIANT;
                        break;

                    case 1:
                        b.type = T_NEPTUNE_LIKE;
                        break;

                    case 2:
                        b.type = T_SUPER_EARTH;
                        break;

                    case 3:
                        b.type = T_TERRESTRIAL;
                        break;

                    case 4:
                        b.type = T_UNKNOWN;
                        break;
                }

                bool_type = 0;
            }

            if (key_pass == KEY_LEFT && num_but > 0)
                num_but --;

            if (key_pass == KEY_RIGHT && num_but < 4)
                num_but ++;

            x = indent_x + (num_but % 2) * (rect1_size_x + indent_x);
            y = up_border + 7 * indent_y + 6 * rect_size_y + (num_but / 2) * (indent_y + rect_size_y);

            draw_button(x, y, rect1_size_x, rect_size_y, WHITE, BLACK, WHITE, script[num_but + 8]);
        }

        draw_button(x, y, rect1_size_x, rect_size_y, BLACK, WHITE, WHITE, script[num_but + 8]);

        bool_type = 1;
        num_but = 0;

        x = indent_x + num_but * (rect1_size_x + indent_x);
        y = up_border + 12 * indent_y + 9 * rect_size_y;

        draw_button(x, y, rect1_size_x, rect_size_y, WHITE, BLACK, WHITE, script[num_but == 2 ? 17 : num_but + 6]);

        while (bool_type)
        {
            if((key_pass = readkey()) == 0)
                key_pass = readkey();

            x = indent_x + num_but * (rect1_size_x + indent_x);
            y = up_border + 12 * indent_y + 9 * rect_size_y;

            draw_button(x, y, rect1_size_x, rect_size_y, BLACK, WHITE, WHITE, script[num_but == 2 ? 17 : num_but + 6]);

            if (key_pass == KEY_ENTER)
            {
                switch (num_but)
                {
                    case 0:
                        if (database_incert(a, &b))
                        {
                            bool_type = 0;

                            output(state.indent_x, state.indent_y, "Error incert!");
                        }
                        break;

                    case 1:
                        bool_type = 0;
                        break;

                    case 2:
                        bool_type = 0;
                        repeat = 0;
                        break;
                }
            }

            if (key_pass == KEY_LEFT && num_but > 0)
                num_but --;

            if (key_pass == KEY_RIGHT && num_but < 2)
                num_but ++;

            x = indent_x + num_but * (rect1_size_x + indent_x);
            y = up_border + 12 * indent_y + 9 * rect_size_y;

            draw_button(x, y, rect1_size_x, rect_size_y, WHITE, BLACK, WHITE, script[num_but == 2 ? 17 : num_but + 6]);
        }
    }

    free(b.name);

    cleardevice();
}

/* The function deletes the database "a" element by index.
 * If you enter 0, all the elements will be deleted.
 */
void delete_element (database *a)
{
    int x_m, indent_x, indent_y, up_border, x, y, num_element, rect_size_x, rect_size_y;

    x_m = state.x_m;
    indent_x = state.indent_x;
    indent_y = state.indent_y;
    rect_size_x = 5 * textwidth("E") + 2 * indent_x + 2;
    rect_size_y = textheight("E") + 2 * indent_y + 2;
    up_border = print_header(x_m - 2 * indent_x, 5 * indent_y, "DataBase. Deleting an element.");
    x = 2 * indent_x + textwidth(script[14]);
    y = up_border + indent_y;

    setcolor(WHITE);
    outtextxy(indent_x, y + indent_y + 1, script[14]);
    draw_button(x, y, rect_size_x, rect_size_y, BLACK, WHITE, WHITE, "");

    if (input_int(x + 2 * indent_x + 1, y + indent_y + 1, &num_element))
        num_element = a->size_base + 1;

    if(database_delete(a, num_element))
        output(indent_x, indent_y, "The element cannot be deleted!");
    else
        output(indent_x, indent_y, "Element deleted.");

    cleardevice();
}

/* The function writes the database "a" from the file.
 */
void read_database_file (database *a)
{
    int x_m, indent_x, indent_y, up_border, x, y, rect_size_x, rect_size_y;
    char file_name[28];

    x_m = state.x_m;
    indent_x = state.indent_x;
    indent_y = state.indent_y;
    rect_size_x = 28 * textwidth("E") + 2 * indent_x + 2;
    rect_size_y = textheight("E") + 2 * indent_y + 2;
    up_border = print_header(x_m - 2 * indent_x, 5 * indent_y, "DataBase. Reading from a file.");
    x = 2 * indent_x + textwidth(script[16]);
    y = up_border + indent_y;

    setcolor(WHITE);
    outtextxy(indent_x, y + indent_y + 1, script[16]);
    draw_button(x, y, rect_size_x, rect_size_y, BLACK, WHITE, WHITE, "");

    input(x + indent_x + 1, y + indent_y + 1, 28, file_name, "");

    if (read_file(file_name, a))
        output(indent_x, indent_y, "File reading error!");
    else
        output(indent_x, indent_y, "Reading the file successfully.");

    cleardevice();
}

/* The function outputs the database "a" to a file.
 */
void output_database_file (database *a)
{
    int x_m, indent_x, indent_y, up_border, x, y, rect_size_x, rect_size_y;
    char file_name[28];

    x_m = state.x_m;
    indent_x = state.indent_x;
    indent_y = state.indent_y;
    rect_size_x = 28 * textwidth("E") + 2 * indent_x + 2;
    rect_size_y = textheight("E") + 2 * indent_y + 2;
    up_border = print_header(x_m - 2 * indent_x, 5 * indent_y, "DataBase. Output to a file.");
    x = 2 * indent_x + textwidth(script[16]);
    y = up_border + indent_y;

    setcolor(WHITE);
    outtextxy(indent_x, y + indent_y + 1, script[16]);
    draw_button(x, y, rect_size_x, rect_size_y, BLACK, WHITE, WHITE, "");

    input(x + indent_x + 1, y + indent_y + 1, 28, file_name, "");

    if (output_file(file_name, a))
        output(indent_x, indent_y, "Error writing to file!");
    else
        output(indent_x, indent_y, "Write to file successfully.");

    cleardevice();
}

/* The function sorts the database "a" by the selected field.
 */
void q_sort_database (database *a)
{
    if (!(a->size_base))
        return;

    int x_m, indent_x, indent_y, up_border, x, y, cont, num_but, answer, rect_size_x, rect_size_y;
    char key_pass;
    comparison F;

    cont = 1;
    num_but = 0;
    answer = 0;
    x_m = state.x_m;
    indent_x = state.indent_x;
    indent_y = state.indent_y;
    up_border = print_header(x_m - 2 * indent_x, 5 * indent_y, "DataBase. Sorting the database.");
    rect_size_x = 9 * textwidth("E") + 2 * indent_x + 2;
    rect_size_y = textheight("E") + 2 * indent_y + 2;

    x = (x_m - rect_size_x) / 2;
    y = up_border - rect_size_y;

    for (int i = 0; i < 6; i ++)
    {
        y += indent_y + rect_size_y;

        draw_button(x, y, rect_size_x, rect_size_y, BLACK, WHITE, WHITE, script[i]);
    }

    while (cont)
    {
        if((key_pass = readkey()) == 0)
            key_pass = readkey();

        x = (x_m - rect_size_x) / 2;
        y = up_border + indent_y + num_but * (indent_y + rect_size_y);

        draw_button(x, y, rect_size_x, rect_size_y, BLACK, WHITE, WHITE, script[num_but]);

        if (key_pass == KEY_ENTER)
        {
            char sort_of[] = "UP - ascending order. DOWN - descending order.";

            x = (x_m - textwidth(sort_of)) / 2;
            y = up_border + 8 * indent_y + 6 * rect_size_y;

            outtextxy(x, y, sort_of);

            while (key_pass != KEY_UP && key_pass != KEY_DOWN)
                if((key_pass = readkey()) == 0)
                    key_pass = readkey();

            int kind_sort;

            if (key_pass == KEY_UP)
                kind_sort = 1;
            else
                kind_sort = 0;

            switch (num_but)
            {
                case 0:
                    if (kind_sort)
                        F = comp_name_up;
                    else
                        F = comp_name_down;

                    if(q_sort(a, F))
                        answer = 1;

                    break;

                case 1:
                    if (kind_sort)
                        F = comp_year_open_up;
                    else
                        F = comp_year_open_down;

                    if(q_sort(a, F))
                        answer = 1;

                    break;

                case 2:
                    if (kind_sort)
                        F = comp_mass_up;
                    else
                        F = comp_mass_down;

                    if(q_sort(a, F))
                        answer = 1;

                    break;

                case 3:
                    if (kind_sort)
                        F = comp_radius_up;
                    else
                        F = comp_radius_down;

                    if(q_sort(a, F))
                        answer = 1;

                    break;

                case 4:
                    if (kind_sort)
                        F = comp_light_year_up;
                    else
                        F = comp_light_year_down;

                    if(q_sort(a, F))
                        answer = 1;

                    break;

                case 5:
                    if (kind_sort)
                        F = comp_type_up;
                    else
                        F = comp_type_down;

                    if(q_sort(a, F))
                        answer = 1;

                    break;
            }

            cont = 0;
        }

        if (key_pass == KEY_UP && num_but > 0)
            num_but --;

        if (key_pass == KEY_DOWN && num_but < 5)
            num_but ++;

        x = (x_m - rect_size_x) / 2;
        y = up_border + indent_y + num_but * (indent_y + rect_size_y);

        draw_button(x, y, rect_size_x, rect_size_y, WHITE, BLACK, WHITE, script[num_but]);
    }

    if (answer)
        output(indent_x, indent_y, "Sorting error!");
    else
        output(indent_x, indent_y, "Sorting is successful.");

    cleardevice();
}

/* The function outputs the database "a" field (begin from "element")
 * in the form of a bar chart (the symbol "data_type" defines the data type of the elements).
 * f - comparison function.
 */
void bar_chart (void *element, database *a, char data_type, comparison f)
{
    cleardevice();

    if (!(a->size_base))
        return;

    int x_m, y_m, indent_x, indent_y, up_border, x, y, x1, y1, cont, page, bar_size_x, max_bar_size_y;
    char key_pass, str[28];
    data *max_el;
    void *max_element;

    cont = 1;
    page = 0;
    x_m = state.x_m;
    y_m = state.y_m;
    indent_x = state.indent_x;
    indent_y = state.indent_y;
    bar_size_x = (int)(0.6 * x_m / 10);
    max_bar_size_y = (int)(0.5 * y_m);
    max_el = found_max_element(a, f);
    max_element = (void*)max_el + (element - (void*)a->element);

    while (cont)
    {
        cleardevice();

        up_border = print_header(x_m - 2 * indent_x, 5 * indent_y, "DataBase. Bar chart.");

        char buffer[5];

        int_to_string(page + 1, 0, buffer);

        strcpy(str, "Page ");
        strcat(str, buffer);
        strcat(str, ". ");
        strcat(str, script[13]);

        setcolor(WHITE);

        settextsize(x_m - 2 * indent_x, 5 * indent_y, str);

        outtextxy((x_m - textwidth(str)) / 2, y_m - indent_y - textheight("E"), str);

        settextsize((int)(0.12 * x_m), (int)(0.12 * y_m), "log10(n)");

        x = indent_x;
        y = up_border + indent_x;

        outtextxy(x, y, "log10(n)");

        y += indent_y + textheight("E");

        int nx, nx1;

        if (data_type == 'd')
            nx = 0, nx1 = 0;

        if (data_type == 'f')
        {
            if (element == &a->element->mass)
                nx = 24, nx1 = 1;
            else
                nx = 4, nx1 = 1;
        }

        for (int i = 0; i < 5; i ++)
        {
            if (data_type == 'd')
                double_to_string(log10((double)(*((int*)max_element))) * (1.0 - (double)i / 5) + nx - (double)i / 5 * nx1, 2, str);

            if (data_type == 'f')
                double_to_string(log10(*((double*)max_element)) * (1.0 - (double)i / 5) + nx - (double)i / 5 * nx1, 2, str);

            outtextxy(x, y + i * (max_bar_size_y + 2 * indent_y + 2) / 5, str);
        }

        x += indent_x + textwidth("log10(n)") - bar_size_x;
        y += max_bar_size_y;

        rectangle(x + bar_size_x, y - max_bar_size_y, x + 2 * indent_x + 11 * bar_size_x + 1, y + 2 * indent_y + 1);

        x += indent_x + 1;
        y += indent_y + 1;
        x1 = x + 2 * indent_x + 11 * bar_size_x + 1;
        y1 = y - max_bar_size_y;

        for (data *i = get_element(page * 10, a),
             *e = page * 10 + 9 > a->size_base - 1 ? get_element(a->size_base - 1, a) : get_element(page * 10 + 9, a);
             i <= e; i ++)
        {
            x += bar_size_x;
            y1 += textheight("E") + indent_y;

            char str_name[11];
            int str_size = 10 > strlen(i->name) ? strlen(i->name) : 10;

            strncpy(str_name, i->name, str_size);
            str_name[str_size] = '\0';

            setcolor(WHITE);

            outtextxy(x1 + indent_x + textwidth("E"), y1, str_name);

            setfillstyle(SOLID_FILL, (i - get_element(page * 10, a)) + 1);

            bar(x1, y1, x1 + textwidth("E"), y1 + textwidth("E"));

            int y_up;

            if (data_type == 'f')
            {
                double mean_element = *((double*)(element + ((void*)i - (void*)get_element(0, a))));

                if (mean_element == 0)
                    continue;

                y_up = y - (int)((log10(mean_element) + nx1) / (log10(*((double*)max_element)) + nx1) * max_bar_size_y);
            }

            if (data_type == 'd')
            {
                int mean_element = *((int*)(element + ((void*)i - (void*)get_element(0, a))));

                if (mean_element == 0)
                    continue;

                y_up = y - (int)((log10((double)mean_element) + nx1) / (log10((double)(*((int*)max_element))) + nx1) * max_bar_size_y);
            }

            bar(x, y_up, x + bar_size_x - 1, y);
        }

        if((key_pass = readkey()) == 0)
            key_pass = readkey();

        if (key_pass == KEY_ENTER)
            cont = 0;

        if (key_pass == KEY_LEFT && page > 0)
            page --;

        if (key_pass == KEY_RIGHT && page * 10 + 10 < a->size_base)
            page ++;
    }
}

/* The function of graphical selection of the database "a" output field in the form of a bar chart.
 */
void bar_chart_begin (database *a)
{
    int x_m, indent_x, indent_y, up_border, x, y, cont, num_but, rect_size_x, rect_size_y;
    char key_pass;
    comparison F;

    cont = 1;
    num_but = 2;
    x_m = state.x_m;
    indent_x = state.indent_x;
    indent_y = state.indent_y;
    up_border = print_header(x_m - 2 * indent_x, 5 * indent_y, "DataBase. Bar chart.");
    rect_size_x = 9 * textwidth("E") + 2 * indent_x + 2;
    rect_size_y = textheight("E") + 2 * indent_y + 2;

    x = (x_m - rect_size_x) / 2;
    y = up_border - rect_size_y;

    for (int i = 2; i < 5; i ++)
    {
        y = y + indent_y + rect_size_y;

        draw_button(x, y, rect_size_x, rect_size_y, BLACK, WHITE, WHITE, script[i]);
    }

    while (cont)
    {
        if((key_pass = readkey()) == 0)
            key_pass = readkey();

        x = (x_m - rect_size_x) / 2;
        y = up_border + indent_y + (num_but - 2) * (indent_y + rect_size_y);

        draw_button(x, y, rect_size_x, rect_size_y, BLACK, WHITE, WHITE, script[num_but]);

        if (key_pass == KEY_ENTER)
        {
            switch (num_but)
            {
                case 2:
                    F = comp_mass_up;

                    bar_chart((void*)(&a->element->mass), a, 'f', F);

                    break;

                case 3:
                    F = comp_radius_up;

                    bar_chart((void*)(&a->element->radius), a, 'f', F);

                    break;

                case 4:
                    F = comp_light_year_up;

                    bar_chart((void*)(&a->element->light_year), a, 'd', F);

                    break;
            }

            cont = 0;
        }

        if (key_pass == KEY_UP && num_but > 2)
            num_but --;

        if (key_pass == KEY_DOWN && num_but < 4)
            num_but ++;

        x = (x_m - rect_size_x) / 2;
        y = up_border + indent_y + (num_but - 2) * (indent_y + rect_size_y);

        draw_button(x, y, rect_size_x, rect_size_y, WHITE, BLACK, WHITE, script[num_but]);
    }

    cleardevice();
}

/* The function of graphical output of the database "a" in the form of a pie chart.
 */
void pie_chart (database *a)
{
    if (!(a->size_base))
        return;

    int x_m = state.x_m, y_m = state.y_m, indent_x = state.indent_x, indent_y = state.indent_y, x, y;
    int up_border = print_header(x_m - 2 * indent_x, 5 * indent_y, "DataBase. Pie chart.");
    int radius = (int)(fmin(0.3 * x_m, 0.4 * y_m)), angel = 0, next_angel;
    size_t type_chart[5] = {}, num = a->size_base;

    angel = 0;
    x_m = state.x_m;
    y_m = state.y_m;
    indent_x = state.indent_x;
    indent_y = state.indent_y;
    up_border = print_header(x_m - 2 * indent_x, 5 * indent_y, "DataBase. Pie chart.");
    radius = (int)(fmin(0.3 * x_m, 0.4 * y_m));
    num = a->size_base;

    for (const data *i = get_element_const(0, a),
         *e = get_element_const(a->size_base - 1, a);
         i <= e; i ++)
        type_chart[i->type] ++;

    x = 2 * (indent_x + radius);
    y = up_border + indent_y;

    for (int i = 0; i < 5; i ++)
    {
        y += textheight("E") + indent_y;

        setfillstyle(SOLID_FILL, i + 1);
        bar(x, y, x + textwidth("E"), y + textwidth("E"));

        next_angel = i == 4 ? 360 : angel + (int)((double)type_chart[i] * 360 / num);

        setcolor(i + 1);
        pieslice(indent_x + radius, up_border + indent_y + radius, angel, next_angel, radius);

        angel = next_angel;

        setcolor(WHITE);
        outtextxy(x + textwidth("E") + indent_x, y, script[8 + i]);
    }

    char key_pass = KEY_DOWN, str[28];

    strcpy(str, script[13]);

    setcolor(WHITE);

    settextsize(x_m - 2 * indent_x, 5 * indent_y, str);

    outtextxy((x_m - textwidth(str)) / 2, y_m - indent_y - textheight("E"), str);

    while (key_pass != KEY_ENTER)
        if((key_pass = readkey()) == 0)
            key_pass = readkey();

    cleardevice();
}

int data_interface (int h, int w)
{
    if (h < 479 || w < 639 || 3 * w < 4 * h || 9 * w > 16 * h)
        return 1;

    int gd = CUSTOM, gm = CUSTOM_MODE(w, h);
    database *base = database_alloc();

    initgraph(&gd, &gm, "");

    int x_m, y_m, indent_x, indent_y, x, y, up_border, rect_size_x, rect_size_y;
    const char selection_lines[] = "Inserting an element\0"
                                   "Deleting an item\0"
                                   "Sorting the array\0"
                                   "Displaying the database\0"
                                   "Reading from a file\0"
                                   "Output an array to a file\0"
                                   "Bar chart\0"
                                   "Pie chart\0"
                                   "End the program\0";
    const char *signature[9] = {selection_lines, selection_lines + 21,
                                selection_lines + 38, selection_lines + 56,
                                selection_lines + 80, selection_lines + 100,
                                selection_lines + 126, selection_lines + 136,
                                selection_lines + 146};
    const char longest[] = "Output an array to a file";

    x_m = state.x_m = getmaxx();
    y_m = state.y_m = getmaxy();
    indent_x = state.indent_x = (int)(0.01 * x_m);
    indent_y = state.indent_y = (int)(0.01 * y_m);
    up_border = print_header(x_m - 2 * indent_x, 5 * indent_y, "DataBase. Home page.");

    settextsize((x_m - 8 * indent_x) / 2, (y_m - up_border - 15 * indent_y) / 5, longest);

    rect_size_x = textwidth(longest) + 2 * indent_x + 2;
    rect_size_y = textheight("E") + 2 * indent_y + 2;

    for (int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < 4; j ++)
        {
            x = x_m / 2 - rect_size_x - indent_x + i * (rect_size_x + 2 * indent_x);
            y = up_border + indent_y + j * (rect_size_y + indent_y);

            draw_button(x, y, rect_size_x, rect_size_y, BLACK, WHITE, WHITE, signature[4 * i + j]);
        }
    }

    x = x_m / 2 - rect_size_x - indent_x;
    y = up_border + 5 * indent_y + 4 * rect_size_y;

    draw_button(x, y, 2 * (rect_size_x + indent_x), rect_size_y, WHITE, BLACK, WHITE, signature[8]);

    char key_pass;
    int num_col = 1, num_str = 4, cont = 1;

    while(cont)
    {
        if((key_pass = readkey()) == 0)
            key_pass = readkey();

        if (num_col == 1 && num_str == 4)
        {
            x = x_m / 2 - rect_size_x - indent_x;
            y = up_border + 5 * indent_y + 4 * rect_size_y;

            draw_button(x, y, 2 * (rect_size_x + indent_x), rect_size_y, BLACK, WHITE, WHITE, signature[8]);
        }
        else
        {
            x = x_m / 2 - rect_size_x - indent_x + num_col * (rect_size_x + 2 * indent_x);
            y = up_border + indent_y + num_str * (rect_size_y + indent_y);

            draw_button(x, y, rect_size_x, rect_size_y, BLACK, WHITE, WHITE, signature[4 * num_col + num_str]);
        }

        switch (key_pass)
        {
            case KEY_UP:
                if(num_str > 0)
                    num_str --;
                break;

            case KEY_DOWN:
                if(num_str < 4 && (num_col != 0 || num_str != 3))
                    num_str ++;
                else if (num_str == 3 && num_col == 0)
                    num_col = 1, num_str = 4;
                break;

            case KEY_RIGHT:
                if(num_col < 1)
                    num_col ++;
                break;

            case KEY_LEFT:
                if(num_col > 0 && num_str != 4)
                    num_col --;
                break;

            case KEY_ENTER:
                setvisualpage(1);
                setactivepage(1);

                switch ((num_col == 1 && num_str == 4) ? 8 : num_col * 4 + num_str)
                {
                    case 0:
                        insert_element(base);
                        break;

                    case 1:
                        delete_element(base);
                        break;

                    case 2:
                        q_sort_database(base);
                        break;

                    case 3:
                        database_output_screen(base);
                        break;

                    case 4:
                        read_database_file(base);
                        break;

                    case 5:
                        output_database_file(base);
                        break;

                    case 6:
                        bar_chart_begin(base);
                        break;

                    case 7:
                        pie_chart(base);
                        break;

                    case 8:
                        cont = 0;
                        break;
                }

                setvisualpage(0);
                setactivepage(0);

                break;
        }

        settextsize((x_m - 8 * indent_x) / 2, (y_m - up_border - 15 * indent_y) / 5, longest);

        if (num_col == 1 && num_str == 4)
        {
            x = x_m / 2 - rect_size_x - indent_x;
            y = up_border + 5 * indent_y + 4 * rect_size_y;

            draw_button(x, y, 2 * (rect_size_x + indent_x), rect_size_y, WHITE, BLACK, WHITE, signature[8]);
        }
        else
        {
            x = x_m / 2 - rect_size_x - indent_x + num_col * (rect_size_x + 2 * indent_x);
            y = up_border + indent_y + num_str * (rect_size_y + indent_y);

            draw_button(x, y, rect_size_x, rect_size_y, WHITE, BLACK, WHITE, signature[4 * num_col + num_str]);
        }
    }

    closegraph();

    database_free(base);

    return 0;
}
