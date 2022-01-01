#include <vector>
#include <cmath>
#include <iostream>
#include <string>

typedef long long ll;
using namespace std;

#define MAXNUM 1000000000

typedef struct command
{
	string str;
	int	var;
} t_com;

int NUM(vector<ll> &v, int x)
{
	v.push_back(x);
	return (0);
}

int POP(vector<ll> &v)
{
	if (v.size() == 0)
		return (1);
	v.pop_back();
	return (0);
}

int INV(vector<ll> &v)
{
	if (v.size() == 0)
		return (1);
	ll temp = v.back();
	v.pop_back();
	temp *= -1;
	v.push_back(temp);
	return (0);
}

int DUP(vector<ll> &v)
{
	if (v.size() == 0)
		return (1);
	ll temp = v.back();
	v.push_back(temp);
	return (0);
}
int SWP(vector<ll> &v)
{
	if (v.size() < 2)
		return (1);
	ll first = v.back();
	v.pop_back();
	ll second = v.back();
	v.pop_back();
	v.push_back(first);
	v.push_back(second);
	return (0);
}
int ADD(vector<ll> &v)
{
	if (v.size() < 2)
		return (1);
	ll first = v.back();
	v.pop_back();
	ll second = v.back();
	v.pop_back();
	if (abs(first+second) > MAXNUM)
		return (1);
	v.push_back(first+second);
	return (0);
}
int SUB(vector<ll> &v)
{
	if (v.size() < 2)
		return (1);
	ll first = v.back();
	v.pop_back();
	ll second = v.back();
	v.pop_back();
	if (abs(second-first) > MAXNUM)
		return (1);
	v.push_back(second-first);
	return (0);
}
int MUL(vector<ll> &v)
{
	if (v.size() < 2)
		return (1);
	ll first = v.back();
	v.pop_back();
	ll second = v.back();
	v.pop_back();
	if (abs(first * second) > MAXNUM)
		return (1);
	v.push_back(first*second);
	return (0);
}
int DIV(vector<ll> &v)
{
	if (v.size() < 2)
		return (1);
	ll first = v.back();
	v.pop_back();
	ll second = v.back();
	v.pop_back();
	if (first == 0)
		return (1);
	int minus = 0;
	if (first < 0) minus++;
	if (second < 0) minus++;
	first = abs(first);
	second = abs(second);
	ll res = minus == 1 ? (second / first) * -1 : second / first;
	v.push_back(res);
	return (0);
}
int MOD(vector<ll> &v)
{
	if (v.size() < 2)
		return (1);
	ll first = v.back();
	v.pop_back();
	ll second = v.back();
	v.pop_back();
	if (first == 0)
		return (1);
	bool hasMinus = false;
	if (second < 0)
		hasMinus = true;
	first = abs(first);
	second = abs(second);
	ll res = hasMinus ? (second % first) * -1 : second % first;
	v.push_back(res);
	return (0);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	bool is_first_program = true;

	while (true)
	{
		vector<t_com> p;
		int p_len = 0;
		bool is_first_command = true;
		while (true)
		{
			string str;
			cin >> str;
			if (str == "QUIT") return 0;
			else if (is_first_program) {
				is_first_program = false;
				is_first_command = false;
			}
			else if (is_first_command) {
				is_first_command = false;
				cout << "\n";
			}
			if (str == "END") break;
			else if (str == "NUM")
			{
				t_com newCom;
				newCom.str = str;
				int num; cin >> num;
				newCom.var = num;
				p.push_back(newCom);
				p_len++;
			}
			else {
				t_com newCom;
				newCom.str = str;
				p.push_back(newCom);
				p_len++;
			}
		}

		int t; cin >> t;
		while (t--)
		{
			ll num; cin >> num;

			vector<ll> v;
			int res = 0;
			v.push_back(num);
			for (int i = 0; i < p_len; ++i)
			{
				if (p[i].str == "NUM")
					res = NUM(v, p[i].var);
				else if (p[i].str == "POP")
					res = POP(v);
				else if (p[i].str == "INV")
					res = INV(v);
				else if (p[i].str == "DUP")
					res = DUP(v);
				else if (p[i].str == "SWP")
					res = SWP(v);
				else if (p[i].str == "ADD")
					res = ADD(v);
				else if (p[i].str == "SUB")
					res = SUB(v);
				else if (p[i].str == "MUL")
					res = MUL(v);
				else if (p[i].str == "DIV")
					res = DIV(v);
				else if (p[i].str == "MOD")
					res = MOD(v);
				if (res == 1)
				{
					break;
				}
			} // end p for
			if (v.size() != 1 || res == 1)
			{
				cout << "ERROR\n";
			}
			else
				cout << v.back() << "\n";
		}

	}
}
