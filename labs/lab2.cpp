
#include <iostream>
#include <cmath>

using namespace std;

double minimum(double a, double b) {
    if (a > b)
        return b;
    else
        return a;
}

double maximum(double a, double b) {
    if (a < b)
        return b;
    else
        return a;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double x, y, f;

    cout << "Введите x: " << endl;
    cin >> x;

    cout << "Введите y: " << endl;
    cin >> y;

    if (((fabs(x) + fabs(y) <= 1) || x >= 0)) {
        f = maximum(x, y) + pow(x, 1 / 2.);
    }
    else if (((fabs(x) + fabs(y) > 0) || ((x < 0) && (y < 0)))) {
        f = minimum(x, y) + pow(sin(x), 2) - pow(cos(y), 2);
    }
    else {
        f = exp(pow(x, 2) + fabs(y));
    }

    cout << "Результат: ";
    cout << f;

    return 0;
}
