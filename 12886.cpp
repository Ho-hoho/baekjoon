#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[3];
int visited[1001][1001] = { 0 };
queue<pair<int,int>> bfs;

void check() {
	sort(arr, arr + 3);
	if (!visited[arr[0]][arr[1]]) {
		bfs.push(make_pair(arr[0], arr[1]));
		visited[arr[0]][arr[1]] = 1;
	}
}

void solve() {
	if ((arr[0] + arr[1] + arr[2]) % 3 != 0) {
		printf("0");
		return;
	}
	int sum = arr[0] + arr[1] + arr[2];
	sort(arr, arr + 3);
	bfs.push(make_pair(arr[0], arr[1]));
	while (!bfs.empty()) {
		arr[0] = bfs.front().first;
		arr[1] = bfs.front().second;
		arr[2] = sum - arr[0] - arr[1];	
		if (arr[0] == arr[1] && arr[1] == arr[2]) {
			printf("1");
			return;
		}
		bfs.pop();
		int a = arr[0];int b = arr[1];int c = arr[2];
		arr[0] = a + a; arr[1] = b; arr[2] = c - a;
		check();
		arr[0] = a + a; arr[1] = b - a; arr[2] = c;
		check();
		arr[0] = a; arr[1] = b + b; arr[2] = c - b;
		check();
	}
	printf("0");
	return;
}

int main() {
	cin >> arr[0] >> arr[1] >> arr[2];
	solve();

	return 0;
}
