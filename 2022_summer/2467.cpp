#include <iostream>
#include <algorithm>

using namespace std;
int N,s,e,ans= 2'000'000'001,a,b;
int arr[100'000];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	s = 0; e = N - 1;

	while (s != e) {
		int temp = arr[s] + arr[e];
		if (abs(ans) > abs(temp)) {
			ans = temp;
			a = arr[s];
			b = arr[e];
		}
		if (temp == 0) break;
		else if (temp > 0) e--;
		else s++;
	}
	cout << a << " " << b;

	return 0;
}
