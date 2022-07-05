#include <iostream>
#include <string>
using namespace std;

#define HASH_SIZE (200010)
#define MOD (200010 - 1)
struct Node {
	Node* next;
	int idx;
	char* name;
}nodearr[HASH_SIZE];

int N, M;
int node_cnt = 0;
Node* get_node(char name[], int idx) {
	Node* node = &nodearr[node_cnt++];
	node->name = name;
	node->idx = idx;
	return node;
}

int make_hash(char s[]) {
	long long ret = 0;
	for (register int i = 0; s[i] != 0; i++) {
		ret *= 33; ret += (s[i]-'A' + 1);
	}
	return (int)(ret & MOD);
}

Node* h[HASH_SIZE];
int get(char name[]) {
	int hash = make_hash(name);
	Node* cur = h[hash];
	while (cur != nullptr) {
		bool flag = true;
		for (int i = 0; i < 21; i++) {
			if (name[i] != cur->name[i]) { flag = false; break; }
		}
		if (flag) return cur->idx;
		cur = cur->next;
	}
}

void put(char name[], int idx) {
	int hash = make_hash(name);
	Node* node = get_node(name,idx);
	if (h[hash] == nullptr) h[hash] = node;
	else {
		node->next = h[hash];
		h[hash] = node;
	}
}

int contain(char name[]) {
	int hash = make_hash(name);
	if (h[hash] == nullptr) return 0;
	else {
		Node* cur = h[hash];
		while (cur != nullptr) {
			bool flag = true;
			for (int i = 0; i < 21; i++) {
				if (name[i] != cur->name[i]) { flag = false; break; }
			}
			if (flag) return 1;
			cur = cur->next;
		}
		return 0;
	}
}


struct node {
	int parent;
	int num = 1;
}dset[HASH_SIZE];


int Find(int a) {
	if (dset[a].parent == a)
		return a;
	return dset[a].parent = Find(dset[a].parent);
}

int Union(int x, int y) {
	int a = Find(x), b = Find(y);
	if (a != b) {
		dset[b].parent = dset[a].parent;
		dset[a].num += dset[b].num;
	}
	return dset[a].num;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> N;

	int key1, key2;
	int x, y;
	int name_cnt = 1;
	while (N--) {
		for (int i = 0; i < HASH_SIZE; i++) {
			dset[i].parent = i;
			dset[i].num = 1;
		}
		cin >> M;
		while (M--) {
			char* n1 = (char*)malloc(sizeof(char) * 21);
			char* n2 = (char*)malloc(sizeof(char) * 21);
			//char n1[21]; char n2[21];
			cin >> n1 >> n2;
			if (!contain(n1)) { put(n1, name_cnt++); }
			if (!contain(n2)) { put(n2, name_cnt++); }
			cout << Union(get(n1), get(n2)) << "\n";

		}

	}

}
