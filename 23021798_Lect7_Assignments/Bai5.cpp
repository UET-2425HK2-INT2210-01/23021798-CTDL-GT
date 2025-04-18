#include <iostream>
#include <cmath>
using namespace std;

int n;
int visited[10001]; // Mảng đánh dấu số đã được sử dụng hay chưa
int ans[10001];     // Mảng lưu thứ tự hiện tại của hoán vị

// Hàm đệ quy để sinh tất cả các hoán vị của 1..n
void solve(int i)
{
    // Duyệt qua tất cả các số từ 1 đến n
    for (int j = 1; j <= n; j++)
    {
        // Nếu số j chưa được sử dụng
        if (!visited[j])
        {
            ans[i] = j;     // Gán số j vào vị trí thứ i
            visited[j] = 1; // Đánh dấu j đã được sử dụng

            // Nếu đã gán đủ n vị trí, in ra hoán vị
            if (i == n)
            {
                for (int k = 1; k <= n; k++)
                {
                    cout << ans[k];
                }
                cout << " ";
            }
            else
            {
                // Nếu chưa đủ, tiếp tục gán cho vị trí tiếp theo
                solve(i + 1);
            }

            // Quay lui: bỏ đánh dấu số j để dùng cho các nhánh khác
            visited[j] = 0;
        }
    }
}

int main()
{
    cin >> n;     // Nhập vào số n
    solve(1);     // Gọi hàm đệ quy bắt đầu từ vị trí đầu tiên
}
