#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int N, K,ans=0;
string s[51];
bool alp[27] = { false };
int max_num = 0;
void DFS(int idx,int cnt) {
	if (cnt == K) {
		int tmp=0;
		for (int i = 0; i < N; i++) {
			int flag = true;
			for (int j = 0; j < s[i].size(); j++) {
				if (!alp[s[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag)
				tmp++;
		}
		max_num = max(max_num, tmp);
		return;
	}
	else {
		for (int i = idx; i < 26; i++) {
			if (alp[i]) continue;
			alp[i] = true;
			DFS(i, cnt + 1);
			alp[i] = false;
		}
		
	}

}

int main() {
	cin >> N >> K;
	K = K - 5;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	alp['a' - 'a'] = true; alp['n' - 'a'] = true; alp['t' - 'a'] = true;
	alp['i' - 'a'] = true; alp['c' - 'a'] = true;

	DFS(0, 0);
	cout << max_num;

}
