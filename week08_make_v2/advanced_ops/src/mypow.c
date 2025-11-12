double mypow(double a,double b){
    long long n=(long long)b; double base=a;
    if(n==0) return 1.0;
    double acc=1.0; long long e=(n<0)?-n:n;
    while(e--) acc*=base;
    return (n<0)?1.0/acc:acc;
}
