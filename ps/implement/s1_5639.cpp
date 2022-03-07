#include <iostream>
#include <vector>
#include <string>
using namespace std;

void postorder(vector<int> &v, int i) {
	if (v[i*2] != -1) postorder(v, i*2);
	if (v[i*2+1] != -1) postorder(v, i*2+1);
	cout << v[i] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v(50505, -1);

	int root;
	cin >> root;

	int i = 1, num;
	v[0] = 1234567890;
	v[1] = root;
	while (cin.fail() == false) {
		cin >> num;
		cout << num << "\n";
		while (true) {
			if (num < v[i] && v[i*2] == -1) {
				i *= 2;
				v[i*2] = num;
				break;
			}
			if (num > v[i] && v[i/2] > num && v[i*2+1] == -1) {
				i = i*2+1;
				v[i*2+1] = num;
				break;
			}
			else i /= 2;
		}
	}
}
