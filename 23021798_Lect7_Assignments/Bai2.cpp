#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

// Thuật toán Kadane để tìm đoạn con liên tiếp có tổng lớn nhất trong mảng 1 chiều
int kadane(const vector<int>& arr, int& start, int& finish, int n) {
    int sum = 0, maxSum = INT_MIN;
    int local_start = 0;
    finish = -1;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum < arr[i]) {
            sum = arr[i];
            local_start = i;
        }
        if (sum > maxSum) {
            maxSum = sum;
            start = local_start;
            finish = i;
        }
    }

    // Trường hợp đặc biệt: tất cả các số đều âm
    if (finish == -1) {
        maxSum = arr[0];
        start = finish = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > maxSum) {
                maxSum = arr[i];
                start = finish = i;
            }
        }
    }

    return maxSum;
}

int main() {
    // Mở file để đọc dữ liệu ma trận
    ifstream infile("matrix.txt");
    ofstream outfile("matrix.out");

    int m, n;
    infile >> m >> n; // đọc số dòng (m) và số cột (n)

    // Khởi tạo ma trận m dòng n cột
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            infile >> matrix[i][j]; // đọc từng phần tử của ma trận

    int maxSum = INT_MIN; // Khởi tạo tổng lớn nhất ban đầu
    int finalLeft, finalRight, finalTop, finalBottom; // lưu tọa độ của hình chữ nhật tốt nhất

    // Xét tất cả các cặp dòng trên (top) và dưới (bottom)
    for (int top = 0; top < m; ++top) {
        vector<int> temp(n, 0); // mảng tạm lưu tổng các cột từ dòng top đến bottom
        for (int bottom = top; bottom < m; ++bottom) {
            // Cộng thêm giá trị dòng bottom vào mảng temp
            for (int i = 0; i < n; ++i)
                temp[i] += matrix[bottom][i];

            int left, right;
            // Áp dụng Kadane để tìm đoạn liên tiếp trên temp có tổng lớn nhất
            int sum = kadane(temp, left, right, n);

            // Cập nhật nếu tìm thấy tổng lớn hơn
            if (sum > maxSum) {
                maxSum = sum;
                finalTop = top;
                finalBottom = bottom;
                finalLeft = left;
                finalRight = right;
            }
        }
    }

    // Xuất kết quả ra file (dùng chỉ số bắt đầu từ 1 thay vì 0)
    outfile << finalTop + 1 << " " << finalLeft + 1 << " "
            << finalBottom + 1 << " " << finalRight + 1 << " "
            << maxSum << endl;

    // Đóng file
    infile.close();
    outfile.close();
    return 0;
}
