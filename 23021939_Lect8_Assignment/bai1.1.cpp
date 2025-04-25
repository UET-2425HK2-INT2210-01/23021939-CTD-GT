#include <iostream>
using namespace std;

void swap_doubles(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch mảng xung quanh một pivot
// arr[]: Mảng cần phân chia
// low: Chỉ số bắt đầu của mảng con cần phân chia
// high: Chỉ số kết thúc của mảng con cần phân chia
// Trả về vị trí của pivot sau khi mảng đã được phân chia
int partition(double arr[], int low, int high) {
    // Chọn phần tử cuối cùng làm pivot
    double pivot = arr[high];
    // Chỉ số của phần tử nhỏ hơn pivot
    int i = (low - 1);
    // Duyệt qua các phần tử từ low đến high-1
    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++;
        // Tăng chỉ số của phần tử nhỏ hơn hoặc bằng pivot
            swap_doubles(arr[i], arr[j]);
        // Hoán đổi arr[i] và arr[j]
        }
    }
    // Đưa pivot về đúng vị trí của nó trong mảng đã sắp xếp
    swap_doubles(arr[i + 1], arr[high]);
    return (i + 1);
    // Đây là vị trí chia mảng thành hai phần
}

// Hàm thực hiện thuật toán Quick Sort
// arr[]: Mảng cần sắp xếp
// low: Chỉ số bắt đầu
// high: Chỉ số kết thúc
void quickSort(double arr[], int low, int high) {
    // Điều kiện dừng đệ quy: khi mảng con có ít nhất 2 phần tử
    if (low < high) {
      //trả về chỉ số của pivot sau khi phân chia mảng.
        int pi = partition(arr, low, high);

        // Đệ quy sắp xếp phần mảng trước pivot
        quickSort(arr, low, pi - 1);
        // Đệ quy sắp xếp phần mảng sau pivot
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    if (n <= 0) {
        return 0;
    }

    // Khởi tạo mảng C-style để lưu trữ các số thực
    double numbers[n];

    // Đọc n số thực từ input vào mảng
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // Gọi hàm quickSort để sắp xếp mảng
    quickSort(numbers, 0, n - 1);

    // In ra mảng đã sắp xếp
    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << (i == n - 1 ? "" : " ");
        //Nếu đúng (i == n - 1), thì không in ra dấu cách
    }
    cout << endl;

    return 0;
}
