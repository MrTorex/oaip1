
#include <iostream>

using namespace std;

const int len = 100;

void get_string(char* str)
{
    cout << "Введите предложение: \n";
    cin.getline(str, len);
}

void print_words(const char* str)
{
    int it = 0, spaces = 0;

    while (str[it] != '\0')
    {
        if (str[it] == ' ')
        {
            while (str[it] == ' ')
            {
                it++;
            }
            spaces++;
        }

        if (spaces == 0) it++;

        else if (spaces == 1 || spaces == 2)
        {
            while (str[it] != ' ' && str[it] != '\0')
            {
                cout << str[it];
                it++;
            }
            cout << " ";
        }

        else if (spaces == 3)
        {
            while (str[it] != ' ' && str[it] != '\0')
            {
                cout << str[it];
                it++;
            }
            break;
        }
    }
    cout << endl;
}


int main()
{
    char str[len];
     
    setlocale(LC_ALL, "Russian");

    get_string(str);

    print_words(str);

    system("pause");

    return 0;
}