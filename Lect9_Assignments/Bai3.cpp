#include <iostream>
using namespace std;

// Hàm tìm tổng giá trị lớn nhất có thể với giới hạn trọng lượng
int knapsack(int n, int maxWeight, int weights[], int values[]) {
    // Tạo mảng dp để lưu trữ giá trị tối ưu
    // dp[i][w] là giá trị lớn nhất có thể với i vật đầu tiên và trọng lượng tối đa w
    int dp[n + 1][maxWeight + 1];
    
    // Khởi tạo mảng dp
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            // Nếu không có vật nào hoặc trọng lượng tối đa là 0, giá trị là 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            // Với mỗi vật i và trọng lượng w
            else {
                // Không chọn vật i
                dp[i][w] = dp[i - 1][w];
                // Nếu có thể chọn vật i (trọng lượng của nó không vượt quá w)
                if (weights[i - 1] <= w) {
                    // So sánh giữa không chọn và chọn vật i
                    int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                    if (include > dp[i][w]) {
                        dp[i][w] = include;
                    }
                }
            }
        }
    }
    
    // Trả về giá trị lớn nhất có thể với n vật và trọng lượng tối đa maxWeight
    return dp[n][maxWeight];
}

int main() {
    int n, maxWeight;
        cin >> n >> maxWeight;
 
    int weights[n], values[n];

    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    
    // Gọi hàm knapsack để tính tổng giá trị lớn nhất
    int result = knapsack(n, maxWeight, weights, values);
    cout << result << endl;
    
    return 0;
}