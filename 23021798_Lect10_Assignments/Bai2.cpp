#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Hàm thực hiện BFS để tìm khoảng cách ngắn nhất từ start đến end
int BFS(int totalNodes, vector<vector<int>>& adjacencyList, int startNode, int endNode) {
    vector<int> distance(totalNodes + 1, -1); // mảng lưu khoảng cách, khởi tạo -1 là chưa được thăm
    queue<int> q; // hàng đợi để phục vụ BFS

    distance[startNode] = 0; // khoảng cách từ startNode đến chính nó là 0
    q.push(startNode); // đưa startNode vào hàng đợi

    while (!q.empty()) { // lặp cho đến khi hàng đợi rỗng
        int currentNode = q.front(); // lấy đỉnh đầu tiên trong hàng đợi
        q.pop(); // loại bỏ phần tử đầu khỏi hàng đợi

        for (int neighbor : adjacencyList[currentNode]) { // duyệt qua các đỉnh kề
            if (distance[neighbor] == -1) { // nếu đỉnh chưa được thăm
                distance[neighbor] = distance[currentNode] + 1; // cập nhật khoảng cách
                q.push(neighbor); // thêm đỉnh kề vào hàng đợi
            }
        }
    }

    return distance[endNode]; // trả về khoảng cách từ startNode đến endNode
}

int main() {
    int totalNodes, totalEdges, sourceNode, targetNode;
    cin >> totalNodes >> totalEdges >> sourceNode >> targetNode;

    vector<vector<int>> adjacencyList(totalNodes + 1); // danh sách kề

    for (int i = 0; i < totalEdges; i++) {
        int fromNode, toNode;
        cin >> fromNode >> toNode;
        adjacencyList[fromNode].push_back(toNode); // thêm cạnh có hướng
    }

    int shortestDistance = BFS(totalNodes, adjacencyList, sourceNode, targetNode);
    cout << shortestDistance;

    return 0;
}
