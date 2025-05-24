#include <iostream>
using namespace std;

// Định nghĩa cấu trúc 1 nút trong danh sách liên kết
struct Node {
    int data;           // Dữ liệu của nút
    Node* next;         // Con trỏ trỏ đến nút kế tiếp

    // Constructor khởi tạo Node với giá trị val
    Node(int val) : data(val), next(nullptr) {}
};

// Lớp danh sách liên kết đơn
class LinkedList {
private:
    Node* head;  // Con trỏ tới nút đầu tiên của danh sách
    Node* tail;  // Con trỏ tới nút cuối cùng

public:
    // Constructor khởi tạo danh sách rỗng
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Hàm thêm phần tử vào cuối danh sách
    void append(int x) {
        Node* newNode = new Node(x); // Tạo node mới
        if (head == nullptr) {       // Nếu danh sách rỗng
            head = tail = newNode;   // head và tail cùng trỏ đến node mới
        } else {
            tail->next = newNode;    // Nối node mới vào sau tail
            tail = newNode;          // Cập nhật tail
        }
        printList(); // In danh sách sau khi thêm
    }

    // Hàm tìm kiếm giá trị x trong danh sách
    void search(int x) {
        Node* current = head;
        int position = 1;  // Bắt đầu đếm từ vị trí 1
        bool found = false;

        while (current != nullptr) {
            if (current->data == x) {
                found = true;
                cout << position << endl; // In ra vị trí đầu tiên tìm thấy
                break;                    // Thoát khỏi vòng lặp
            }
            current = current->next;
            position++;
        }

        if (!found) {
            cout << "NO" << endl; // Không tìm thấy x
        }
    }

    // Hàm đảo ngược danh sách liên kết
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        tail = head; // Sau khi đảo, tail sẽ là head ban đầu

        while (current != nullptr) {
            next = current->next;     // Lưu node tiếp theo
            current->next = prev;     // Đảo chiều liên kết
            prev = current;           // Di chuyển prev lên
            current = next;           // Di chuyển current lên
        }
        head = prev; // Cập nhật head mới
    }

    // Hàm in toàn bộ danh sách
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor để giải phóng bộ nhớ
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Hàm main
int main() {
    LinkedList list;  // Tạo một danh sách liên kết rỗng
    int n;
    cin >> n;         // Nhập số lượng lệnh

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "append") {
            int x;
            cin >> x;
            list.append(x); // Thêm phần tử vào danh sách
        } else if (command == "search") {
            int x;
            cin >> x;
            list.search(x); // Tìm kiếm phần tử
        } else if (command == "reverse") {
            list.reverse(); // Đảo ngược danh sách
        }
    }

    return 0;
}
