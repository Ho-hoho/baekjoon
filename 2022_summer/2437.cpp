#include <iostream>
#include <algorithm>

using namespace std;

int n,sum=0;
int arr[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (sum + 2 <= arr[i]) break;
		sum += arr[i];
	}
	cout << sum + 1;
	return 0;
}
