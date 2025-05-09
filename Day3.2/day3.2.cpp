#include <iostream>

// ����΢�ַ����Ҳ�ĺ���
double f(double x, double y) {
    return -2 * x + 1;
}

// �Ľ���ŷ���������΢�ַ���
double improvedEulerMethod(double x0, double y0, double h, int numSteps) {
    double x = x0;
    double y = y0;
    for (int i = 0; i < numSteps; i++) {
        double y_temp = y + h * f(x, y);
        y = y + h / 2 * (f(x, y) + f(x + h, y_temp));
        x += h;
    }
    return y;
}

int main() {
    double x0 = 0;
    double y0 = 1;
    double h = 0.1;
    int numSteps = 10;

    double result = improvedEulerMethod(x0, y0, h, numSteps);
    std::cout << "Numerical solution: " << result << std::endl;

    return 0;
}