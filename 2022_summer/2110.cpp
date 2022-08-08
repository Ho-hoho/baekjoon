#include <iostream>
#include <algorithm>

using namespace std;
int N, C;
int arr[200'000];
int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	
	int s = 1;
	int e = arr[N - 1] - arr[0];
	int result = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 1;
		int prev = arr[0];
		for (int i = 0; i < N; i++) {
			if (arr[i] - prev >= mid) {
				cnt++;
				prev = arr[i];
			}
		}
		if (cnt >= C) {
			result = max(result, mid);
			s = mid + 1;
		}
		else e = mid - 1;
	}
	cout << result;
	return 0;
}
