#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

int main()

{

	double a = 1, b = 3;      //a,b表示[a,b]求解区间

	double x0 = 1, y0 = 2;      //x0表示初始时刻x的值，y0表示初始时刻y的值

	double x, y;      //x,y分别表示变化的时候x，y的值

	double F1, F2, F3, F4;      //F1,F2,F3,F4分别表示斜率值

	double h = 1.0f / 128;      //h表示步长

	cout<< setiosflags(ios::left)
		<< setw(25) << "x的值"
		<< setw(25) << "龙格库塔计算得到的值"
		<< setw(25) << "解析解得到的值"
		<< setw(25) << "误差" << endl;

	x = x0;

	y = y0;

	cout? << setw(25) << x
		<< setw(25) << y
		<< setw(25) << y0
		<< setw(25) << abs(y0 - y) << endl;

	do
	{

		F1 = h * pow(x, -2) * (x * y - y * y);
		F2 = h * pow(x + h / 2, -2) * ((x + h / 2) * (y + F1 / 2) - (y + F1 / 2) * (y + F1 / 2));
		F3 = h * pow(x + h / 2, -2) * ((x + h / 2) * (y + F2 / 2) - (y + F2 / 2) * (y + F2 / 2));
		F4 = h * pow(x + h, -2) * ((x + h) * (y + F3) - (y + F3) * (y + F3));

		y += (F1 + 2 * F2 + 2 * F3 + F4) / 6;
		x = x + h;

		cout << setw(25) << x

			<< setw(25) << y

			<< setw(25) << x / (1.0f / 2 + log(x))

			<< abs(x / (1.0f / 2 + log(x)) - y) << endl;

	} while (x <= b);

	return 0;
}