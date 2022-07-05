#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long N, G, K;
long long s=1000000001,e=2000000001,x;
long long info[200001][3] = { 0 }; // S L O

void solve() {
	vector<pair<long long,int>> arr;
	while (1) {
		long long sum = 0;
		arr.clear();
		if (s + 1 >= e) {
			x = e;
		}
		else x = (s + e) / 2 ;

		for (int i = 0; i < N; i++) {
			arr.push_back(make_pair(info[i][0] * max((long long)1, x - info[i][1]),info[i][2]));
		}
		sort(arr.begin(), arr.end());
		int k = K;
		for (int i = arr.size() -1 ; i >= 0; i--) {			
			if (k && arr[i].second) {
				k--;
			}
			else sum += arr[i].first;
		}
		if (s + 1 >= e) {
			if (sum > G)
				cout << s;
			else
				cout << e;
			break;
		}
		else {
			if (sum > G)
				e = x;
			else
				s = x;
		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> G >> K;
	for (int i = 0; i < N; i++) {
		cin >> info[i][0] >> info[i][1] >> info[i][2];
		if (s > info[i][1])
			s = info[i][1];
	}
	solve();

	return 0;
}
