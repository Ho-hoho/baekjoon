#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int key;
	int u;
	int v;
}element;
int compare(const void* a, const void* b) {
	element* m = (element *)a;
	element* n = (element*)b;
	if (m->key < n->key)
		return -1;
	if (m->key > n->key)
		return 1;
	return 0;
}
int parent[10001] = { 0 };
int edge_num ,V;
element edge_set[100001] = { 0 };
int init_set(int n) {
	parent[n] = -1;
	return 0;
}
int find_set(int v) {
	while (parent[v] >= 0) {
		v = parent[v];
	}
	return v;
}/*
void union_set(int n1, int n2) {
	if (parent[n1] < 0 && parent[n2] < 0) {
		if (parent[n1] <= parent[n2]) {
			int temp = parent[n2];
			parent[n2] = n1;
			parent[n1] += temp;
		}
		else {
			int temp = parent[n1];
			parent[n1] = n2;
			parent[n2] += temp;

		}
	}
	else if (parent[n1] < 0 && parent[n2] >= 0) {
		int temp = parent[n1];
		parent[n1] = n2;
		parent[parent[n2]] += temp;
	}
	else if (parent[n1] >= 0 && parent[n2] < 0) {
		int temp = parent[n2];
		parent[n2] = parent[n1];
		parent[parent[n1]] += temp;
	}
	else {
		int temp = parent[n1];
		parent[n1] = parent[n2];
		parent[temp] = parent[n2];
	}
}*/
void union_set(int u, int v) {
	parent[v] = u;
}
int kruskal(element e[],int n) {
	int mst_e = 0;
	int mst_e_n = 0;
	qsort(e, edge_num, sizeof(element), compare);
	for (int i = 0; i < n; i++)
		init_set(i);
	for (int i = 0; mst_e_n < n - 1; i++) {
		int u = e[i].u; int v = e[i].v;
		int rootA = find_set(u);
		int rootB = find_set(v);
		if (rootA != rootB) {
			mst_e += e[i].key;
			mst_e_n++;
			union_set(rootA, rootB);
		}
	}
	return mst_e;
}

int main() {
	scanf("%d %d", &V, &edge_num);
	for (int i = 0; i < edge_num; i++) {
		scanf("%d %d %d", &edge_set[i].u, &edge_set[i].v, &edge_set[i].key);
	}
	printf("%d", kruskal(edge_set,V));
	return 0;
}
