
#include <iostream>
#include <cmath>

using namespace std;

int factorial(int i)
{
	if (i == 0) return 1;
	else return i * factorial(i - 1);
}

bool is_nan(long double value)
{
	return value != value;
}

int main()
{

	setlocale(LC_ALL, "Russian");

	long float a, b, h, E, n, x, S, Y, k;
	
	cout << "Введите начальное значение a: " << endl;
	cin >> a;

	cout << "Введите конечное значение b: " << endl;
	cin >> b;

	cout << "Введите шаг h: " << endl;
	cin >> h;

	cout << "Введите необходимую погрешность E: " << endl;
	cin >> E;
	cout << "\n";

	x = a;

	k = 1;

	while (true)
	{

		k = 1;

		n = 1;

		Y = 2 * (pow(cos(x), 2) - 1);

		S = 0;

		while (fabs(S - Y) >= E) 
		{

			S = S + (pow((-1), k) * (pow(2 * x, 2 * k) / (factorial(2 * k))));

			n = n + 1;

			k = k + 1;

		}

		cout << "x: " << x << "\t";

		if (is_nan(S)) cout << "S: Слишком большое кол-во знаков после запятой или слишком большое число!" << "\n\n";

		else
		{

			cout << "S: " << S << "\t";

			cout << "Y: " << Y << "\t";

			cout << "n: " << n << "\t";

			cout << "Погрешность: " << fabs(S - Y) << "\n\n";

		}

		if (fabs(x - b) < 1e-7) break;

		x = x + h;

	}

	system("pause");

	return 0;

}

