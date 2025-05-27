#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// Cấu trúc dữ liệu biểu diễn một cạnh trong đồ thị
struct Edge {
    int from, to, weight;

    // Toán tử so sánh để sắp xếp cạnh theo trọng số tăng dần (áp dụng cho Kruskal)
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Cấu trúc dữ liệu dùng trong Disjoint Set Union (DSU)
vector<int> parent;       // Mảng lưu cha đại diện của mỗi tập hợp
vector<int> rank_level;   // Mảng lưu cấp bậc của từng tập hợp (để tối ưu hóa việc hợp nhất)

// Hàm tìm tập hợp đại diện của một đỉnh (có áp dụng path compression)
int findRepresentative(int node) {
    if (parent[node] != node)
        parent[node] = findRepresentative(parent[node]);  // Nén đường đi để tối ưu
    return parent[node];
}

// Hàm hợp nhất hai tập hợp nếu chúng thuộc các cây khác nhau
bool unionSets(int nodeA, int nodeB) {
    int rootA = findRepresentative(nodeA);
    int rootB = findRepresentative(nodeB);

    if (rootA == rootB) return false;  // Nếu hai đỉnh đã thuộc cùng một tập hợp, bỏ qua

    // Hợp nhất theo cấp bậc (giúp giữ cây phẳng)
    if (rank_level[rootA] < rank_level[rootB]) {
        parent[rootA] = rootB;
    } else if (rank_level[rootA] > rank_level[rootB]) {
        parent[rootB] = rootA;
    } else {
        parent[rootB] = rootA;
        rank_level[rootA]++;
    }
    return true;
}

int main() {
    ifstream inputFile("connection.txt");   // Mở file chứa dữ liệu đồ thị
    ofstream outputFile("connection-out.txt");  // Mở file để ghi kết quả

    // Kiểm tra xem file có mở thành công không
    if (!inputFile) {
        cerr << "Không thể mở file đầu vào!\n";
        return 1;
    }
    if (!outputFile) {
        cerr << "Không thể mở file đầu ra!\n";
        return 1;
    }

    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;  // Đọc số đỉnh và số cạnh từ file

    // Đọc danh sách cạnh từ file
    vector<Edge> edgeList(numEdges);
    for (int i = 0; i < numEdges; ++i) {
        inputFile >> edgeList[i].from >> edgeList[i].to >> edgeList[i].weight;
    }

    sort(edgeList.begin(), edgeList.end());  // Sắp xếp các cạnh theo trọng số tăng dần

    // Khởi tạo DSU (mỗi đỉnh là đại diện của chính nó)
    parent.resize(numVertices + 1);
    rank_level.resize(numVertices + 1, 0);
    for (int i = 1; i <= numVertices; ++i) {
        parent[i] = i;
    }

    int totalWeight = 0;             // Tổng trọng số của cây khung nhỏ nhất (MST)
    vector<Edge> mstEdges;           // Danh sách các cạnh thuộc cây khung nhỏ nhất

    // Duyệt qua từng cạnh đã sắp xếp theo thuật toán Kruskal
    for (Edge& edge : edgeList) {
        if (unionSets(edge.from, edge.to)) {  // Nếu hợp nhất được hai tập hợp
            totalWeight += edge.weight;       // Cộng trọng số vào tổng chi phí
            mstEdges.push_back(edge);         // Thêm cạnh vào danh sách MST
        }
    }

    // Ghi kết quả ra file
    outputFile << totalWeight << '\n';   // Ghi tổng trọng số của cây khung nhỏ nhất
    for (const Edge& edge : mstEdges) {
        outputFile << edge.from << ' ' << edge.to << ' ' << edge.weight << '\n';
    }

    return 0;   // Kết thúc chương trình
}
