/* Laboratory work 21.1a.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 */

#include <stdio.h>
#include <stdlib.h>
#include "Sierpinski_triangle.h"

int main()
{
    int height = 720, width = 1280;

    if (fract(height, width))
        return 1;

    return 0;
}
