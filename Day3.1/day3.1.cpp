#include <iostream>

double f(double x, double y) {
    return x + y;
}

double rk4(double x, double y, double h) {
    double k1 = h * f(x, y);
    double k2 = h * f(x + 0.5 * h, y + 0.5 * k1);
    double k3 = h * f(x + 0.5 * h, y + 0.5 * k2);
    double k4 = h * f(x + h, y + k3);
    return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}

int main() {
    double x0 = 0;
    double y0 = 1;
    double h = 0.1;
    double x_end = 1;

    while (x0 < x_end) {
        y0 = rk4(x0, y0, h);
        x0 += h;
    }

    std::cout << "Approximate solution at x = 1: " << y0 << std::endl;

    return 0;
}
