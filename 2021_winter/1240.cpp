#include <iostream>
#include <string>

using namespace std;
int N, M;
int arr[1010][1010] ;

int main() {
	cin >> N >> M;

	for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) arr[i][j] = 987654321;
	int a, b,d;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b >>d;
		arr[a][b] = d;
		arr[b][a] = d;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << arr[a][b] << "\n";
	}
	return 0;
}
