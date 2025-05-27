#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

// Hàm DFS để duyệt đồ thị và tạo thứ tự topo
void dfsTraversal(const vector<vector<int>> &graph, vector<bool> &visited, int node, stack<int> &sortedOrder) {
    visited[node] = true;  // Đánh dấu đỉnh hiện tại đã được thăm

    // Duyệt tất cả các đỉnh kề của đỉnh hiện tại
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsTraversal(graph, visited, neighbor, sortedOrder);  // Đệ quy thăm đỉnh kề
        }
    }

    // Sau khi đã duyệt hết các đỉnh kề, đẩy đỉnh hiện tại vào stack
    sortedOrder.push(node);
}

// Hàm thực hiện sắp xếp topo bằng DFS
void performTopoSort(const vector<vector<int>> &graph, int numNodes, stack<int> &sortedOrder) {
    vector<bool> visited(numNodes + 1, false);  // Mảng đánh dấu đỉnh đã thăm, khởi tạo tất cả là false

    // Duyệt qua tất cả các đỉnh của đồ thị
    for (int vertex = 1; vertex <= numNodes; vertex++) {
        if (!visited[vertex]) {
            dfsTraversal(graph, visited, vertex, sortedOrder);  // Nếu chưa thăm, thực hiện DFS từ đỉnh đó
        }
    }
}

int main() {
    ifstream inputFile("jobs.txt");   // Mở file input để đọc đồ thị (dạng danh sách cạnh)
    ofstream outputFile("jobs-out.txt");  // Mở file output để ghi kết quả

    int numNodes, numEdges;
    inputFile >> numNodes >> numEdges;  // Đọc số đỉnh và số cạnh từ file

    // Khởi tạo danh sách kề, chỉ số từ 1 đến numNodes
    vector<vector<int>> adjacencyList(numNodes + 1);

    // Đọc danh sách cạnh và xây dựng danh sách kề
    for (int i = 1; i <= numEdges; i++) {
        int fromNode, toNode;
        inputFile >> fromNode >> toNode;  // Đọc cạnh từ fromNode đến toNode
        adjacencyList[fromNode].push_back(toNode);  // Thêm toNode vào danh sách kề của fromNode
    }

    stack<int> sortedOrder;  // Stack lưu kết quả sắp xếp topo
    performTopoSort(adjacencyList, numNodes, sortedOrder);  // Thực hiện sắp xếp topo

    // Ghi kết quả từ stack ra file output theo thứ tự topo
    while (!sortedOrder.empty()) {
        outputFile << sortedOrder.top() << ' ';  // Ghi đỉnh vào file
        sortedOrder.pop();  // Xóa đỉnh khỏi stack
    }

    return 0;  // Kết thúc chương trình
}
