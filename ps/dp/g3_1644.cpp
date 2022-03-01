#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
#define MAX_N 4000000

int main(void) {
	vector<int> dp(MAX_N + 10, 0);
	vector<int> is_prime(MAX_N + 10, -1);
	vector<int> primes;

	for (int i = 2; i <= MAX_N; ++i) {
		if (is_prime[i] == -1) {N
			int m = sqrt(i)+1;
			for (int j=0;j<primes.size();++j) {
				bool b_prime = true;
				if (i%primes[j] == 0) {
					b_prime = false;
				}
				if (b_prime) {
					primes.push_back(i);
					int k = 2;
					while (i * k <= MAX_N) {
						is_prime[i*k] = 0;
						k++;
					}
				}
			}
		}
	}

	for (int i=0;i<primes.size();++i) {

	}

	int N;
}
