#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M,cnt;
int parent[1001] = { 0 };
vector<int>connected;
int Find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	parent[a] = parent[b];
	return ;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int x = Find(a);
		int y = Find(b);
		if (x != y) {
			Union(x, y);
		}
	}
	for (int i = 1; i <= N; i++) {
		int tmp = Find(i);
		if (find(connected.begin(), connected.end(), tmp) == connected.end()) {
			connected.push_back(tmp);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
