#include <iostream>
using namespace std;

// Hàm đệ quy tính giai thừa của n
int factorial(int n) {
    if (n == 0 || n == 1) return 1; // Điều kiện dừng: 0! = 1! = 1
    return n * factorial(n - 1); // Công thức đệ quy: n! = n * (n-1)!
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Giai thua cua " << n << " la: " << factorial(n) << endl;
    return 0;
}
