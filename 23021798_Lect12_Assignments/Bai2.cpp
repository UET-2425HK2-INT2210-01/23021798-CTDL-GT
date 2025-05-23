#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc biểu diễn một kết nối giữa hai máy tính với chi phí tương ứng
struct Connection {
    int computerA, computerB, cost;

    // Toán tử so sánh để sắp xếp kết nối theo chi phí tăng dần
    bool operator<(const Connection& other) const {
        return cost < other.cost;
    }
};

const int MAX_COMPUTERS = 10005;  // Giới hạn số máy tính tối đa
int root[MAX_COMPUTERS];          // Mảng đại diện tổ hợp (Union-Find)

// Số lượng máy tính và số kết nối khả dĩ
int numComputers, numConnections;

// Tìm gốc của một máy tính (kỹ thuật nén đường đi)
int findRoot(int x) {
    if (root[x] != x)
        root[x] = findRoot(root[x]);  // Nén đường đi
    return root[x];
}

// Hợp nhất hai nhóm máy tính. Trả về true nếu hợp nhất thành công
bool merge(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if (rootA == rootB) return false;  // Nếu cùng nhóm → bỏ (tránh chu trình)
    root[rootA] = rootB;               // Hợp nhất nhóm
    return true;
}

int main() {
    ifstream input("connection.txt");        // Mở file đầu vào
    ofstream output("connection.out");       // Mở file đầu ra

    input >> numComputers >> numConnections;  // Đọc số lượng máy và kết nối
    vector<Connection> allConnections(numConnections);  // Danh sách các kết nối

    // Nhập dữ liệu từng kết nối
    for (int i = 0; i < numConnections; ++i) {
        input >> allConnections[i].computerA 
              >> allConnections[i].computerB 
              >> allConnections[i].cost;
    }

    // Khởi tạo mỗi máy là gốc của chính nó
    for (int i = 1; i <= numComputers; ++i)
        root[i] = i;

    // Sắp xếp kết nối theo chi phí từ thấp đến cao
    sort(allConnections.begin(), allConnections.end());

    int minimumTotalCost = 0;                     // Tổng chi phí của mạng tối ưu
    vector<Connection> selectedConnections;       // Kết nối được chọn vào mạng

    // Duyệt qua tất cả các kết nối đã sắp xếp
    for (Connection& conn : allConnections) {
        if (merge(conn.computerA, conn.computerB)) {
            minimumTotalCost += conn.cost;          // Cộng chi phí
            selectedConnections.push_back(conn);    // Thêm vào kết quả
        }
    }

    // Xuất kết quả tổng chi phí
    output << minimumTotalCost << endl;

    // Xuất các kết nối được chọn
    for (Connection& conn : selectedConnections) {
        output << conn.computerA << " " 
               << conn.computerB << " " 
               << conn.cost << endl;
    }

    input.close();   // Đóng file đầu vào
    output.close();  // Đóng file đầu ra

    return 0;        // Kết thúc chương trình
}
