#include <iostream>
#include <algorithm>
using namespace std;

int p[51]={0};
int narr[51];
int vis[10001]={0};
int w[10001];
int N, M, check = 0,maxnum=0;
int t=0;

int main() {
	//int time = 0; # 내장 함수여서 전역은 안되고 지역은 된다나 뭐라나
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> narr[i];
		if (narr[i] > maxnum) maxnum = narr[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> w[i];

	sort(w, w + M,greater<>());
	if (w[0] > maxnum) {
		cout << -1;
		return 0;
	}
	while (check != M) {
		for (int i = 0; i < N; i++) {
			for (int j = p[i]; j < M; j++) {
				if (!vis[j] && narr[i] >= w[j]) {
					vis[j] = 1; check++; break;
				}
				p[i]++;
			}
		}
		t++; 
	}
	cout << t;
	return 0;
}
