#include <iostream>
using namespace std;
int N, Q;
long long ans = 0;
long long arr[100001] = { 0 };
long long seg[400004] = { 0 };
long long init_seg(int s, int e, int node) {
	if (s == e) {
		return seg[node] = arr[s];
	}
	int mid = (s + e) / 2;
	seg[node] = init_seg(s, mid, node * 2) + init_seg(mid + 1, e, node * 2 + 1);
	return seg[node];
}

long long sum(int s, int e, int node, int left, int right) {
	if (e < left || s > right) return 0;
	else if (s >= left && e <= right) return seg[node];
	int mid = (s + e) / 2;
	return sum(s, mid, node * 2, left, right) + sum(mid + 1, e, node * 2 + 1, left, right);
}

void update(int s, int e, int node, int idx, long long dif) {
	if (e < idx || s > idx) return;
	seg[node] += dif;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(s, mid, node * 2, idx, dif);
	update(mid + 1, e, node * 2 + 1, idx, dif);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init_seg(1, N, 1);
	for (int i = 1; i <= Q; i++) {
		long long c, d;
		cin >> c >> d;
		cout << sum(1, N, 1, min(c, d), max(c, d)) << "\n";
		cin >> c >> d;
		update(1, N, 1, c, d - arr[c]);
		arr[c] = d;
	}
	return 0;
}
