#include <iostream>
using namespace std;

// Hàm phân hoạch theo cách Hoare
int partitionHoare(int arr[], int low, int high) {
    int pivot = arr[low]; // Chọn pivot là phần tử đầu tiên
    int i = low - 1;
    int j = high + 1;

    while (true) {
        // Tìm phần tử lớn hơn hoặc bằng pivot từ trái sang phải
        do {
            i++;
        } while (arr[i] < pivot);

        // Tìm phần tử nhỏ hơn hoặc bằng pivot từ phải sang trái
        do {
            j--;
        } while (arr[j] > pivot);

        // Nếu hai con trỏ đã giao nhau thì trả về vị trí phân hoạch
        if (i >= j)
            return j;

        // Đổi chỗ hai phần tử không đúng vị trí
        swap(arr[i], arr[j]);
    }
}

// Hàm QuickSort dùng phân hoạch Hoare
void quickSortHoare(int arr[], int low, int high) {
    if (low < high) {
        // Phân hoạch và đệ quy sắp xếp 2 bên
        int pi = partitionHoare(arr, low, high);
        quickSortHoare(arr, low, pi);      // Bên trái
        quickSortHoare(arr, pi + 1, high); // Bên phải
    }
}
