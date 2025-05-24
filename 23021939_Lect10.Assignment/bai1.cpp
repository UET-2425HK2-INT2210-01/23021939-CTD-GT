#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Hàm BFS (Breadth-First Search) để duyệt qua các nút trong thành phần liên thông
// start: đỉnh bắt đầu duyệt
// adj: danh sách kề của đồ thị
// visited: mảng đánh dấu đỉnh đã được thăm
void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;            // Hàng đợi để lưu các đỉnh sẽ duyệt
    q.push(start);           // Thêm đỉnh bắt đầu vào hàng đợi
    visited[start] = true;   // Đánh dấu đỉnh bắt đầu là đã thăm

    // Lặp cho đến khi hàng đợi rỗng
    while (!q.empty()) {
        int current = q.front(); // Lấy đỉnh đầu hàng đợi
        q.pop();                 // Xóa đỉnh đầu khỏi hàng đợi

        // Duyệt qua tất cả các đỉnh kề với current
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {         // Nếu đỉnh kề chưa được thăm
                visited[neighbor] = true;     // Đánh dấu đã thăm
                q.push(neighbor);             // Thêm vào hàng đợi để duyệt tiếp
            }
        }
    }
}

int main() {
    int n, m; // n: số đỉnh, m: số cạnh
    cin >> n >> m;

    // Tạo danh sách kề với n+1 phần tử (vì đỉnh đánh số từ 1 đến n)
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false); // Mảng đánh dấu các đỉnh đã được thăm

    // Nhập m cạnh của đồ thị
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Thêm y vào danh sách kề của x
        adj[y].push_back(x); // Thêm x vào danh sách kề của y (vì đồ thị vô hướng)
    }

    int components = 0; // Biến đếm số thành phần liên thông

    // Duyệt qua từng đỉnh từ 1 đến n
    for (int i = 1; i <= n; ++i) {
        // Nếu đỉnh chưa được thăm → bắt đầu BFS từ đó → là thành phần mới
        if (!visited[i]) {
            bfs(i, adj, visited); // Duyệt toàn bộ thành phần liên thông từ đỉnh i
            components++;         // Mỗi lần gọi BFS mới là 1 thành phần liên thông
        }
    }

    // In ra số thành phần liên thông
    cout << components << endl;

    return 0;
}
