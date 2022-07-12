#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

pair <long long, char> arr[12];
bool flag[12] = { 0 };
long long num[12] = { 0 };
int n,number;
long long ans;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 0; i < 10; i++) {
		arr[i].first = 0;
		arr[i].second = 'A' + i;
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		long long times=1;
		for (int k = s.length()-1 ; k >=0; k--) {
			arr[s[k]-'A'].first += times;
			times *= 10;
		}
		flag[s[0] - 'A'] = true;
	}

	sort(arr, arr + 10, greater<>());
	number = 9;	

	for (int i = 0; i < 10; i++) {
		if (arr[i].first == 0) break;
		if (i == 9 && flag[arr[9].second - 'A']) {			
			for (int k = 8; k >= 0; k--) {
				if (!flag[arr[k].second - 'A']) {
					char temp = arr[k].second;
					double tempd = arr[k].first;
					for (int j = k; j < 9; j++) {
						arr[j].first = arr[j + 1].first;
						arr[j].second = arr[j + 1].second;
					}
					arr[9].second = temp;
					arr[9].first = tempd;
					break;
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		if (arr[i].first) {
			num[arr[i].second - 'A'] = number--;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < 10; i++) {
		ans += num[arr[i].second - 'A'] * arr[i].first;
	}

	cout << ans;
}
