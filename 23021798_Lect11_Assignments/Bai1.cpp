#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Hằng số đại diện cho vô cực (INF)
const long long INF = 1000000000000000LL;

// Cấu trúc cạnh có hướng với trọng số
struct Edge {
    int from;       // đỉnh xuất phát
    int to;         // đỉnh đích
    long long weight; // trọng số (độ bẩn của đường)
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- 1. Nhập dữ liệu ---
    int totalCities, totalRoads, sourceCity, targetCity;
    cin >> totalCities >> totalRoads >> sourceCity >> targetCity;

    vector<Edge> roadList;
    roadList.reserve(totalRoads);

    for (int i = 0; i < totalRoads; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        roadList.push_back({u, v, w});
    }

    // --- 2. Bellman–Ford để tìm đường đi ngắn nhất từ sourceCity đến targetCity ---
    vector<long long> minDistance(totalCities + 1, INF); // mảng lưu khoảng cách ngắn nhất
    vector<int> predecessor(totalCities + 1, -1);         // mảng lưu đỉnh trước đó trong đường đi

    minDistance[sourceCity] = 0;

    // Thư giãn cạnh tối đa (totalCities - 1) lần
    for (int iteration = 1; iteration < totalCities; iteration++) {
        bool updated = false;
        for (const Edge& edge : roadList) {
            int u = edge.from;
            int v = edge.to;
            long long w = edge.weight;
            if (minDistance[u] < INF && minDistance[u] + w < minDistance[v]) {
                minDistance[v] = minDistance[u] + w;
                predecessor[v] = u;
                updated = true;
            }
        }
        if (!updated) break; // không có cập nhật nào, dừng sớm
    }

    // --- 2.3. Xuất kết quả Bellman–Ford ---
    if (minDistance[targetCity] >= INF / 2) {
        cout << "INF\n\n"; // không có đường đi
    } else {
        cout << minDistance[targetCity] << "\n"; // in tổng độ bẩn

        // Truy vết đường đi từ targetCity về sourceCity
        vector<int> path;
        int current = targetCity;
        while (current != -1) {
            path.push_back(current);
            current = predecessor[current];
        }
        // Đảo ngược để in từ sourceCity đến targetCity
        reverse(path.begin(), path.end());

        for (int i = 0; i < (int)path.size(); i++) {
            if (i) cout << ' ';
            cout << path[i];
        }
        cout << "\n";
    }

    // --- 3. Floyd–Warshall để tính đường đi ngắn nhất giữa mọi cặp thành phố ---
    vector<vector<long long>> allPairsDist(totalCities + 1,
                                           vector<long long>(totalCities + 1, INF));

    // Khoảng cách từ một thành phố đến chính nó là 0
    for (int i = 1; i <= totalCities; i++) {
        allPairsDist[i][i] = 0;
    }

    // Cập nhật trọng số đường đi ban đầu
    for (const Edge& edge : roadList) {
        int u = edge.from;
        int v = edge.to;
        long long w = edge.weight;
        if (w < allPairsDist[u][v]) {
            allPairsDist[u][v] = w;
        }
    }

    // Thuật toán Floyd–Warshall
    for (int k = 1; k <= totalCities; k++) {
        for (int i = 1; i <= totalCities; i++) {
            if (allPairsDist[i][k] >= INF) continue;
            for (int j = 1; j <= totalCities; j++) {
                if (allPairsDist[k][j] < INF &&
                    allPairsDist[i][k] + allPairsDist[k][j] < allPairsDist[i][j]) {
                    allPairsDist[i][j] = allPairsDist[i][k] + allPairsDist[k][j];
                }
            }
        }
    }

    // Xuất kết quả ma trận khoảng cách
    for (int i = 1; i <= totalCities; i++) {
        for (int j = 1; j <= totalCities; j++) {
            if (allPairsDist[i][j] >= INF / 2) {
                cout << "INF";
            } else {
                cout << allPairsDist[i][j];
            }
            if (j < totalCities) cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}
