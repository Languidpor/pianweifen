#include<iostream>
#include<vector>
#include<cmath>
#include <iomanip>
using namespace std;

//牛顿迭代法求根
double fx(double x) {
	return pow(x, 3) - x - 1;
}
double dfx(double x) {
	return 3 * x * x - 1;
}
double fx1(double x) {
	return x * x - 115;
}
double dfx1(double x) {
	return 2 * x;
}
double newtown(double x0, int n, double eps) {
	//x0:迭代初值  n:迭代次数  esp:精度
	double x1 = x0;
	for (int i = 0; i < n; i++) {
		x1 = x0 - fx1(x0) / dfx1(x0);
		cout << setprecision(10) << x1 << endl;
		if (abs(x1 - x0) < eps) {
			return x1;
		}
		x0 = x1;
	}
	cout << "迭代失败" << endl;
	return 0;
}
int main() {
	cout << setprecision(10) << newtown(-5, 10, 0.000001);
	return 0;
}