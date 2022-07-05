#include <iostream>

using namespace std;
int N;
int skill[4];
int ans[1000001] = { 0 };
int arr[1000001] = { 0 };

void change(int i) {
	if (i == 1 || i == 2) {
		do {
			skill[i]++;
		} while (arr[skill[i]]);
	}
	else {
		do {
			skill[i]--;
		} while (arr[skill[i]]);

	}
}
int main() {
	cin >> N;
	skill[1] = 1;
	skill[2] = 2;
	skill[3] = N;
	for (int i = N; i >= 1 ; i--) {
		int type;
		cin >> type;
		arr[skill[type]] = i;
		switch (type) {
		case 1 :
			change(1);
			change(2);
			break;
		case 2:
			change(2);
			break;
		case 3:
			change(3);
			break;
		}
	}
	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";
	
	return 0;
}
