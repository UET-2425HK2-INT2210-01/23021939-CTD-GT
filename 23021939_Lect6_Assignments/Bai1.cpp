#include <iostream>
using namespace std;

// Định nghĩa node của cây nhị phân tìm kiếm (BST)
struct Node {
    int data;     // Giá trị của node
    Node* left;   // Con trỏ trỏ đến node con bên trái
    Node* right;  // Con trỏ trỏ đến node con bên phải

    // Hàm khởi tạo một node mới với giá trị được truyền vào
    Node(int value) {
        data = value;
        left = right = nullptr; // Mặc định node mới chưa có con
    }
};

// Định nghĩa lớp BinaryTree để quản lý cây nhị phân tìm kiếm (BST)
class BinaryTree {
public:
    Node* root = nullptr; // Con trỏ gốc của cây, ban đầu là null

    // Hàm chèn một phần tử mới vào cây BST
    void insert(Node*& root, int value) {
        if (root == nullptr) { // Nếu cây rỗng, tạo node mới
            root = new Node(value);
            return;
        }
        if (value < root->data) insert(root->left, value);  // Chèn vào cây con bên trái nếu nhỏ hơn node hiện tại
        else if (value > root->data) insert(root->right, value); // Chèn vào cây con bên phải nếu lớn hơn node hiện tại
    }

    // Hàm tìm node có giá trị nhỏ nhất trong cây con bên phải (Successor)
    Node* findMin(Node* node) {
        while (node->left != nullptr) node = node->left; // Lặp đến node trái nhất (node nhỏ nhất)
        return node; // Trả về node nhỏ nhất tìm được
    }

    // Hàm xóa một phần tử khỏi cây BST
    void remove(Node*& root, int value) {
        if (root == nullptr) return; // Nếu cây rỗng, không cần xóa

        if (value < root->data) remove(root->left, value); // Nếu giá trị nhỏ hơn, tiếp tục tìm ở cây con bên trái
        else if (value > root->data) remove(root->right, value); // Nếu giá trị lớn hơn, tiếp tục tìm ở cây con bên phải
        else { // Tìm thấy node cần xóa
            if (root->left == nullptr) { // Trường hợp không có con trái
                Node* temp = root->right; // Lưu node con phải
                delete root; // Xóa node hiện tại
                root = temp; // Gán node con phải làm node mới
            } else if (root->right == nullptr) { // Trường hợp không có con phải
                Node* temp = root->left; // Lưu node con trái
                delete root; // Xóa node hiện tại
                root = temp; // Gán node con trái làm node mới
            } else { // Trường hợp có cả hai con
                Node* temp = findMin(root->right); // Tìm node nhỏ nhất bên phải
                root->data = temp->data; // Thay giá trị của node cần xóa bằng giá trị node nhỏ nhất bên phải
                remove(root->right, temp->data); // Xóa node nhỏ nhất bên phải
            }
        }
    }

    // Duyệt cây theo thứ tự trung tố (inorder) để in giá trị các node theo thứ tự tăng dần
    void inorder(Node* root) {
        if (root) {
            inorder(root->left); // Duyệt cây con bên trái trước
            cout << root->data << " "; // In giá trị node hiện tại
            inorder(root->right); // Duyệt cây con bên phải sau
        }
    }

    // Hàm hiển thị trạng thái cây BST sau mỗi thao tác
    void printTree(const string& message) {
        cout << message << ": ";
        inorder(root); // Gọi hàm inorder để in cây
        cout << endl;
    }
};

int main() {
    BinaryTree tree; // Khởi tạo một cây nhị phân tìm kiếm (BST)

    // Xây dựng cây BST từ danh sách ban đầu
    int initialValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int value : initialValues) tree.insert(tree.root, value);
    tree.printTree("Cây ban đầu");

    // Chèn các phần tử mới {14, 0, 35} vào BST
    int newValues[] = {14, 0, 35};
    for (int value : newValues) tree.insert(tree.root, value);
    tree.printTree("Cây sau khi chèn 14, 0, 35");

    // Xóa các phần tử {6, 13, 35} khỏi BST
    int toDelete[] = {6, 13, 35};
    for (int value : toDelete) tree.remove(tree.root, value);
    tree.printTree("Cây sau khi xóa 6, 13, 35");

    return 0;
}
