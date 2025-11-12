#include <stdio.h>

double mypow(double a, double b) {
    printf("This is mypow().\n");
    long long n = (long long)b;   
    double r = 1.0;

    if (n < 0) {                  
        n = -n;
        while (n--) r *= a;
        return 1.0 / r;
    }
    while (n--) r *= a;
    return r;
}
