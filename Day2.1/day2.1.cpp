#include <iostream> 
#include <iomanip> //ͷ�ļ������ó�������ҪΪ�˱���С�����λ
#include <cmath>//ͷ�ļ���������ʹ�ó��õ���ѧ����

using namespace std;
double x[100];//����ÿ�ο�Խһ����xֵ�� 
double y[100];//����ÿ��xֵ��Ӧ�ĳ�ֵy 
double yp[100];//����һ��Ԥ��ֵyp
double C;//����y��yp�Ĳ�ֵ�����ں������ 
double func_y(double x, double y, double c, double h);
//����ƽ������ʽ�ĸĽ�ŷ����ʽ(������һ��c����
//��������ô����ڿ��Խ�һ�����ú���ֻҪ�ı�����Ϳ������yp��yc) 
double f_y;//������ú����ķ���ֵyp 
double a;//����x����������� 
double b;//����x����������� 
double h;//������ 
int I;
//���岽��
//����Ҫ���������䳤���ܷ񱻲��������ǲ���֪��
//����Ҫ��֤ÿ�ο粽Ҫ��x�Ķ������ڣ������ǲ���֪��
//����ͨ��ÿ�ο粽���x��ֵ�����Ҷ˵�Ƚ� ��xֵ�������Ҷ˵��ֵ��������⡣ 

int main()
{
    cout << "����x������" << endl;
    cin >> b;
    cout << "����x������" << endl;
    cin >> a;
    cout << "����x0" << endl;
    cin >> x[0];
    cout << "����y0" << endl;
    cin >> y[0];
    cout << "���벽��" << endl;
    cin >> h;//����ģ�飻֮��Ϊ�����ڿ������ڣ���h�Ĳ�����������н����ٴΣ� 
    for (int i = 1; x[0] + i * h <= b; i++)
        //����ͨ��ÿ�ο粽���x��ֵ�����Ҷ˵�Ƚ� ��xֵ�������Ҷ˵��ֵ������ѭ��
    {
        x[i] = x[0] + i * h;
        func_y(x[i - 1], y[i - 1], 0, h);//��һ�ε������Ԥ��ֵyp 
        yp[i] = f_y;
        C = y[i - 1] - f_y;
        //�����������Ҫ������Ϊ��ͳһ���ú����Ĳ�������
        //���Խ�һ�����ú���ֻҪ�ı�����Ϳ������yp��yc
        func_y(x[i], yp[i], C, h);//�ڶ��ε������yc 
        y[i] = (yp[i] + f_y) / 2;//yp��yc��ƽ��ֵΪ����ֵ 
        I = i;
    }
    cout << "**********������**********" << endl;
    cout << setiosflags(ios::fixed) << setprecision(5);//����������5λС�� 
    cout << "    Xn " << "    Ԥ��ֵ  " << "  У��ֵ" << endl;
    for (int i = 1; i <= I; i++)
    {
        cout << " " << x[i] << " , " << yp[i] << " , " << y[i] << endl;
    }
    return 0;
}

double func_y(double x, double y, double c, double h)//����ƽ������ʽ�ĸĽ�ŷ����ʽyp 
{
    f_y = y + c + h * (pow(x, 3) * pow(y, 2) + 1);
    //�޸��µ���⺯��ʱ��ֻҪ�� (pow(x,3)*pow(y,2) + 1)������������ݼ���
    return f_y;
}