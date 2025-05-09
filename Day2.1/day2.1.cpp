#include <iostream> 
#include <iomanip> //头文件——该程序中主要为了保留小数点后几位
#include <cmath>//头文件——可以使用常用的数学函数

using namespace std;
double x[100];//定义每次跨越一步的x值； 
double y[100];//定义每个x值对应的初值y 
double yp[100];//定义一个预测值yp
double C;//定义y与yp的差值，便于后面调用 
double func_y(double x, double y, double c, double h);
//定义平均化形式的改进欧拉公式(加入了一个c变量
//这个变量好处在于可以将一个调用函数只要改变参数就可以求出yp和yc) 
double f_y;//定义调用函数的返回值yp 
double a;//定义x可行域的下限 
double b;//定义x可行域的上限 
double h;//步长； 
int I;
//定义步数
//这主要是由于区间长度能否被步长整除是不可知的
//由于要保证每次跨步要在x的定义域内，步数是不可知的
//这里通过每次跨步后的x的值与最右端点比较 当x值大于最右端点的值，结束求解。 

int main()
{
    cout << "输入x的上限" << endl;
    cin >> b;
    cout << "输入x的下限" << endl;
    cin >> a;
    cout << "输入x0" << endl;
    cin >> x[0];
    cout << "输入y0" << endl;
    cin >> y[0];
    cout << "输入步长" << endl;
    cin >> h;//输入模块；之后为计算在可行域内，以h的步长可以最多行进多少次； 
    for (int i = 1; x[0] + i * h <= b; i++)
        //这里通过每次跨步后的x的值与最右端点比较 当x值大于最右端点的值，结束循环
    {
        x[i] = x[0] + i * h;
        func_y(x[i - 1], y[i - 1], 0, h);//第一次调用求出预测值yp 
        yp[i] = f_y;
        C = y[i - 1] - f_y;
        //这个变量的主要作用是为了统一调用函数的参数个数
        //可以将一个调用函数只要改变参数就可以求出yp和yc
        func_y(x[i], yp[i], C, h);//第二次调用求出yc 
        y[i] = (yp[i] + f_y) / 2;//yp与yc的平均值为矫正值 
        I = i;
    }
    cout << "**********输出结果**********" << endl;
    cout << setiosflags(ios::fixed) << setprecision(5);//输出结果保留5位小数 
    cout << "    Xn " << "    预测值  " << "  校正值" << endl;
    for (int i = 1; i <= I; i++)
    {
        cout << " " << x[i] << " , " << yp[i] << " , " << y[i] << endl;
    }
    return 0;
}

double func_y(double x, double y, double c, double h)//定义平均化形式的改进欧拉公式yp 
{
    f_y = y + c + h * (pow(x, 3) * pow(y, 2) + 1);
    //修改新的求解函数时，只要改 (pow(x,3)*pow(y,2) + 1)括号里面的内容即可
    return f_y;
}