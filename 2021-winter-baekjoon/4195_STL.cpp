#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int N, M;
struct node {
	string parent="\0";
	int num=0;
};

unordered_map<string, node> m;
int num[200020];


string Find(string a) {
	if (m[a].parent == a)
		return a;
	return m[a].parent = Find(m[a].parent);
}

int Union(string x, string y) {
	string a = Find(x); string b = Find(y);
	if (a != b) {
		m[b].parent = a;
		m[a].num += m[b].num;
	}
	return m[a].num;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	string in,in2;
	string a, b;
	while (N--) {
		m.clear();
		memset(num, 0, sizeof(num));
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> in >> in2;
			if (m[in].parent == "\0") {
				m[in].parent = in;
				m[in].num += 1;
			}
			if (m[in2].parent == "\0") {
				m[in2].parent = in2;
				m[in2].num += 1;
			}
			cout << Union(in, in2) << "\n";

		}

	}
}
