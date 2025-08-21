#include <iostream>
#include <omp.h>
using namespace std;

double f(double x) {
    return x * x;
}

double trapezoid(double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (f(a) + f(b)) / 2.0;

    #pragma omp parallel for reduction(+:integral)
    for (int i = 1; i < n; ++i) {
        integral += f(a + i * h);
    }

    integral *= h;
    return integral;
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 1000000;
    double result = trapezoid(a, b, n);
    cout << "Integral result: " << result << endl;
    return 0;
}