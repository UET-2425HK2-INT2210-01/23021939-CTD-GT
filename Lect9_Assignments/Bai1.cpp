#include <iostream>
using namespace std;

// Khai báo hàm partition trước để tránh lỗi biên dịch
int partition(double numbers[], int left, int right);

// Hàm QuickSort chính để sắp xếp mảng số thực
void quickSort(double numbers[], int left, int right) {
    // Nếu chỉ số left nhỏ hơn right, tiếp tục chia mảng
    if (left < right) {
        // Tìm vị trí phân hoạch (pivot)
        int pivotIndex = partition(numbers, left, right);
        
        // Đệ quy sắp xếp nửa bên trái của pivot
        quickSort(numbers, left, pivotIndex - 1);
        // Đệ quy sắp xếp nửa bên phải của pivot
        quickSort(numbers, pivotIndex + 1, right);
    }
}

// Hàm phân hoạch để chọn pivot và sắp xếp các phần tử
int partition(double numbers[], int left, int right) {
    // Chọn phần tử cuối cùng làm pivot
    double pivot = numbers[right];
    // Chỉ số của phần tử nhỏ hơn pivot
    int i = left - 1;
    
    // Duyệt qua các phần tử từ left đến right-1
    for (int j = left; j < right; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (numbers[j] <= pivot) {
            // Tăng chỉ số i và hoán đổi numbers[i] với numbers[j]
            i++;
            double temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }
    }
    
    // Đặt pivot vào vị trí đúng bằng cách hoán đổi numbers[i+1] với numbers[right]
    double temp = numbers[i + 1];
    numbers[i + 1] = numbers[right];
    numbers[right] = temp;
    
    // Trả về vị trí của pivot
    return i + 1;
}

int main() {
    int size;
    cin >> size;
    
    // Khởi tạo mảng để lưu size số thực
    double numbers[size];
    
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
    
    // Gọi hàm quickSort để sắp xếp mảng
    quickSort(numbers, 0, size - 1);
    
    // In ra danh sách đã sắp xếp
    for (int i = 0; i < size; i++) {
        cout << numbers[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    
    return 0;
}