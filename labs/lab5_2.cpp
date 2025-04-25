
#include <iostream>

using namespace std;

void get_n(int& n)
{
	cout << "Введите порядок матрицы (натуральное число): \n";
	cin >> n;
}

void get_mass(double**& a, const int n)
{
	double el = 0;

	for (int i = 0; i < n; i++)
	{
		cout << "Введите элементы столбца №" << i + 1 << ":\n";

		for (int j = 0; j < n; j++)
		{
			cout << "Введите элемент  №" << j + 1 << " (рациональное число):\n";
			cin >> el;

			a[i][j] = el;
		}
	}
}

void get_min_max(double**& a, const int n, double& min, double& max)
{
	int j1 = 0, j2 = n - 1, j1_temp, j2_temp;

	for (int i = 0; i < n; i++)
	{
		if (j1 > j2)
		{
			j1_temp = j2;
			j2_temp = j1;
		}
		else
		{
			j1_temp = j1;
			j2_temp = j2;
		}

		for (j1_temp; j1_temp <= j2_temp; j1_temp++)
		{
			if (a[i][j1_temp] > max)
				max = a[i][j1_temp];

			if (a[i][j1_temp] < min)
				min = a[i][j1_temp];
		}

		j1++;

		j2--;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;

	get_n(n);

	double** a = new double*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}

	get_mass(a, n);

	double min = 1e10, max = 1e-10;

	get_min_max(a, n, min, max);

	cout << "Максимальное значение: " << max << endl;
	cout << "Минимальное значение: " << min << endl;

	delete[] a;

	return 0;
}

