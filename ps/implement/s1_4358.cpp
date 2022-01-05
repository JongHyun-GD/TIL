#include <string>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str;
    map<string, int> m;
    int size = 0;
    while (getline(cin, str).eof() == false) {
        size++;
        if (m.find(str) == m.end()) {
            m.insert(make_pair(str, 1));
        } else {
            m[str]++;
        }
    }
    size++;
    if (m.find(str) == m.end()) {
        m.insert(make_pair(str, 1));
    } else {
        m[str]++;
    }
    for (auto tree : m) {
		cout << tree.first << " ";
        printf("%.4f\n", round(double)tree.second / (double)size * 1000000) / 10000;
    }

}
