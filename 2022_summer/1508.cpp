#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k,s,e,h,pre,cnt,res=-1;
int arr[51];

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) cin >> arr[i];
	s = 1; e = arr[k-1]-arr[0];
	while (s <= e) {
		h = (s + e) / 2;
		pre = arr[0]; cnt = 1;
		for (int i = 1; i < k; i++) {
			if (arr[i] - pre >= h) {
				pre = arr[i];
				cnt++;
			}
		}
		if (cnt >= m) {
			res = h;
			s = h + 1;
		}
		else e = h - 1;
	}
	pre = arr[0]; cout << 1; cnt = 1;
	for (int i = 1; i < k; i++) {
		if ( (arr[i] - pre >= res ) && (cnt < m)) {
			cout << 1;
			cnt++;
			pre = arr[i];
		}
		else {
			cout << 0;
		}
	}
	return 0;
}
