#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Hàm tự viết để sắp xếp nổi bọt (bubble sort)
void bubbleSort(vector<double>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Đổi chỗ nếu phần tử đứng trước lớn hơn phần tử đứng sau
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    ifstream inputFile("numbers.txt");  // Mở file đọc
    ofstream outputFile("numbers.sorted"); // Mở file ghi

    // Kiểm tra mở file thành công
    if (!inputFile || !outputFile) {
        cerr << "Lỗi mở file!" << endl;
        return 1;
    }

    vector<double> numbers;
    double num;

    // Đọc các số từ file vào mảng
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    inputFile.close(); // Đóng file sau khi đọc xong

    // Gọi hàm tự viết để sắp xếp
    bubbleSort(numbers);

    // Ghi ra file kết quả
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
        outputFile << fixed << setprecision(10) << numbers[i];
        if (i != n - 1) outputFile << " ";
    }

    outputFile << endl;
    outputFile.close(); // Đóng file ghi
    return 0;
}
