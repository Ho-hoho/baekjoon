#include <iostream>
#include <queue>
using namespace std;

int tc;

int main() {
	cin >> tc;
	while (tc--) {
		vector<int> mid;
		int n,pivot,a,b;
		
		priority_queue <int, vector<int>, greater<int>> rpq;
		priority_queue<int> lpq;

		cin >> n >> pivot; mid.push_back(pivot);
		for (int i = 2; i <= n; i+=2) {
			cin >> a >> b;
			if (a >= pivot)	rpq.push(a);
			else lpq.push(a);

			if (b >= pivot) rpq.push(b);
			else lpq.push(b);
			
			if (lpq.size() != rpq.size()) {
				if (lpq.size() > rpq.size()) {
					rpq.push(pivot);
					pivot = lpq.top();
					lpq.pop();
				}
				else {
					lpq.push(pivot);
					pivot = rpq.top();
					rpq.pop();
				}
			}
			mid.push_back(pivot);			
		}

		cout << mid.size() << "\n";
		for (int i = 0; i < mid.size(); i++) {
			cout << mid[i] << " ";
			if (i % 10 == 9 ) cout << "\n";
		}

	}

}
