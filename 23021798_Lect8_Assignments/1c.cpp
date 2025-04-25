#include <iostream>
using namespace std;

// Hàm trộn hai mảng con đã được sắp xếp
void merge(int arr[], int left, int mid, int right) {
    // Kích thước hai mảng con
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo mảng tạm
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Trộn hai mảng con vào mảng chính
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy phần còn lại (nếu có)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Giải phóng bộ nhớ tạm
    delete[] L;
    delete[] R;
}

// Hàm Merge Sort chính
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Tránh tràn số

        // Đệ quy chia đôi mảng
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gộp hai mảng con lại
        merge(arr, left, mid, right);
    }
}
