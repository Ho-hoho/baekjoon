#include <iostream>

using namespace std;
int N,cnt=0;

void solve(int i,int j,int num) {
	if ((i/num)%3 == 1 && (j/num)%3 == 1) {
		cout << " ";
	}
	else {
		if (num / 3 == 0) {
			cout << "*";
		}
		else {
			solve(i, j, num / 3);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			solve(i, j, N);
		}
		cout << "\n";
	}
	return 0;
}
