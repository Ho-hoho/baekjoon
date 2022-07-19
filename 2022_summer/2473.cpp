#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> arr;
int n;
int ans[3] = { 0 };
bool flag = false;
long long minval = 4'000'000'001;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a,s1,s2,s3;
	long long temp;
	cin >> n ;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	for (int k = 0; k < n-2; k++) {
		s1 = k; 
		s2 = k+1;
		s3 = n - 1;
		while (s2 != s3) {
			temp = (long long)arr[s1] + arr[s2] + arr[s3];
			
			if ( abs(temp) < minval) {
				minval = abs(temp);
				ans[0] = arr[s1]; ans[1] = arr[s2]; ans[2] = arr[s3];
				if (temp == 0) {
					flag = true;
					break;
				}
			}

			if (temp > 0) {
				s3--;
			}
			else {
				s2++;
			}
			
		}
		if (flag) break;
	}
	
	cout << ans[0] << " " << ans[1] << " " << ans[2];

	return 0;
}
