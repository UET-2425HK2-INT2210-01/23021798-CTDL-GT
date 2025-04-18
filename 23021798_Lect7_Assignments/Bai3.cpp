#include <iostream>
using namespace std;

// Hàm đệ quy tìm ước chung lớn nhất (GCD) của hai số
int gcd(int x, int y) {
    // Nếu y = 0, thì GCD là x
    if (y == 0)
        return x;
    // Gọi đệ quy với tham số mới (y, x % y)
    return gcd(y, x % y);
}

int main() {
    int X, Y;

    // Nhập hai số nguyên từ người dùng
    cout << "Nhap hai so nguyen X va Y: ";
    cin >> X >> Y;

    // Gọi hàm gcd và in kết quả
    cout << "Uoc chung lon nhat cua " << X << " va " << Y << " la: " << gcd(X, Y) << endl;

    return 0;
}
