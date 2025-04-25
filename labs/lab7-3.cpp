
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void get_string(string& str)
{
    cout << "Введите строку для шифровки: \n";
    getline(cin, str);
}

void crypt_string(string& str, const bool decode)
{
    char ch_1 = ' ', ch_2 = ' ';

    const int str_len = str.size();

    for (int it = 0; it < str_len - 1; it += 2)
    {
        ch_1 = str[it];
        ch_2 = str[it + 1];

        str[it] = ch_2;
        str[it + 1] = ch_1;
    }

    if (decode) cout << "Строка расшифрована!" << endl;

    else cout << "Строка зашифрована!" << endl;
}

void write_to_file(const string& str) 
{
    ofstream out;

    out.open("crypted.txt");

    if (out.is_open())
    {
        out << str;
    }
    out.close();
}

void read_from_file(string& str) 
{
    ifstream in;

    in.open("crypted.txt");

    if (in.is_open())
    {
        getline(in, str);
    }
    in.close();
}

void add_to_file(const string& str)
{
    ofstream out ("crypted.txt", ios::app);

    if (out.is_open())
    {
        out << endl << str;
    }
    out.close();
}

bool check_right_yes_or_no(const char variant)
{
    if (variant == 'y' || variant == 'n' || variant == 'Y' || variant == 'N') return true;

    return false;
}

bool encrypt_ask() 
{
    string variant;

    cout << "Хотите ли вы расшифровать вашу строку (в файле)? (y: да; n: нет): ";
    cin >> variant;

    while (!check_right_yes_or_no(variant[0]) || variant.length() != 1)
    {
        cout << "Введите y или n (y: да; n: нет): ";
        cin >> variant;
    }

    if (variant[0] == 'y' || variant[0] == 'Y') return true;
    else return false;
}


int main()
{

    string str;

    setlocale(LC_ALL, "Russian");

    get_string(str);

    crypt_string(str, false);

    write_to_file(str);

    if (encrypt_ask()) 
    {
        read_from_file(str);

        crypt_string(str, true);

        add_to_file(str);
    }

    system("pause");

    return 0;
}