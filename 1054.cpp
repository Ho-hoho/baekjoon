#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int N, K;
int countBits(int value) {
	int count = 0;
	while (value > 0) {
		if ((value & 1) == 1)
			count++;
		value = value >> 1;
	}
	return count;
}

void solve() {
	for (int i = 0;; i++) {
		if (countBits(N) <= K) {
			cout << i;
			return;
		}
		N++;
	}
}

int main() {
	cin >> N >> K;
	solve();
}
