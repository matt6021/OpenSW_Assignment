#include <stdio.h>

double mydiv(double a, double b) {

    printf("This is mydiv().\n");

    if (b == 0.0) {
        
        printf("Error: divide by zero\n");
        return 0.0;
    }

    return a / b;

}
