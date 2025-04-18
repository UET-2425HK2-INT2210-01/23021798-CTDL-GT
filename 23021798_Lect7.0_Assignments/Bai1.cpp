#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng từ 1 đến n
int sum(int n) {
    if (n == 0) return 0; // Điều kiện dừng: tổng đến 0 là 0
    return n + sum(n - 1); // Công thức đệ quy: tổng đến n bằng n cộng tổng đến (n-1)
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Tong tu 1 den " << n << " la: " << sum(n) << endl;
    return 0;
}
