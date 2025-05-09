#include <iostream>
using namespace std;

// Hàm đệ quy quay lui để kiểm tra có tập con nào có tổng bằng mục tiêu hay không
bool kiemTraTongTapCon(int mang[], int kichThuoc, int mucTieu, int viTri, int tongHienTai) {
    // Nếu tổng hiện tại bằng mục tiêu, trả về true
    if (tongHienTai == mucTieu) {
        return true;
    }

    // Nếu đã xét hết mảng hoặc tổng hiện tại đã vượt quá mục tiêu, trả về false
    if (viTri >= kichThuoc || tongHienTai > mucTieu) {
        return false;
    }

    // Lựa chọn 1: Bao gồm phần tử tại vị trí hiện tại vào tổng
    if (kiemTraTongTapCon(mang, kichThuoc, mucTieu, viTri + 1, tongHienTai + mang[viTri])) {
        return true;
    }

    // Lựa chọn 2: Bỏ qua phần tử tại vị trí hiện tại
    if (kiemTraTongTapCon(mang, kichThuoc, mucTieu, viTri + 1, tongHienTai)) {
        return true;
    }

    // Không có tập con nào thỏa mãn
    return false;
}

int main() {
    int soPhanTu, mucTieu;

    cin >> soPhanTu >> mucTieu;

    int duLieu[soPhanTu];

    for (int i = 0; i < soPhanTu; i++) {
        cin >> duLieu[i];
    }

    // Gọi hàm kiểm tra tổng tập con
    bool coTapCon = kiemTraTongTapCon(duLieu, soPhanTu, mucTieu, 0, 0);
    
    if (coTapCon) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
