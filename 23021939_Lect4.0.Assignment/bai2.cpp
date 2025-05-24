#include<iostream>
using namespace std;

// Định nghĩa cấu trúc Node cho danh sách liên kết đôi
struct Node {
    int data1;       // Dữ liệu chính (ví dụ: giá trị cần lưu trữ)
    int data2;       // Ưu tiên (priority)
    Node* next;      // Con trỏ tới node tiếp theo
    Node* prev;      // Con trỏ tới node trước đó

    // Constructor khởi tạo Node với giá trị x và độ ưu tiên p
    Node(int x, int p) {
        data1 = x;
        data2 = p;
        next = nullptr;
        prev = nullptr;
    }
};

// Lớp danh sách liên kết đôi biểu diễn hàng đợi ưu tiên
class doublyLinkedList {
public:
    Node* head = nullptr;  // Con trỏ đầu danh sách
    Node* tail = nullptr;  // Con trỏ cuối danh sách

    // Hàm in toàn bộ danh sách theo định dạng (x,p);(x,p)...
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->data1 << "," << temp->data2 << ")";
            temp = temp->next;
            if (temp != nullptr) {
                cout << ";";
            }
        }
        cout << endl;
    }

    // Thêm phần tử vào danh sách theo thứ tự ưu tiên giảm dần
    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);

        // TH1: Danh sách đang rỗng
        if (head == nullptr) {
            head = tail = newNode;

        // TH2: Độ ưu tiên lớn hơn đầu danh sách => chèn vào đầu
        } else if (p > head->data2) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;

        // TH3: Độ ưu tiên nhỏ hơn hoặc bằng đuôi => chèn vào cuối
        } else if (p <= tail->data2) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;

        // TH4: Chèn giữa danh sách sao cho danh sách luôn giảm dần theo độ ưu tiên
        } else {
            Node* temp = head;
            // Tìm vị trí mà p <= temp->next->data2
            while (temp->next && p <= temp->next->data2) {
                temp = temp->next;
            }

            // Chèn newNode vào giữa temp và temp->next
            newNode->next = temp->next;
            if (temp->next) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Xóa phần tử đầu danh sách (phần tử có độ ưu tiên cao nhất)
    void dequeue() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr; // Nếu danh sách rỗng sau khi xóa
            }
            delete temp; // Giải phóng bộ nhớ
        }
    }
};

// Hàm main
int main() {
    int n;
    cin >> n; // Nhập số lượng thao tác

    int x, p;
    doublyLinkedList myList; // Tạo hàng đợi ưu tiên
    string operat;

    for (int i = 0; i < n; i++) {
        cin >> operat;

        if (operat == "enqueue") {
            cin >> x >> p;
            myList.enqueue(x, p); // Thêm phần tử với độ ưu tiên
        } else if (operat == "dequeue") {
            myList.dequeue();     // Loại bỏ phần tử ưu tiên cao nhất
        } else {
            cout << " invalid";
        }
    }

    // In danh sách sau tất cả các thao tác
    myList.print();

    return 0;
}
