#include <iostream>
using namespace std;

// Hàm phân hoạch theo cách Lomuto
int partitionLomuto(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn pivot là phần tử cuối cùng
    int i = low - 1;       // i là chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn pivot
        if (arr[j] < pivot) {
            i++; // Tăng i và đổi chỗ arr[i] với arr[j]
            swap(arr[i], arr[j]);
        }
    }

    // Đặt pivot về đúng vị trí
    swap(arr[i + 1], arr[high]);
    return i + 1; // Trả về chỉ số của pivot
}

// Hàm QuickSort dùng phân hoạch Lomuto
void quickSortLomuto(int arr[], int low, int high) {
    if (low < high) {
        // Chia mảng và sắp xếp đệ quy
        int pi = partitionLomuto(arr, low, high);
        quickSortLomuto(arr, low, pi - 1);   // Sắp xếp bên trái pivot
        quickSortLomuto(arr, pi + 1, high);  // Sắp xếp bên phải pivot
    }
}
