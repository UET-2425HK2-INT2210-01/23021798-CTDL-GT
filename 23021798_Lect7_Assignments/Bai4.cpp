#include <iostream>
using namespace std;

int a[100]; // Mảng lưu trữ dãy nhị phân (giả sử n <= 100)

// Hàm đệ quy để sinh tất cả dãy nhị phân độ dài n
void generateBinary(int n, int i) {
    // Nếu đã điền đủ n vị trí, thì in ra dãy
    if (i == n) {
        for (int j = 0; j < n; j++) {
            cout << a[j];
        }
        cout << " ";
        return;
    }

    // Gán giá trị 0 vào vị trí hiện tại và tiếp tục đệ quy
    a[i] = 0;
    generateBinary(n, i + 1);

    // Gán giá trị 1 vào vị trí hiện tại và tiếp tục đệ quy
    a[i] = 1;
    generateBinary(n, i + 1);
}

int main() {
    int n;

    // Nhập độ dài n từ bàn phím
    cout << "Nhap do dai n: ";
    cin >> n;

    // Gọi hàm generateBinary để bắt đầu sinh dãy
    generateBinary(n, 0);

    return 0;
}
