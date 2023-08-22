/* Laboratory work 27.2.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 * The module enters a string.
 */

#include <stdio.h>
#include <stdlib.h>
#include "input_str.h"

int input_str (char *str, size_t max_size)
{
    if (!str)
        return 1;

    char letter;
    int counter = 0;

    letter = getchar();

    if (letter != '\n')
    {
        str[counter] = letter;

        counter ++;
    }

    letter = '0';

    while (letter != '\n')
    {
        if (counter > max_size - 2)
            return 1;

        letter = getchar();
        str[counter] = letter;

        counter ++;
    }

    str[counter - 1] = '\0';

    return 0;
}
