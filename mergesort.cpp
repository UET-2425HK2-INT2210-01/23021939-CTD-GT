#include <iostream>
using namespace std;

const int MAX = 100000;
int temp[MAX];  // Mảng phụ dùng để lưu khi gộp

// Gộp 2 đoạn [left..mid] và [mid+1..right] trong mảng arr
void merge(int arr[], int left, int mid, int right) {
    int i = left;      // con trỏ đoạn trái
    int j = mid + 1;   // con trỏ đoạn phải
    int k = left;      // vị trí hiện tại trong temp

    // So sánh và gộp từng phần tử vào temp
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Gộp phần còn lại của đoạn trái (nếu có)
    while (i <= mid)
        temp[k++] = arr[i++];

    // Gộp phần còn lại của đoạn phải (nếu có)
    while (j <= right)
        temp[k++] = arr[j++];

    // Sao chép từ temp về lại mảng chính
    for (int i = left; i <= right; ++i)
        arr[i] = temp[i];
}

// Merge Sort không đệ quy (bottom-up)
void mergeSort(int arr[], int n) {
    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[MAX];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    mergeSort(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
