#include <iostream>
using namespace std;

// Quay lui để sinh tất cả các hoán vị của dãy từ 1 đến n

const int MAX_N = 10;  // Giới hạn tối đa cho n
int perm[MAX_N];       // Mảng lưu trữ hoán vị hiện tại
bool used[MAX_N];      // Mảng đánh dấu các số đã được sử dụng

// Hàm hiển thị một hoán vị
void print_permutation(int n) {
    for (int i = 0; i < n; ++i) {
        cout << perm[i];
        // Nếu muốn cách nhau bằng dấu cách, có thể bật dòng dưới:
        // if (i < n - 1) cout << " ";
    }
    cout << endl; // Xuống dòng sau khi in xong một hoán vị
}

// Hàm đệ quy sinh các hoán vị
void generate_permutations(int pos, int n) {
    // Nếu đã điền đủ n vị trí, in ra hoán vị hiện tại
    if (pos == n) {
        print_permutation(n);
        return;
    }

    // Thử tất cả các giá trị từ 1 đến n
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {                 // Nếu i chưa được sử dụng
            used[i] = true;             // Đánh dấu i là đã dùng
            perm[pos] = i;              // Gán i vào vị trí hiện tại
            generate_permutations(pos + 1, n); // Gọi đệ quy cho vị trí tiếp theo
            used[i] = false;            // Quay lui: bỏ đánh dấu i để thử giá trị khác
        }
    }
}

int main() {
    int n;
    cin >> n;

    // Kiểm tra điều kiện đầu vào
    if (n > MAX_N || n < 1) {
        cout << "n phải nằm trong khoảng từ 1 đến " << MAX_N << endl;
        return 1;
    }

    generate_permutations(0, n); // Bắt đầu sinh hoán vị từ vị trí đầu tiên
    return 0;
}
