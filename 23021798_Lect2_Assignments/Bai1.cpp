#include <iostream>
#include <string.h>
using namespace std;

                            // Bài tập 1
int main()
{
    int n; cin >> n;
    int a[n]; for (int &x : a) cin >> x;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j]) cnt++;
        }
    }
    cout << cnt;
}