#include <iostream>

using namespace std;

int T;
long long N;

void solve() {
	if ((N % 9) == 0) cout << "TAK\n";
	else if ((N % 3) == 2) cout << "TAK\n";
	else cout << "NIE\n";
	return;
}
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		solve();
	}
	return 0;
}
