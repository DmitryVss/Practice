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

	double x0 = 0;									//начальное значение аргумента
	double x[NMAX];									//массив значений аргумента
	double y[NMAX];									//массив значений функции
	double hf[NMAX];								//массив значений h * f(x,y)
	double f[NMAX];									//массив значений дифференциала функции
	double h;										//шаг
	double a;										//левая граница отрезка
	double b;										//правая граница отрезка
	double NumberFragm = 0;                         //количество разбиений
	int i;											//счетчик эл-тов
	char answer;									//ответ на вопрос интерфейса;

	//выбор ввода
	cout << "Исходные данные вводить с клавиатуры?		Y/N"<<endl;
	cin >> answer;
	switch (answer)
	{
		case 'Y':
		case 'y':
			cout << "Введите отрезок" << endl;
			cin >> a >> b;
			cout << "Введен отрезок: [" << a << "," << b << "]" << endl;
			cout << "Введите количество шагов" << endl;
			cin >> h;
			cout << "Введено количество шагов h = " << h << endl;
			break;
		case 'N':
		case 'n':
			cout << "Считывание данных из text.txt"<<endl;
			ifstream fin(FDATA);
			fin >> a >> b;
			cout << "Считан отрезок: [" << a << "," << b << "]" << endl; 
			fin >> h;
			cout << "Считано количество шагов h = " << h << endl;
			break;
			fin.close();
	}
	y[0] = 1;										//начальное значение функции

	//подсчет количества шагов
	NumberFragm = (b - a) / h;
	//cout << "Количество разбиений: " << NumberFragm << endl;

	//решение дифференциального уравнения
	for (i = 0; i <= NumberFragm; i++)
	{
		x[i] = x0 + h * i;							//нахождение значения аргумента
		//cout << "x[" << i << "] = " << x[i] << endl;
		f[i] = 2 * x[i] * y[i];						//нахождение значения y'=2*x*y
		//cout << "f[" << i << "] = " << f[i]<<endl;
		hf[i] = f[i] * h;				
		//cout << "hf[" << i << "] = " << hf[i]<<endl;
		y[i + 1] = y[i] + hf[i];					//нахождение значения функции
		//cout << "y[" << i << "] = " << y[i]<<endl;
	}

	system("cls");

	//построение графика
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 250, 335, NULL);
	LineTo(hDC, 450, 335);
	MoveToEx(hDC, 350, 250, NULL);
	LineTo(hDC, 350, 420);
	for (i = 0; i <= NumberFragm; i++)
	{
		MoveToEx(hDC, 200 * x[i] + 350, -100 * y[i] + 420, NULL);
		LineTo(hDC, 200 * x[i + 1] + 350, -100 * y[i + 1] + 420);
		if (i == (NumberFragm/2))
		{
			break;
		}
	}

	//выбор вывода
	cout << "Результат выводить на экран?		Y/N" << endl;
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
			cout << "Вывод результатов в res.txt" << endl;
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