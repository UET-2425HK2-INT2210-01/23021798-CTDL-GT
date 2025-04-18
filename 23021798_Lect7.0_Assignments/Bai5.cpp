#include <iostream>
using namespace std;

// Hàm đệ quy đếm số lượng chữ số
int countDigits(int n) {
    if (n == 0) return 0; // Điều kiện dừng
    return 1 + countDigits(n / 10); // Mỗi lần bỏ 1 chữ số (chia 10)
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (n == 0)
        cout << "So chu so cua " << n << " la: 1" << endl; // Trường hợp riêng cho n=0
    else
        cout << "So chu so cua " << n << " la: " << countDigits(n) << endl;
    return 0;
}
