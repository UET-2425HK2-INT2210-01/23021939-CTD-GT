#include <iostream>

using namespace std;

const int MAX_NUMS = 1000;
int main() {
    // Mở file và đọc
    freopen("numbers.txt", "r", stdin);

    double numbers[MAX_NUMS];
    int count = 0;
    double num;
    while (cin >> num && count < MAX_NUMS) {
        numbers[count++] = num;
    }

    //Dùng Bubble sort
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                double temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }


    freopen("numbers.sorted", "w", stdout);


    for (int i = 0; i < count; ++i) {
        cout << numbers[i];
        if (i < count - 1) {
            cout << " ";
        }
    }

    return 0;
}
