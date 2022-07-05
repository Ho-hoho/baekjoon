#include <iostream>

using namespace std;
int N, K,ans=0;
int arr[9] = { 0 };
int visited[9] = { 0 };
void solve (int n, int k,int day){
	if (k < 500)
		return;
	else if (day == N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			solve(i, k - K +arr[i] , day + 1);
			visited[i] = 0;
		}
	}

}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	solve(N,500,0);
	printf("%d\n", ans);
}
