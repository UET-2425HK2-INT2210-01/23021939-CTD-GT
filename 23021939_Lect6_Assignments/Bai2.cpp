#include <iostream>
using namespace std;

class MinHeap {
public:
    int* arr;  // Mảng lưu trữ các phần tử của heap
    int n;  // Số lượng phần tử hiện tại trong heap

    MinHeap() {
        n = 0;
        arr = new int[1000];  // Khởi tạo mảng có kích thước tối đa
    }

    // Hàm đẩy phần tử lên để đảm bảo tính chất của heap
    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;  // Chỉ số của node cha
            if (arr[idx] < arr[parent]) {  // Nếu con nhỏ hơn cha
                swap(arr[idx], arr[parent]);  // Đổi chỗ
                idx = parent;  // Tiếp tục kiểm tra cha
            } else {
                break;  // Dừng lại nếu không cần hoán đổi
            }
        }
    }

    // Hàm đẩy phần tử xuống để đảm bảo tính chất của heap
    void heapifyDown(int idx) {
        while (true) {
            int left = 2 * idx + 1;  // Con trái
            int right = 2 * idx + 2;  // Con phải
            int smallest = idx;  // Giả sử node hiện tại nhỏ nhất

            // Kiểm tra xem có cần hoán đổi với con trái không
            if (left < n && arr[left] < arr[smallest]) {
                smallest = left;
            }
            // Kiểm tra xem có cần hoán đổi với con phải không
            if (right < n && arr[right] < arr[smallest]) {
                smallest = right;
            }

            if (smallest != idx) {  // Nếu có sự thay đổi
                swap(arr[idx], arr[smallest]);  // Hoán đổi
                idx = smallest;  // Kiểm tra tiếp từ vị trí mới
            } else {
                break;  // Nếu không có gì để đổi, dừng lại
            }
        }
    }

    // Hàm thêm một phần tử vào heap
    void insert(int val) {
        arr[n] = val;  // Đặt giá trị mới vào cuối mảng
        heapifyUp(n);  // Điều chỉnh heap
        n++;  // Tăng kích thước heap
    }

    // Hàm lấy phần tử nhỏ nhất
    int getMin() {
        if (n == 0) return -1;  // Nếu heap rỗng, trả về -1
        return arr[0];  // Phần tử nhỏ nhất luôn ở index 0
    }

    // Hàm xóa phần tử nhỏ nhất (extractMin)
    void extractMin() {
        if (n == 0) return;  // Nếu heap rỗng, không làm gì cả

        arr[0] = arr[n - 1];  // Đưa phần tử cuối lên đầu
        n--;  // Giảm kích thước heap
        heapifyDown(0);  // Điều chỉnh lại heap
    }

    // Hàm xóa một phần tử bất kỳ
    void remove(int val) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == val) {
                idx = i;
                break;
            }
        }

        if (idx == -1) return;  // Nếu không tìm thấy giá trị cần xóa

        arr[idx] = arr[n - 1];  // Thay thế phần tử cần xóa bằng phần tử cuối
        n--;  // Giảm kích thước heap
        heapifyDown(idx);  // Điều chỉnh lại heap
        heapifyUp(idx);  // Cũng có thể cần đẩy lên nếu phần tử mới nhỏ hơn cha
    }

    // Hàm in các phần tử trong heap
    void printHeap() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;

    // Thêm các phần tử vào heap
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20, 14, 0, 35};
    for (int value : values) heap.insert(value);

    cout << "Heap sau khi chèn các phần tử: ";
    heap.printHeap();

    // Xóa các phần tử khỏi heap
    int toDelete[] = {6, 13, 35};
    for (int value : toDelete) heap.remove(value);

    cout << "Heap sau khi xóa 6, 13, 35: ";
    heap.printHeap();

    return 0;
}