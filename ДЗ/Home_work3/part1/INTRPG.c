#include "INTRPG.h"

double func1(double x) {
    return x * (x - 1);
}

double func2(double x) {
    return exp(x) / x;
}

double INTPRG(double a, double b, int n, double (*func)(double)) {
    double res  = 0.0;
    double size = (b - a) / n;

    for (int i = 1; i <= n; i++) {
        double x = a + i * size;
        res += func(x);
    }

    return res * size;
}