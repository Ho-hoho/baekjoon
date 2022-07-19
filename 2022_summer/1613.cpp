#include <iostream>

using namespace std;

int n, k, s;
int arr[401][401] = { 0 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b;

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int t = 1; t <= n; t++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][t] && arr[t][j]) arr[i][j] = 1;
			}
		}
	}

	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		if (arr[a][b]) {
			cout << -1 << "\n";
		}
		else if (arr[b][a]) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	return 0;
}
