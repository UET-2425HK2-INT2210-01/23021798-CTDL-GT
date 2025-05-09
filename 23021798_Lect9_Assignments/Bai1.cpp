#include <iostream>
using namespace std;

// Khai báo hàm phân hoạch để tránh lỗi biên dịch
int phanHoach(double mang[], int trai, int phai);

// Hàm QuickSort chính để sắp xếp mảng số thực
void quickSort(double mang[], int trai, int phai) {
    // Nếu chỉ số bên trái nhỏ hơn bên phải, tiếp tục chia nhỏ mảng
    if (trai < phai) {
        // Tìm vị trí chốt (pivot) sau khi phân hoạch
        int viTriChot = phanHoach(mang, trai, phai);
        
        // Đệ quy sắp xếp nửa bên trái của pivot
        quickSort(mang, trai, viTriChot - 1);
        // Đệ quy sắp xếp nửa bên phải của pivot
        quickSort(mang, viTriChot + 1, phai);
    }
}

// Hàm phân hoạch để chọn pivot và sắp xếp các phần tử xung quanh pivot
int phanHoach(double mang[], int trai, int phai) {
    // Chọn phần tử cuối cùng làm pivot
    double chot = mang[phai];
    // i là chỉ số của phần tử nhỏ hơn hoặc bằng pivot
    int i = trai - 1;
    
    // Duyệt qua các phần tử từ vị trí 'trai' đến 'phai - 1'
    for (int j = trai; j < phai; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (mang[j] <= chot) {
            // Tăng chỉ số i và hoán đổi phần tử tại i và j
            i++;
            double tam = mang[i];
            mang[i] = mang[j];
            mang[j] = tam;
        }
    }
    
    // Đặt pivot vào đúng vị trí bằng cách hoán đổi mang[i + 1] với mang[phai]
    double tam = mang[i + 1];
    mang[i + 1] = mang[phai];
    mang[phai] = tam;
    
    // Trả về vị trí mới của pivot
    return i + 1;
}

int main() {
    int kichThuoc;
    cin >> kichThuoc;
    
    // Khởi tạo mảng chứa các số thực cần sắp xếp
    double duLieu[kichThuoc];
    
    // Nhập các phần tử cho mảng
    for (int i = 0; i < kichThuoc; i++) {
        cin >> duLieu[i];
    }
    
    // Gọi hàm quickSort để sắp xếp mảng
    quickSort(duLieu, 0, kichThuoc - 1);
    
    // In ra mảng đã sắp xếp
    for (int i = 0; i < kichThuoc; i++) {
        cout << duLieu[i];
        if (i < kichThuoc - 1) {
            cout << " ";
        }
    }
    
    return 0;
}
