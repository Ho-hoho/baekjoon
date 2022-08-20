#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

vector<pair<int, int>> arr;
int n,a,zcnt=1;
bool pmat[500000];
long long dp[500001];
long long ans = 0;

void make_pmat() {
	memset(pmat, true, sizeof(pmat));
	pmat[0] = false; pmat[1] = false;
	int num = 10000 * n;
	for (int i = 2; i <= sqrt(num); i++) {
		if (pmat[i] == false) continue;
		for (int j = i * i; j <= num; j+=i) {
			pmat[j] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int flag = -1;
		cin >> a;
		if (a == 0) { zcnt++; continue; }
		for (int i = 0; i < arr.size(); i++) {
			if (a == arr[i].first) {
				flag = i; break;
			}
		}
		if (flag == -1) arr.push_back({ a,1 });
		else arr[flag].second++;
	}
	make_pmat();

	dp[0] = 1;
	for (auto cur : arr) {
		for (int i = n * 10000; i >= 0; i--) {
			for (int j = 1; j <= cur.second; j++) {
				
				if (i - cur.first * j < 0) break;
				dp[i] += dp[i - cur.first * j];
				
			}
		}
	}

	for (int i = 2; i <= n * 10000; i++) {
		if (pmat[i]) ans += dp[i];
	}

	cout << ans*zcnt;
}
