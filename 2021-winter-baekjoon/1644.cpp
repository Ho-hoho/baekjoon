#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> prime;
bool check[4000010] = { false };

int Eratos() {
	int res=0;
	for (int i = 2; i*i <= N; i++) {
		if (!check[i]) {
			//prime.push_back(i);
			for (int j = i*i; j <= N; j+=i) check[j] = true;
		}
	}
	
	for (int i = 2; i <= N; i++) {
		if (!check[i]) prime.push_back(i);
	}
	int s = prime.size();
	
	int sum = 0, left = 0, right = 0;
	while (1) {
		if (sum >= N) {
			sum -= prime[left++];
		}
		else if (right == s) break;
		else {
			sum += prime[right++];
		}

		if (sum == N) {
			res++;
		}
	}
	return res;
}

int main() {
	cin >> N;
	cout << Eratos();
}
