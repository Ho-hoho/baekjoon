#include <iostream>
#include <vector>
using namespace std;
//vector<int> arr;
int arr[100001];
int N, S;
const int MAX = 100000;
const int INF = 987654321;
int MIN(int a, int b) {
	return a < b ? a : b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int low = 0, high = 0,result = INF;
	int sum = arr[0];
	while (low <= high && high < N) {
		if (sum < S) {
			sum += arr[++high];
		}
		else if (sum == S) {
			result = MIN(result, (high - low + 1));
			sum += arr[++high];
		}
		else if (sum > S) {
			result = MIN(result, (high - low + 1));
			sum -= arr[low++];
		}
	}
	if (result == INF)
		cout << 0<<'\n';
	else
		cout << result << '\n';
	return 0;

}
