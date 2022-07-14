#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Node {
	map<string, Node*> child;

	void insert(vector<string> v, int idx) {
		if (idx == v.size()) return;
		auto iter = child.find(v[idx]); // map<string,Node*>::iterator iter
		if ( iter != child.end()) { // 이미 존재
			iter->second->insert(v, idx + 1);
		}
		else {
			Node* n = new Node;
			child.insert({ v[idx],n });
			n->insert(v, idx + 1);
		}
	}

	void print(int idx) {
		if (child.empty()) return;
		for (auto iter = child.begin(); iter != child.end();iter++ ) {
			for (int i = 0; i < idx; i++) cout << "--";
			cout << iter->first << "\n";
			iter->second->print(idx + 1);
		}
	}

};




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	Node* root = new Node;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		vector<string> v;
		for (int j = 0; j < k; j++) {
			string ss;
			cin >> ss;
			v.push_back(ss);
		}
		root->insert(v,0);
	}
	root->print(0);

	return 0;
}
