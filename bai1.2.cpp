#include <iostream>
#include <vector>
using namespace std;

// Hàm phân hoạch theo phương pháp Hoare Partition
int hoarePartition(vector<float> &arr, int low, int high) {
    float pivot = arr[low];       // Chọn phần tử đầu tiên làm pivot
    int i = low - 1;              // i bắt đầu từ ngoài vùng [low..high]
    int j = high + 1;             // j cũng bắt đầu từ ngoài vùng

    while (true) {
        // Tăng i đến khi gặp phần tử >= pivot
        do {
            ++i;
        } while (arr[i] < pivot);

        // Giảm j đến khi gặp phần tử <= pivot
        do {
            --j;
        } while (arr[j] > pivot);

        // Nếu i >= j thì trả về vị trí phân hoạch
        if (i >= j)
            return j;

        // Nếu i < j, hoán đổi 2 phần tử arr[i] và arr[j]
        swap(arr[i], arr[j]);
    }
}

// Hàm sắp xếp nhanh (QuickSort) dùng Hoare partition
void quickSortHoare(vector<float> &arr, int low, int high) {
    if (low < high) {
        // Phân hoạch mảng và nhận vị trí j
        int pi = hoarePartition(arr, low, high);

        // Đệ quy sắp xếp 2 phần: từ low đến pi, và từ pi + 1 đến high
        quickSortHoare(arr, low, pi);       // Lưu ý: không dùng pi - 1 ở đây!
        quickSortHoare(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;                      // Nhập số lượng phần tử
    vector<float> arr(n);         // Mảng kiểu float

    // Nhập từng phần tử
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    // Gọi hàm sắp xếp QuickSort-Hoare
    quickSortHoare(arr, 0, n - 1);

    // In mảng sau khi sắp xếp
    for (float x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
