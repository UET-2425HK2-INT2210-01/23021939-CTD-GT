#include <iostream>
using namespace std;

// Hàm quay lui để kiểm tra xem có tập hợp con nào có tổng bằng target hay không
bool findSubsetSum(int ages[], int n, int target, int index, int currentSum) {
    // Nếu tổng hiện tại bằng target, trả về true
    if (currentSum == target) {
        return true;
    }
    
    // Nếu đã duyệt hết mảng hoặc tổng hiện tại vượt quá target, trả về false
    if (index >= n || currentSum > target) {
        return false;
    }
    
    // Có hai lựa chọn: bao gồm hoặc không bao gồm ages[index]
    
    // Lựa chọn 1: Bao gồm ages[index] vào tổng
    if (findSubsetSum(ages, n, target, index + 1, currentSum + ages[index])) {
        return true;
    }
    
    // Lựa chọn 2: Không bao gồm ages[index]
    if (findSubsetSum(ages, n, target, index + 1, currentSum)) {
        return true;
    }
    
    // Nếu không tìm thấy tập hợp con nào thỏa mãn, trả về false
    return false;
}

int main() {
    int n, target;
    
    cin >> n >> target;
    
    int ages[n];
    
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }
    
    // Gọi hàm findSubsetSum để kiểm tra
    bool result = findSubsetSum(ages, n, target, 0, 0);
    if (result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}