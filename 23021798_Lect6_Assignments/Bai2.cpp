#include <iostream>
#include <vector>
using namespace std;

// Lớp MinHeap biểu diễn một Heap nhị phân tối thiểu
class MinHeap {
public:
    vector<int> mangHeap; // Mảng chứa các phần tử của heap

    MinHeap() {} // Constructor mặc định

    // Hàm trả về chỉ mục của cha của một nút
    int chiMucCha(int index) { return (index - 1) / 2; }
    // Hàm trả về chỉ mục của con trái
    int chiMucConTrai(int index) { return 2 * index + 1; }
    // Hàm trả về chỉ mục của con phải
    int chiMucConPhai(int index) { return 2 * index + 2; }

    // Hàm chèn một giá trị vào heap
    void chenGiaTri(int value) {
        mangHeap.push_back(value); // Thêm vào cuối
        int index = mangHeap.size() - 1; // Lấy vị trí mới
        
        // Điều chỉnh vị trí để đảm bảo tính chất của heap
        while (index != 0 && mangHeap[chiMucCha(index)] > mangHeap[index]) {
            swap(mangHeap[index], mangHeap[chiMucCha(index)]);
            index = chiMucCha(index);
        }
    }

    // Hàm lấy giá trị nhỏ nhất từ heap
    int layGiaTriNhoNhat() {
        if (!mangHeap.empty()) return mangHeap[0]; // Giá trị nhỏ nhất là gốc heap
        return -1; // Trả về -1 nếu heap rỗng
    }

    // Hàm xóa một giá trị khỏi heap
    void xoaGiaTri(int value) {
        int index = -1;
        for (int i = 0; i < mangHeap.size(); i++) {
            if (mangHeap[i] == value) {
                index = i;
                break;
            }
        }
        
        if (index == -1) return; // Không tìm thấy giá trị
        
        mangHeap[index] = mangHeap.back(); // Thay thế bằng phần tử cuối
        mangHeap.pop_back(); // Xóa phần tử cuối
        
        if (index < mangHeap.size()) {
            dieuChinhHeap(index); // Điều chỉnh heap nếu cần
            while (index != 0 && mangHeap[chiMucCha(index)] > mangHeap[index]) {
                swap(mangHeap[index], mangHeap[chiMucCha(index)]);
                index = chiMucCha(index);
            }
        }
    }

    // Hàm điều chỉnh heap để duy trì tính chất của nó
    void dieuChinhHeap(int index) {
        int nhoNhat = index;
        int chiMucTrai = chiMucConTrai(index);
        int chiMucPhai = chiMucConPhai(index);

        if (chiMucTrai < mangHeap.size() && mangHeap[chiMucTrai] < mangHeap[nhoNhat]) {
            nhoNhat = chiMucTrai;
        }
        if (chiMucPhai < mangHeap.size() && mangHeap[chiMucPhai] < mangHeap[nhoNhat]) {
            nhoNhat = chiMucPhai;
        }
        if (nhoNhat != index) {
            swap(mangHeap[index], mangHeap[nhoNhat]);
            dieuChinhHeap(nhoNhat);
        }
    }

    // Hàm in ra các phần tử trong heap
    void inHeap() {
        for (int val : mangHeap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    vector<int> giaTriBanDau = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    
    // Chèn các giá trị ban đầu vào heap
    cout << "Chèn các giá trị ban đầu: ";
    for (int val : giaTriBanDau) {
        heap.chenGiaTri(val);
    }
    heap.inHeap();
    
    // Thêm các giá trị mới vào heap
    vector<int> giaTriChen = {14, 0, 35};
    cout << "\nHeap sau khi chèn 14, 0, 35:" << endl;
    for (int val : giaTriChen) {
        heap.chenGiaTri(val);
    }
    heap.inHeap();
    
    // Xóa các giá trị khỏi heap
    vector<int> giaTriXoa = {6, 13, 35};
    cout << "\nHeap sau khi xóa 6, 13, 35:" << endl;
    for (int val : giaTriXoa) {
        heap.xoaGiaTri(val);
    }
    heap.inHeap();
    
    return 0;
}