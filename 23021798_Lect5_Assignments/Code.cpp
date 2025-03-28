#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính chiều cao của cây
int height(int node, const vector<vector<int>>& adj) {
    if (adj[node].empty()) {
        return 0;
    }
    int maxHeight = 0;
    for (int child : adj[node]) {
        maxHeight = max(maxHeight, height(child, adj));
    }
    return maxHeight + 1;
}

// Hàm thực hiện duyệt cây theo thứ tự trước
void preorder(int node, const vector<vector<int>>& adj, vector<int>& result) {
    result.push_back(node);
    for (int child : adj[node]) {
        preorder(child, adj, result);
    }
}

// Hàm thực hiện duyệt cây theo thứ tự sau
void postorder(int node, const vector<vector<int>>& adj, vector<int>& result) {
    for (int child : adj[node]) {
        postorder(child, adj, result);
    }
    result.push_back(node);
}

// Hàm kiểm tra xem cây có phải là cây nhị phân hay không và thực hiện duyệt cây theo thứ tự giữa nếu có
void inorder(int node, const vector<vector<int>>& adj, vector<int>& result, bool& isBinary) {
    if (adj[node].size() > 2) {
        isBinary = false;
        return;
    }
    if (adj[node].size() >= 1) {
        inorder(adj[node][0], adj, result, isBinary);
    }
    result.push_back(node);
    if (adj[node].size() == 2) {
        inorder(adj[node][1], adj, result, isBinary);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        parent[v] = u;
    }

    // Tìm nút gốc của cây
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (parent[i] == 0) {
            root = i;
            break;
        }
    }

    // Tính chiều cao của cây
    cout << height(root, adj) << endl;

    // Duyệt cây theo thứ tự trước
    vector<int> preorderResult;
    preorder(root, adj, preorderResult);
    for (int node : preorderResult) {
        cout << node << " ";
    }
    cout << endl;

    // Duyệt cây theo thứ tự sau
    vector<int> postorderResult;
    postorder(root, adj, postorderResult);
    for (int node : postorderResult) {
        cout << node << " ";
    }
    cout << endl;

    // Kiểm tra xem cây có phải là cây nhị phân hay không và thực hiện duyệt cây theo thứ tự giữa nếu có
    bool isBinary = true;
    vector<int> inorderResult;
    inorder(root, adj, inorderResult, isBinary);

    if (isBinary) {
        for (int node : inorderResult) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }

    return 0;
}