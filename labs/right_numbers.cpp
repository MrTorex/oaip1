
#include <iostream>
#include <string>

using namespace std;

constexpr char num_unsigned_int[] = "0123456789";

constexpr char num_float[] = "-0123456789.";

bool is_unsigned_integer(string str)
{
	auto it = str.begin();

	while (it != str.end() && strchr(num_unsigned_int, *it))
	{

		++it;

	}

	if (!str.empty() && it == str.end()) return true;
	else return false;
}

bool is_float(string str)
{

	int dots = 0, minuses = 0;

	auto it = str.begin();

	while (it != str.end() && strchr(num_float, *it) && dots <= 1 && minuses <= 1)
	{
		if (strchr(".", *it)) dots++;

		if (strchr("-", *it)) minuses++;

		++it;

	}

	if (!str.empty() && it == str.end() && dots <= 1 && minuses <= 1) return true;
	else return false;
}
int main()
{
    std::cout << "Hello World!\n";
}