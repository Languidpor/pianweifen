#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

int main()

{

	double a = 1, b = 3;      //a,b��ʾ[a,b]�������

	double x0 = 1, y0 = 2;      //x0��ʾ��ʼʱ��x��ֵ��y0��ʾ��ʼʱ��y��ֵ

	double x, y;      //x,y�ֱ��ʾ�仯��ʱ��x��y��ֵ

	double F1, F2, F3, F4;      //F1,F2,F3,F4�ֱ��ʾб��ֵ

	double h = 1.0f / 128;      //h��ʾ����

	cout<< setiosflags(ios::left)
		<< setw(25) << "x��ֵ"
		<< setw(25) << "�����������õ���ֵ"
		<< setw(25) << "������õ���ֵ"
		<< setw(25) << "���" << endl;

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