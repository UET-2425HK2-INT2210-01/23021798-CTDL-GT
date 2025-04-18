#include <iostream>
using namespace std;

// Hàm đệ quy tính x^n
int power(int x, int n) {
    if (n == 0) return 1; // Bất kỳ số nào mũ 0 cũng bằng 1
    return x * power(x, n - 1); // Công thức: x^n = x * x^(n-1)
}

int main() {
    int x, n;
    cout << "Nhap x va n: ";
    cin >> x >> n;
    cout << x << "^" << n << " = " << power(x, n) << endl;
    return 0;
}
