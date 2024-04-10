#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
    return x * x - 4*x - 8.95;
}

int main() {

    double a = 2, b = 3, c, tolerance = 0.01;
    int n = 0;
    float E = (a + b) / 2;

    if (f(a) == 0) {
        printf("La solution est : %f", a);
        return 0;
    }
    else if (f(b) == 0) {
        printf("La solution est : %f", b);
        return 0;
    }

    while (fabs(b - a) > tolerance) {
        c = (a + b) / 2;

        if (f(c) == 0 || fabs(b - a) / 2 < tolerance) {
            break;
        }
        else if (f(a) * f(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }

        n++;
    }

    printf("Apres %d iterations, l'approximation obtenue est %f et l'erreur maximale est %f", n, c, E);
    return 0;
}
