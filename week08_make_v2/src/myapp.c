#include <stdio.h>
#include <string.h>
#include "basic_ops.h"
#include "advanced_ops.h"

static double calculate(const char* op,double a,double b){
    if(!strcmp(op,"+")) return add(a,b);
    else if(!strcmp(op,"-")) return sub(a,b);
    else if(!strcmp(op,"*")) return mul(a,b);
    else if(!strcmp(op,"/")) return div(a,b);
    else if(!strcmp(op,"%")) return mymod(a,b);
    else if(!strcmp(op,"^")) return mypow(a,b);
    printf("Unsupported operation: %s\n", op);
    return 0.0;
}
int main(void){
    double a,b; char op[4];
    printf("Enter calculation (e.g., 1 + 2): ");
    if (scanf("%lf %3s %lf", &a, op, &b) != 3) return 1;
    printf("Result = %.2lf\n", calculate(op,a,b));
    return 0;
}
