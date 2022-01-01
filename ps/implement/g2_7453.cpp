#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> A(N), B(N), C(N), D(N);
    int a,b,c,d;
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    vector<ll> AB, CD;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    ll l = 0, h = N * N - 1;
    ll ans = 0;
    while (l <= N*N-1 && h >= 0) {
        ll sum = AB[l] + CD[h];
        if (sum < 0) l++;
        else if (sum > 0) h--;
        else {
            ll sameAB = 1, sameCD = 1;
            while (l+1 <= N*N-1 && AB[l]==AB[l+1]) {
                l++;
                sameAB++;
            }
            while (h-1 >= 0 && CD[h]==CD[h-1]) {
                h--;
                sameCD++;
            }
            ans += sameAB * sameCD;
			l++;
        }
    }
    cout << ans << "\n";
}
