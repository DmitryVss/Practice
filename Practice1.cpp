#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

const char *FDATA = "text.txt";
const char *FRES = "res.txt";
const int NMAX = 100;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	double x0 = 0;									//��������� �������� ���������
	double x[NMAX];									//������ �������� ���������
	double y[NMAX];									//������ �������� �������
	double hf[NMAX];								//������ �������� h * f(x,y)
	double f[NMAX];									//������ �������� ������������� �������
	double h;										//���
	double a;										//����� ������� �������
	double b;										//������ ������� �������
	double NumberFragm = 0;                         //���������� ���������
	int i;											//������� ��-���
	char answer;									//����� �� ������ ����������;

	//����� �����
	cout << "�������� ������ ������� � ����������?		Y/N"<<endl;
	cin >> answer;
	switch (answer)
	{
		case 'Y':
		case 'y':
			cout << "������� �������" << endl;
			cin >> a >> b;
			cout << "������ �������: [" << a << "," << b << "]" << endl;
			cout << "������� ���������� �����" << endl;
			cin >> h;
			cout << "������� ���������� ����� h = " << h << endl;
			break;
		case 'N':
		case 'n':
			cout << "���������� ������ �� text.txt"<<endl;
			ifstream fin(FDATA);
			fin >> a >> b;
			cout << "������ �������: [" << a << "," << b << "]" << endl; 
			fin >> h;
			cout << "������� ���������� ����� h = " << h << endl;
			break;
			fin.close();
	}
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
		//cout << "y[" << i << "] = " << y[i]<<endl;
	}

	//���������� �������
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 170, 255, NULL);
	LineTo(hDC, 370, 255);
	MoveToEx(hDC, 270, 170, NULL);
	LineTo(hDC, 270, 340);
	/*for (x = -8.0f; x <= 8.0f; x += 0.01f) // O(270,255) - center
	{
		MoveToEx(hDC, 10 * x + 270, -10 * sin(x) + 255, NULL);//10 - scale
		LineTo(hDC, 10 * x + 270, -10 * sin(x) + 255);
	}
	*/
	for (i = 0; i <= NumberFragm; i++)
	{
		MoveToEx(hDC, x[i] + 270, y[i] + 255, NULL);
		LineTo(hDC, x[i+1] + 270, y[i+1] + 255);
	}
	//����� ������
	cout << "��������� �������� �� �����?		Y/N" << endl;
	cin >> answer;
	switch (answer)
	{
		case 'Y':
		case 'y':
			for (i = 0; i <= NumberFragm; i++)
			{
				cout << "y[" << i << "] = " << y[i] << endl;
			}
			break;
		case 'N':
		case 'n':
			cout << "����� ����������� � res.txt" << endl;
			ofstream fout(FRES);
			for (i = 0; i <= NumberFragm; i++)
			{
				fout << "y[" << i << "] = " << y[i] << endl;
			}
			break;
	}
	system("pause");
	return 0;
}