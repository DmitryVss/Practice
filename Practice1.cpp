#include <iostream>
using namespace std;

const int NMAX = 100;

//����� �����
void Input(char answer1)
{
	double a;
	double b;
	switch (answer1)
	{
	case 1:
		cout << "������� �������" << endl;
		cin >> a >> b;
		cout << "������ �������: [" << a << "," << b << "]" << endl;
		break;
	case 2: 
		cout << "���������� ������ �� text.txt";
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	double x0 = 0;									//��������� �������� ���������
	double x[NMAX];									//������ �������� ���������
	double y[NMAX];									//������ �������� �������
	double hf[NMAX];								//������ �������� h * f(x,y)
	double f[NMAX];									//������ �������� ������������� �������
	double h = 0.025;								//���
	double a;										//����� ������� �������
	double b;										//������ ������� �������
	double NumberFragm = 0;                         //���������� ���������
	int i;											//������� ��-���
	char answer1;
	
	cout << "�������� ������ ������� � ����������?		1 - YES; 2 - NO";
	cin >> answer1;

	y[0] = 1;										//��������� �������� �������

	//������� ���������� �����
	NumberFragm = (b - a) / h;
	//cout << "���������� ���������: " << NumberFragm << endl;

	//������� ����������������� ���������
	for (i = 0; i <= NumberFragm; i++)
	{
		x[i] = x0 + h * i;							//���������� �������� ���������
		//cout << "x[" << i << "] = " << x[i] << endl;
		f[i] = 2 * x[i] * y[i];						//���������� �������� y'=2*x*y
		//cout << "f[" << i << "] = " << f[i]<<endl;
		hf[i] = f[i] * h;				
		//cout << "hf[" << i << "] = " << hf[i]<<endl;
		y[i + 1] = y[i] + hf[i];					//���������� �������� �������
		cout << "y[" << i << "] = " << y[i]<<endl;
	}

	

	system("pause");
	return 0;
}