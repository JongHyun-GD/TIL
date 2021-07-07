#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	string str;
	size_t len;
	size_t half;
	int		i;
	bool		diff;

	while (true)
	{
		cin >> str;
		len = str.length();
		i=0;
		diff = false;
		if (len == 1 && str[0] == '0')
			break;
		half = len % 2 == 0 ? len / 2 - 1 : len / 2;
		for (i=0;i<=half;++i)
		{
			if (i == len-i-1) break;
			if (str[i] != str[len-i-1]) {
				diff = true;
				break;
			}
		}
		if (diff) cout << "no\n";
		else cout << "yes" << "\n";
	}
}
