#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k,s,e,h,pre,cnt,res=-1;
int arr[51];
string ans;
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) cin >> arr[i];
	s = 1; e = arr[k-1]-arr[0];
	while (s <= e) {
		string cur = "1";
		h = (s + e) / 2;
		pre = arr[0]; cnt = 1;
		for (int i = 1; i < k; i++) {
			if (arr[i] - pre >= h) {
				pre = arr[i];
				cnt++;
				cur += "1";
				if (cnt == m) break;
			}
			else cur += "0";
		}
		while (cur.size() < k) cur += "0";

		if (cnt >= m) {
			res = h;
			ans = cur;
			s = h + 1;
		}
		else e = h - 1;
	}
	cout << ans;
	
	return 0;
}
