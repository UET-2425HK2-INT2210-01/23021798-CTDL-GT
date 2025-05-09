#include <iostream>
using namespace std;

// Hàm tìm tổng giá trị lớn nhất có thể mang theo với giới hạn trọng lượng
int giaiBaiToanBalo(int soDoVat, int gioiHanCanNang, int trongLuong[], int giaTri[]) {
    // Tạo bảng dp để lưu giá trị tối ưu
    // dp[i][w] là giá trị lớn nhất khi chọn từ i vật đầu tiên và tổng trọng lượng không vượt quá w
    int dp[soDoVat + 1][gioiHanCanNang + 1];

    // Khởi tạo bảng dp
    for (int i = 0; i <= soDoVat; i++) {
        for (int w = 0; w <= gioiHanCanNang; w++) {
            // Nếu không có vật nào hoặc trọng lượng tối đa là 0 thì giá trị là 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // Trường hợp đang xét vật thứ i và giới hạn trọng lượng w
            else {
                // Không chọn vật thứ i
                dp[i][w] = dp[i - 1][w];

                // Nếu có thể chọn vật thứ i (trọng lượng không vượt quá giới hạn)
                if (trongLuong[i - 1] <= w) {
                    // Tính giá trị nếu chọn vật thứ i
                    int chon = giaTri[i - 1] + dp[i - 1][w - trongLuong[i - 1]];

                    // Lấy giá trị lớn hơn giữa chọn và không chọn
                    if (chon > dp[i][w]) {
                        dp[i][w] = chon;
                    }
                }
            }
        }
    }

    // Trả về kết quả tối ưu cuối cùng
    return dp[soDoVat][gioiHanCanNang];
}

int main() {
    int soDoVat, gioiHanCanNang;
    cin >> soDoVat >> gioiHanCanNang;

    int trongLuong[soDoVat], giaTri[soDoVat];

    // Nhập thông tin các đồ vật
    for (int i = 0; i < soDoVat; i++) {
        cin >> trongLuong[i] >> giaTri[i];
    }

    // Gọi hàm giải bài toán balo và in kết quả
    int ketQua = giaiBaiToanBalo(soDoVat, gioiHanCanNang, trongLuong, giaTri);
    cout << ketQua << endl;

    return 0;
}
