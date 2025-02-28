#include <bits/stdc++.h> 
using namespace std;
int main() {
    int n = 5;
    double arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    double max = arr[0];
    double min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    double sum = min + max;
    cout << sum << endl;
    return 0;
}
