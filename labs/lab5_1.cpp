
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
		cout << "Введите элементы стоки №" << i + 1 << ":\n";

		for (int j = 0; j < n; j++)
		{
			cout << "Введите элемент  №" << j + 1 << " (рациональное число):\n";
			cin >> el;

			a[i][j] = el;
		}
	}
}

void count_mass(double**& a, const int n, double& summ, double& prod)
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
			summ += a[i][j1_temp];
			prod *= a[i][j1_temp];
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

	double summ = 0, prod = 1;

	count_mass(a, n, summ, prod);

	cout << "Сумма элементов матрицы: " << summ << endl;

	cout << "Произведение элементов матрицы: " << prod << endl;

	delete[] a;

	return 0;
}
