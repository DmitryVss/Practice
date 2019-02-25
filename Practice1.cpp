#include <iostream>
using namespace std;

const int NMAX = 100;

//выбор ввода
void Input(char answer1)
{
	double a;
	double b;
	switch (answer1)
	{
	case 1:
		cout << "Введите отрезок" << endl;
		cin >> a >> b;
		cout << "Введен отрезок: [" << a << "," << b << "]" << endl;
		break;
	case 2: 
		cout << "Считывание данных из text.txt";
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	double x0 = 0;									//начальное значение аргумента
	double x[NMAX];									//массив значений аргумента
	double y[NMAX];									//массив значений функции
	double hf[NMAX];								//массив значений h * f(x,y)
	double f[NMAX];									//массив значений дифференциала функции
	double h = 0.025;								//шаг
	double a;										//левая граница отрезка
	double b;										//правая граница отрезка
	double NumberFragm = 0;                         //количество разбиений
	int i;											//счетчик эл-тов
	char answer1;
	
	cout << "Исходные данные вводить с клавиатуры?		1 - YES; 2 - NO";
	cin >> answer1;

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
		cout << "y[" << i << "] = " << y[i]<<endl;
	}

	

	system("pause");
	return 0;
}