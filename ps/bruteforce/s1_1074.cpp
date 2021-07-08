#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
vector< vector<int> > m;
int N, R, C;
ull ans;

void z_traverse(ull num, int py, int px, int size)
{
	// 기저 사례
	if (size == 2)
	{
		if (R == py && C == px) ans = num;
		if (R == py && C == px+1) ans = num+1;
		if (R == py+1 && C == px) ans = num+2;
		if (R == py+1 && C == px+1) ans = num+3;
		return ;
	}

	// 재귀 사례
	if (R >= py && R < py+size/2 && C >= px && C < px+size/2)
		z_traverse(num, py, px, size/2);
	if (R >= py && R < py+size/2 && C >= px+size/2)
		z_traverse(num+pow(size/2, 2), py, px+size/2, size/2);
	if (R >= py+size/2 && C >= px && C < px+size/2)
		z_traverse(num+2*pow(size/2, 2), py+size/2, px, size/2);
	if (R >= py+size/2 && C >= px+size/2)
		z_traverse(num+3*pow(size/2, 2), py+size/2, px+size/2, size/2);
}

int main(void)
{
	cin >> N >> R >> C;
	z_traverse(0,0,0,pow(2,N));

	cout << ans << "\n";
}
