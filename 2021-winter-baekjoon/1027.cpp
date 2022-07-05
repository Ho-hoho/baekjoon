#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N,ans=0;
int arr[51];

void solve() {
	for (int i = 1; i <= N; i++) { // 기준 건물
		int tmp = 0;
		for (int a = 1; a < i; a++) { // 보이는 지 확인하는 대상
			if (a == i) continue;
			bool flag = true;
			double grad_a = (arr[i] - arr[a]) / (double)(i - a);
			for (int b = a+1; b < i; b++) { // 그 사이 건물
				double grad_b = (arr[i] - arr[b]) / (double)(i - b);
				if (grad_a >= grad_b) {
					flag = false;
					break;
				}
			}
			if (flag) {
				tmp++;
			}
		}
		for (int a = i+1; a <= N; a++) { // 보이는지 확인하는 대상
			if (a == i) continue;
			bool flag = true;
			double grad_a = (arr[a] - arr[i]) / (double)(a - i);
			for (int b = i + 1; b < a; b++) { // 그 사이 건물
				double grad_b = (arr[b] - arr[i]) / (double)(b - i);
				if (grad_a <= grad_b) {
					flag = false;
					break;
				}
			}
			if (flag) {
				tmp++;
			}
		}
		ans = max(tmp, ans);
	}
	cout << ans;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	solve();
}
