
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

char num_int[] = "-0123456789";

char num_float[] = "-0123456789.";

bool is_integer(string str)
{
    int minuses = 0;

    string::iterator it = str.begin();

    while (it != str.end() && strchr(num_int, *it) && minuses <= 1)
    {
        if (strchr("-", *it)) minuses++;

        it++;

    }

    if (!str.empty() && it == str.end()) return true;
    else return false;
}

bool is_float(string str)
{

    int dots = 0, minuses = 0;

    string::iterator it = str.begin();

    while (it != str.end() && strchr(num_float, *it) && dots <= 1 && minuses <= 1)
    {
        if (strchr(".", *it)) dots++;

        if (strchr("-", *it)) minuses++;

        it++;

    }

    if (!str.empty() && it == str.end() && dots <= 1 && minuses <= 1) return true;
    else return false;
}

void get_x(float& x)
{

    string x_string;

    cout << "Введите x (рациональное число): \n";
    cin >> x_string;

    while (!is_float(x_string)) {

        cout << "Введите рациональное число!\n";
        cin >> x_string;

    }

    x = stof(x_string);
}

void get_n(int& n)
{

    string n_string;

    cout << "Введите n (целое число): \n";
    cin >> n_string;

    while (!is_integer(n_string)) {

        cout << "Введите целое число!\n";
        cin >> n_string;

    }

    n = stoi(n_string);
}

float get_value(const int n, const float x)
{
    float y;

    if (n % 2 == 0) 
    {
        y = pow(pow(x, static_cast<float>(n) / static_cast<float>(2)), static_cast <float>(2));
    }
    else 
    {
        y = x * get_value(n-1, x);
    }

    return y;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;

    float x;

    get_x(x);

    get_n(n);

    cout << "\ny = " << get_value(n, x);
}