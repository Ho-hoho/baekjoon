#include <iostream>
#include <algorithm>

using namespace std;

int N, S, temp, cnt = 0, maxnum, maxidx;
int arr[51];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> S;

    for (int i = 0; i < N - 1 && S != 0; i++)
    {
        cnt = 0;
        maxnum = arr[i];
        maxidx = i;
        for (int j = i + 1; j < N && cnt < S; j++, cnt++)
        {
            if (maxnum < arr[j])
            {
                maxnum = arr[j];
                maxidx = j;
            }
        }
        int j = maxidx;
        if (maxidx > i)
        {
            while (j != i)
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }
        S -= (maxidx - i);
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    return (0);
}