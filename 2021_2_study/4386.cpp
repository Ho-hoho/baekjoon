#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> parent(101);
vector<pair<double, double>> arr;
vector<pair<double,pair<int,int>>> edge;
int N;
int init_set(int n) {
	parent[n] = -1 ;
	return 0;
}
int find_set(int v) {
	while (parent[v] >= 0)
		v = parent[v];
	return v;
}
void union_set(int u, int v) {
	parent[v] = u;
}
double kruskal() {
	double mst_e = 0;
	int mst_e_n = 0;
	sort(edge.begin(), edge.end());
	for (int i = 0; i < N; i++) {
		init_set(i);
	}
	for (int i = 0; mst_e_n < N - 1; i++) {
		int u = edge[i].second.first; int v = edge[i].second.second;
		int rootA = find_set(u);
		int rootB = find_set(v);
		if (rootA != rootB) {
			mst_e += edge[i].first;
			mst_e_n++;
			union_set(rootA, rootB);
		}
	}
	return mst_e;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		double buf1, buf2;
		cin >> buf1 >> buf2;
		arr.push_back({buf1,buf2});
	}
	cout << fixed;
	cout.precision(2);
	int edge_len=0;
	for (int i = 0; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			edge.push_back({ sqrt(pow(arr[i].first - arr[j].first,2) 
				+ pow(arr[i].second - arr[j].second,2)),{j + 1,i + 1} });
			edge_len++;
		}
	}
	
	cout << kruskal();

}
