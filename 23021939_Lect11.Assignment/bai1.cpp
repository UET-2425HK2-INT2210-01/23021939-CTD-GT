#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const long long INF = 1e9; // Giá trị đại diện cho "vô cực" (không có đường đi)

// Cấu trúc lưu thông tin một cạnh của đồ thị
struct Edge {
    int u, v, d; // Cạnh từ u đến v có độ bẩn d
};

// Hàm Bellman-Ford: tìm đường đi ngắn nhất từ s đến e
void bellmanFord(int n, int s, int e, const vector<Edge>& edges, long long& totalDirty, vector<int>& path) {
    vector<long long> dist(n + 1, INF); // Mảng lưu khoảng cách từ s đến các đỉnh
    vector<int> pred(n + 1, -1);        // Mảng lưu đỉnh trước đó để truy vết đường đi
    dist[s] = 0; // Khoảng cách từ s đến chính nó là 0

    // Lặp n-1 lần để cập nhật khoảng cách
    for (int i = 1; i <= n - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.u, v = edge.v, d = edge.d;
            // Nếu có thể cải thiện khoảng cách tới v thông qua u
            if (dist[u] != INF && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                pred[v] = u; // Lưu lại đường đi
            }
        }
    }

    // Nếu không có đường từ s đến e
    if (dist[e] == INF) {
        totalDirty = INF;
        return;
    }

    totalDirty = dist[e]; // Tổng độ bẩn nhỏ nhất

    // Truy vết lại đường đi từ e về s
    path.clear();
    for (int v = e; v != -1; v = pred[v])
        path.push_back(v);

    reverse(path.begin(), path.end()); // Đảo ngược để được đường đi từ s → e
}

// Hàm Floyd-Warshall: tìm đường đi ngắn nhất giữa mọi cặp đỉnh
void floydWarshall(int n, vector<vector<long long>>& dist, const vector<Edge>& edges) {
    // Khởi tạo ma trận khoảng cách
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = (i == j ? 0 : INF); // 0 nếu cùng đỉnh, INF nếu chưa biết

    // Cập nhật từ danh sách cạnh ban đầu
    for (const auto& edge : edges)
        dist[edge.u][edge.v] = min(dist[edge.u][edge.v], (long long)edge.d);

    // Thuật toán Floyd-Warshall 3 vòng lặp
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    ifstream in("dirty.txt"); // Mở file đầu vào
    int n, m, s, e;
    in >> n >> m >> s >> e; // Đọc số đỉnh, số cạnh, điểm bắt đầu và kết thúc

    vector<Edge> edges(m); // Danh sách các cạnh
    for (int i = 0; i < m; ++i)
        in >> edges[i].u >> edges[i].v >> edges[i].d; // Đọc thông tin từng cạnh
    in.close(); // Đóng file

    long long totalDirty;   // Tổng độ bẩn từ s → e
    vector<int> path;       // Đường đi từ s → e
    bellmanFord(n, s, e, edges, totalDirty, path); // Gọi thuật toán Bellman-Ford

    // Khởi tạo ma trận khoảng cách và gọi Floyd-Warshall
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1));
    floydWarshall(n, dist, edges);

    ofstream out("dirty.out"); // Mở file để ghi kết quả

    // Ghi độ bẩn và đường đi từ s đến e
    if (totalDirty == INF) {
        out << "INF\n";
    } else {
        out << totalDirty << "\n";
        for (size_t i = 0; i < path.size(); ++i) {
            out << path[i];
            if (i + 1 < path.size()) out << " ";
        }
        out << "\n";
    }

    // Ghi ma trận khoảng cách ngắn nhất giữa mọi cặp đỉnh
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF) out << "INF"; // Không có đường đi
            else out << dist[i][j];
            if (j < n) out << " ";
        }
        out << "\n";
    }

    out.close(); // Đóng file kết quả
    return 0;
}
