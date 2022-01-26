#include <iostream>

using namespace std;

int N, M;
long long mod_cnt[1001] = { 0 };
long long sum[1000001] = { 0 };
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
		mod_cnt[sum[i] % M]++;
	}
	long long ans = mod_cnt[0];
	for (int i = 0; i < M; i++) {
		ans += mod_cnt[i] * (mod_cnt[i] - 1) / 2;
	}
	cout << ans;
}
