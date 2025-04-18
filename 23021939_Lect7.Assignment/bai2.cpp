#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

const int MAX_M = 100; // Số lượng hàng tối đa của ma trận
const int MAX_N = 100; // Số lượng cột tối đa của ma trận

// Hàm Kadane: Tìm dãy con liên tiếp có tổng lớn nhất trong 1D array
// Trả về chỉ số bắt đầu, kết thúc, và tổng lớn nhất
void kadane(int arr[], int n, int& start, int& end, long long& max_sum) {
    long long curr_sum = 0;        // Tổng hiện tại khi duyệt mảng
    max_sum = LLONG_MIN;           // Khởi tạo tổng lớn nhất với giá trị nhỏ nhất có thể
    start = 0;
    end = -1;
    int curr_start = 0;            // Vị trí bắt đầu hiện tại

    for (int i = 0; i < n; ++i) {
        curr_sum += arr[i];

        if (curr_sum > max_sum) {  // Nếu tìm thấy tổng lớn hơn, cập nhật kết quả
            max_sum = curr_sum;
            start = curr_start;
            end = i;
        }

        if (curr_sum < 0) {        // Nếu tổng âm, reset lại đoạn con
            curr_sum = 0;
            curr_start = i + 1;
        }
    }
}

int main() {
    // Mở tệp đầu vào chứa ma trận
    ifstream inFile("matrix.txt");
    if (!inFile) {
        cerr << "Không thể mở tệp matrix.txt" << endl;
        return 1;
    }

    // Đọc kích thước ma trận từ tệp
    int m, n;
    inFile >> m >> n;

    // Đọc giá trị các phần tử của ma trận
    int matrix[MAX_M][MAX_N];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            inFile >> matrix[i][j];
        }
    }
    inFile.close(); // Đóng tệp sau khi đọc xong

    // Khởi tạo biến lưu kết quả tổng lớn nhất và tọa độ vùng con
    long long max_sum = LLONG_MIN;
    int final_r1, final_c1, final_r2, final_c2;

    int temp[MAX_N]; // Mảng tạm lưu tổng các cột giữa hai hàng

    // Duyệt tất cả các cặp hàng r1 và r2 để xét các hình chữ nhật con
    for (int r1 = 0; r1 < m; ++r1) {
        // Khởi tạo mảng tạm với giá trị 0
        for (int j = 0; j < n; ++j) {
            temp[j] = 0;
        }

        // Mở rộng hàng từ r1 xuống r2
        for (int r2 = r1; r2 < m; ++r2) {
            // Cộng các giá trị hàng r2 vào mảng tạm
            for (int j = 0; j < n; ++j) {
                temp[j] += matrix[r2][j];
            }

            // Áp dụng thuật toán Kadane trên mảng tạm để tìm dãy con liên tiếp lớn nhất theo cột
            int c1, c2;
            long long curr_sum;
            kadane(temp, n, c1, c2, curr_sum);

            // Cập nhật kết quả nếu tổng hiện tại lớn hơn tổng lớn nhất trước đó
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                final_r1 = r1 + 1; // Chuyển sang chỉ số từ 1 (dễ đọc)
                final_r2 = r2 + 1;
                final_c1 = c1 + 1;
                final_c2 = c2 + 1;
            }
        }
    }

    // Ghi kết quả ra tệp đầu ra
    ofstream outFile("matrix.out");
    if (!outFile) {
        cerr << "Không thể mở tệp matrix.out" << endl;
        return 1;
    }

    // Ghi tọa độ góc trên-trái và dưới-phải của vùng con, cùng tổng lớn nhất
    outFile << final_r1 << " " << final_c1 << " "
            << final_r2 << " " << final_c2 << " "
            << max_sum;
    outFile.close(); // Đóng tệp sau khi ghi

    return 0;
}
