#include <stdio.h>
#include <string.h>
#include "basic_ops.h"

static double calculate(char* op,double a,double b){
    if(strcmp(op,"+") == 0){
        return add(a,b);
    }
    else if(strcmp(op,"-") == 0){
        return sub(a,b);
    }
    else if(strcmp(op,"*") == 0){
        return mul(a,b);
    }
    else if(strcmp(op,"/") == 0){
        return div(a,b);
    }
    else{
        printf("Unsupported operation : %s\n",op);
        return 0.0;
    }
}

int main(void){
    double a,b;
    char op[4];

    printf("Enter expression (e.g., 1 + 2) : ");
    if(scanf("%lf %s %lf",&a,op,&b) != 3) return 1;;
    printf("Result = %.2lf\n",calculate(op,a,b));
    return 0;
}