#include <cmath>
#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ull;

int main(void)
{
	ull L; cin >> L;
	string str; cin >> str;
	ull sum = 0;
	ull div = 1234567891;
	ull r = 1;
	for (ull i = 0; i < L; ++i)
	{
		sum += (ull)(str[i] - 'a' + 1) * r;
		sum %= div;
		r = (r * 31) % div;
	}
	cout << sum % div << "\n";
	return (0);
}
