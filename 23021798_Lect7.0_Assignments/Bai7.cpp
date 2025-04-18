#include <iostream>
using namespace std;

// Hàm phụ trợ để đảo ngược số
int reverseNumber(int n, int revNum) {
    if (n == 0) return revNum; // Điều kiện dừng
    revNum = revNum * 10 + n % 10; // Thêm chữ số cuối vào revNum
    return reverseNumber(n / 10, revNum); // Đệ quy với phần còn lại
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    cout << "So dao nguoc cua " << n << " la: " << reverseNumber(n, 0) << endl;
    return 0;
}
