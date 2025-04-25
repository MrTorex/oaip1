
#include <iostream>
#include <string>

using namespace std;

int dots, minuses, n, zero1, zero2;

double el;

int where_zero1(double mass[], int length)
{
    for (int i=0; i < length; i++) 
    {
        if (mass[i] == 0) 
        {
            return i;
        }
    }
    return -1;
}

int where_zero2(double mass[], int length, int zero1)
{
    int b = -1;

    for (int i = zero1; i < length; i++)
    {
        if (mass[i] == 0)
        {
            if (i > b) b = i;
        }
    }
    return b;
}

void reverse(double* mass, int length, int zero1, int zero2) 
{
    int i = 0;

    double a, b;

    while (zero1+i <= zero2-i)
    {
        a = mass[zero1 + i];

        b = mass[zero2 - i];

        mass[zero1 + i] = b;

        mass[zero2 - i] = a;

        i++;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите количество элементов в массиве (натуральное число): \n";
    cin >> n;

    auto a = new double[n] {0.};

    for (int i = 0; i < n; i++) 
    {

        cout << "Введите элемент №" << i+1 << " (рациональное число):\n";
        cin >> el;

        a[i] = el;
    }

    zero1 = where_zero1(a, n);

    zero2 = where_zero2(a, n, zero1);

    cout << "Изначальный массив: \n[";

    for (int i = 0; i < n; i++)
    {

        if (i + 1 == n) cout << a[i] << "]\n";
        else cout << a[i] << ", ";
        
    }

    reverse(a, n, zero1, zero2);

    cout << "Новый массив: \n[";

    for (int i = 0; i < n; i++)
    {

        if (i + 1 == n) cout << a[i] << "]\n";
        else cout << a[i] << ", ";

    }

    delete[] a;

    system("pause");

    return 0;
}
