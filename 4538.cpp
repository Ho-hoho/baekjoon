#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//freopen("input.txt", "r", stdin);

	map<string, int> m;
	string str;
	int cnt = 0;
	while (getline(cin, str)) {
		m[str]++; cnt++;
	}
	cout << fixed;
	cout.precision(4);

	for (auto i = m.begin(); i != m.end(); i++)
		cout << i->first << " " << i->second * 100 / (double)cnt << "\n";
	return 0;
}
