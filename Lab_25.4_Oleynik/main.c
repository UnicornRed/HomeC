/* Laboratory work 25.4.
 * Author: Oleynik Mikhail. Group: 20.B05-mm
 */

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAX_STRING_SIZE 100

int main()
{
    char str[MAX_STRING_SIZE];
    double result;
    int error = 0;

    reminder();

    printf("Enter the calculated expression:\n");

    if (input_str(str, MAX_STRING_SIZE))
    {
        printf("Error! Line size exceeded!\n");

        return 1;
    }

    result = calculate(str, &error);

    if (error)
    {
        switch (error)
        {
            case 1:
                printf("Pointer transmission error!\n");
                break;

            case 2:
                printf("Error! Incorrect string format!\n");
                break;

            case 3:
                printf("Memory allocation error!\n");
                break;

            case 4:
                printf("Out of the scope of the function definition!\n");
                break;
        }

        return 1;
    }
    else
        printf("Result: %f", result);

    return 0;
}
