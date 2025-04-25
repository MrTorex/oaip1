#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double x, y, z, f;

    cout << "Введите x: " << endl;
    cin >> x;

    cout << "Введите y: " << endl;
    cin >> y;

    cout << "Введите z: " << endl;
    cin >> z;

    f = (pow((y + pow((x - 1), 1 / 3.)), 1 / 4.)) / (fabs(x - y) * (pow(sin(z), 2) + tan(z)));

    cout << "Результат: ";
    cout << f;

    return 0;
}