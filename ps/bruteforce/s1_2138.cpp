#include <iostream>
#include <string>
#include <cmath>
#define MAX_SIZE 100000
#define INF 1234567890;
using namespace std;

bool bulbs[MAX_SIZE];
bool ans[MAX_SIZE];
int N;

// n번째 스위치를 누른다.
void click_switch(int n)
{
	for (int i = n-1; i <= n+1; ++i)
	{
		if (i < 0 || i >= MAX_SIZE) continue;
		bulbs[i] = !bulbs[i];
	}
}

// n번째까지 답과 같은지 확인한다.
bool is_answer(int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (bulbs[i] != ans[i]) return false;
	}
	return true;
}

// index번째 전구의 상태를 결정한다.
// 마지막번째라면 자신의 상태를 결정하고 답인지 검사해서 맞으면 click를 반환한다.
int solve(int index, int clicked)
{
	int res;
	bool has_clicked = false;

	// N == 2일 때, 특별 처리
	if (index >= N) return is_answer(N) ? clicked : INF;

	if (bulbs[index - 1] != ans[index - 1])
	{
		click_switch(index);
		clicked++;
		has_clicked = true;
	}

	if (index == N - 1) {// 기저사례
		res = is_answer(N) ? clicked : INF;
	}
	else {// 재귀사례
		res = solve(index+1, clicked);
	}
	if (has_clicked) click_switch(index);
	return res;
}

int main()
{
	int i;
	int res = INF;

	cin >> N;
	string str;
	cin >> str;
	for (i=0;i<N;++i)
		bulbs[i] = str[i] == '1' ? true : false;
	cin >> str;
	for (i=0;i<N;++i)
		ans[i] = str[i] == '1' ? true : false;
	if (bulbs[0] == ans[0])
	{
		// 1,2번째 스위치를 전부 누르지 않은 경우
		res = min(res, solve(2, 0));
		// 1,2번째 스위치를 전부 누른 경우
		click_switch(0);
		click_switch(1);
		res = min(res, solve(2, 2));
	}
	else
	{
		// 1번째 스위치를 누른 경우
		click_switch(0);
		res = min(res, solve(2, 1));
		click_switch(0);
		// 2번째 스위치를 누른 경우
		click_switch(1);
		res = min(res, solve(2, 1));
	}
	res = res == 1234567890 ? -1 : res;
	cout << res << "\n";
	return (0);
}
