#include <iostream>

using namespace std;

int arr[1000002];
int tmp[1000002];
long long ans=0;

void mergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) >> 1;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);

        int left = start, right = mid + 1;
        int idx = start;


        while (left <= mid || right <= end) {
            if (right > end || (left <= mid && arr[left] < arr[right])) {
                tmp[idx++] = arr[left++];
            }
            else {
                ans += (mid - left + 1);
                tmp[idx++] = arr[right++];
            }
        }
        for (int i = start; i <= end; i++)
            arr[i] = tmp[i];
    }
}
int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    mergeSort(0, n - 1);
    cout << ans;

    return 0;
}
