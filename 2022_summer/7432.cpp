#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

int n;

struct Node {
	map<string, Node*> child;

	void addNode(vector<string>v,int idx) {
		if (idx == v.size()) return;
		auto iter = child.find(v[idx]);
		if (iter != child.end())
			iter->second->addNode(v, idx + 1);
		else {
			Node* n = new Node;
			child.insert({ v[idx],n });
			n->addNode(v, idx + 1);
		}
	}

	void print(int idx) {
		if (child.empty()) return;
		for (auto iter = child.begin(); iter != child.end(); iter++) {
			for (int i = 0; i < idx; i++)
				cout << " ";
			cout << iter->first << "\n";
			iter->second->print(idx+1);
		}
	}
};

vector <string> split(string s, char sep) {
	vector <string> ans;
	stringstream ss(s);
	string tmp;

	while (getline(ss, tmp, sep))
		ans.push_back(tmp);
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	Node* root = new Node;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		vector <string> v = split(s,'\\' );
		root->addNode(v,0);
	}
	root->print(0);
	return 0;
}
