#include <iostream>
using namespace std;

// Hàm đệ quy tính số Fibonacci thứ n
int fibonacci(int n) {
    if (n == 0) return 0; // F(0) = 0
    if (n == 1) return 1; // F(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2); // Công thức: F(n) = F(n-1) + F(n-2)
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "So Fibonacci thu " << n << " la: " << fibonacci(n) << endl;
    return 0;
}
