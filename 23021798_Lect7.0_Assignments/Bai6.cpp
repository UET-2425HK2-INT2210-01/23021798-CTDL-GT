#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng các chữ số
int sumOfDigits(int n) {
    if (n == 0) return 0; // Điều kiện dừng
    return (n % 10) + sumOfDigits(n / 10); // Cộng chữ số cuối và đệ quy với phần còn lại
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    cout << "Tong cac chu so cua " << n << " la: " << sumOfDigits(n) << endl;
    return 0;
}
