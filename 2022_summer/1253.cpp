#include <iostream>
#include <algorithm>

using namespace std;
int N,cnt = 0;
int arr[2001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);
	
	for (int i = 0; i < N; i++) {
		int s = 0;
		int e = N - 1;
		while (s != e) {
			if (s == i) s++;
			else if (e == i) e--;
			else {
				int temp = arr[s] + arr[e];
				if (temp == arr[i]) {
					cnt++;
					break;
				}
				else if (temp > arr[i]) e--;
				else s++;
			}
		}

	}
	cout << cnt;
	return 0;
}
