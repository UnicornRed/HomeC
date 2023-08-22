/* Laboratory work 24.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 */

#include <stdlib.h>
#include <stdio.h>
#include "database.h"
#include "database_screen.h"

int main()
{
    int height = 720, width = 960;

    if(data_interface(height, width))
        return 1;

    return 0;
}
