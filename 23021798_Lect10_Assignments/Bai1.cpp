#include<iostream>
#include<vector>

using namespace std;

const int MAX_NODES = 1000; 
vector<int> adjacencyList[MAX_NODES]; // danh sách kề của đồ thị

bool isVisited[MAX_NODES]; // mảng đánh dấu các đỉnh đã được thăm

// Hàm DFS để duyệt các đỉnh trong một thành phần liên thông
void DFS(int currentNode) {
    isVisited[currentNode] = true; // đánh dấu đỉnh hiện tại đã được thăm
    for(int adjacentNode : adjacencyList[currentNode]) { // duyệt qua tất cả đỉnh kề
        if(!isVisited[adjacentNode]) { // nếu đỉnh kề chưa được thăm
            DFS(adjacentNode); // đệ quy duyệt tiếp từ đỉnh kề
        }
    }
}

int main() {
    int totalNodes, totalEdges; // totalNodes là số đỉnh, totalEdges là số cạnh
    cin >> totalNodes >> totalEdges;

    for(int i = 0; i < totalEdges; i++){
        int u, v; // u và v là hai đỉnh của một cạnh
        cin >> u >> v; 
        adjacencyList[u].push_back(v); // thêm v vào danh sách kề của u
        adjacencyList[v].push_back(u); // thêm u vào danh sách kề của v (vì là đồ thị vô hướng)
    }

    int connectedComponentsCount = 0; // biến đếm số thành phần liên thông
    for(int node = 1; node <= totalNodes; node++) { // duyệt qua tất cả các đỉnh
        if(!isVisited[node]) { // nếu đỉnh chưa được thăm
            DFS(node); // thực hiện DFS từ đỉnh này
            connectedComponentsCount++; // tăng số lượng thành phần liên thông
        }
    }

    cout << connectedComponentsCount; // in ra kết quả

    return 0; 
}
