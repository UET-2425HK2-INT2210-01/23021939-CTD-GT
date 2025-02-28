#include <bits/stdc++.h> 
using namespace std;
int GCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << "Uoc chung lon nhat cua a va b la: " << GCD(a, b) << endl;
    return 0; 
} 
