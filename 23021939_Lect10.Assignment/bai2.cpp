#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Hàm tìm đường đi ngắn nhất từ đỉnh X đến đỉnh Y bằng BFS
int shortestPath(vector<vector<int>>& adj, int n, int X, int Y) {
    // Tạo mảng lưu khoảng cách từ đỉnh X đến các đỉnh khác
    // -1 nghĩa là chưa được thăm
    vector<int> distance(n + 1, -1);

    queue<int> q; // Hàng đợi để thực hiện BFS

    // Khởi tạo: khoảng cách từ X đến X là 0
    distance[X] = 0;
    q.push(X);

    // Bắt đầu duyệt đồ thị theo BFS
    while (!q.empty()) {
        int current = q.front(); // Lấy đỉnh đầu hàng đợi
        q.pop(); // Loại khỏi hàng đợi

        // Duyệt qua tất cả các đỉnh kề với current
        for (int neighbor : adj[current]) {
            // Nếu neighbor chưa được thăm
            if (distance[neighbor] == -1) {
                // Cập nhật khoảng cách của neighbor
                distance[neighbor] = distance[current] + 1;

                // Nếu tìm thấy đỉnh Y → trả về khoảng cách luôn
                if (neighbor == Y) {
                    return distance[neighbor];
                }

                // Nếu chưa đến Y → tiếp tục đưa vào hàng đợi
                q.push(neighbor);
            }
        }
    }

    // Nếu không tìm được đường từ X đến Y → trả về -1
    return -1;
}

int main() {
    int n, m, X, Y;
    // Nhập số đỉnh n, số cạnh m, và hai đỉnh X, Y
    cin >> n >> m >> X >> Y;

    // Khởi tạo danh sách kề (adjacency list)
    // Đồ thị có hướng nên chỉ thêm 1 chiều: từ x đến y
    vector<vector<int>> adj(n + 1); // Index từ 1 đến n

    // Đọc m cạnh và xây danh sách kề
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Đồ thị có hướng
    }

    // Gọi hàm tìm đường ngắn nhất từ X đến Y
    int result = shortestPath(adj, n, X, Y);

    // In ra kết quả: độ dài đường đi ngắn nhất, hoặc -1 nếu không có
    cout << result << endl;

    return 0;
}
