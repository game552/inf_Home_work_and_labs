#include <stdio.h>
#include <math.h>

double funck1(double x) {
    return x * (x - 1);
}

double funck2(double x) {
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

int main() {
    int n;

    printf("Enter number of segments n: ");
    if (scanf("%d", &n) != 1){
        printf("WRONG INPUT!!!");
        return 1;
    }

    double approx1 = INTPRG(0, 2, n, funck1);
    double approx2 = INTPRG(1, 2, n, funck2);

    double exact1 = 2.0 / 3.0;
    double exact2 = 3.0591165;

    printf("\n=== Integration Results ===\n");
    printf("n = %d\n\n", n);

    printf("Integral of x(x - 1) on [0, 2]\n");
    printf("  Approximate: %.10f\n", approx1);
    printf("  Exact:       %.10f\n", exact1);

    printf("Integral of exp(x)/x on [1, 2]\n");
    printf("  Approximate: %.10f\n", approx2);
    printf("  Exact:       %.10f\n", exact2);

    return 0;
}
