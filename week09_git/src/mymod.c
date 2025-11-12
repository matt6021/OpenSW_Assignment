#include <stdio.h>

double mymod(double a, double b) {
    printf("This is mymod().\n");
    if (b == 0.0) {
        printf("Error: modulo by zero\n");
        return 0.0;
    }
    long long q = (long long)(a / b);   
    return a - (double)q * b;           
}
