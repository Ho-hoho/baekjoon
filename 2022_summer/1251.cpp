#include <iostream>
#include <vector>

using namespace std;

int arr[10001];
long long n,m,s, e,t,cnt,result=-1;
vector <int > v;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
	if (n <= m) {
		cout << n;
		return 0;
	}
	s = 1; e = 30 * n;
	while (s <= e) {
		t = (s + e) / 2;
		cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += t / arr[i] + 1;
		}
		if (cnt >= n) {
			result = t;
			e = t - 1;
		}
		else s = t + 1;
	}
	cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt += (result - 1) / arr[i] + 1;
	}
	for (int i = 0; i < m; i++) {
		if(result % arr[i] == 0) cnt++;
		if (cnt == n) {
			cout << i + 1;
			break;
		}
	}
	return 0;
}
