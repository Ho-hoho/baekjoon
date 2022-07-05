#include <iostream>
#include <algorithm>
using namespace std;

int N, M, T,cnt=0;
typedef struct node {
	int parent;
	int rank;
}NODE;
int party[51][51] = { 0 };
NODE ds[51];

int Find(int a) {
	if (a == ds[a].parent)
		return a;
	return ds[a].parent = Find(ds[a].parent);
	
}
void Union(int a, int b) {
	int x = Find(a);
	int y = Find(b);
	if (x == y)
		return;
	if (ds[x].rank == 1) {
		ds[y].parent = x;
	}
	else {
		ds[x].parent = y;
	}
}

void solve() {
	for (int i = 0; i < M; i++) {
		for (int j = 2; j <= party[i][0]; j++) {
			Union(party[i][1], party[i][j]);
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 1; j <= party[i][0]; j++) {
			if (ds[ Find(party[i][j]) ].rank)
				break;
			else if (j == party[i][0]) {
				cnt++;
			}
		}
	}
	cout << cnt;
}
int main() {
	cin >> N >> M;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int tmp;
		cin >> tmp;
		ds[tmp].rank = 1;
	}
	for(int i=1;i<=N;i++)
		ds[i].parent = i;
	for (int i = 0; i < M; i++) {
		cin >> party[i][0];
		for (int j = 1; j <= party[i][0]; j++)
			cin >> party[i][j];
	}

	if (T == 0)
		cout << M;
	else 
		solve();
	
	return 0;
}
