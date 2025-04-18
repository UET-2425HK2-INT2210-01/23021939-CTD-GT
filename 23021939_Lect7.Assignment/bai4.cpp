
#include <iostream>
#include <string>
using namespace std;


//Dùng thuật toán quay lui
void generateBinaryRecursive(string prefix, int n) {
    if (n == 0) {
        cout << prefix << endl;
        return;
    }
    generateBinaryRecursive(prefix + "0", n - 1);
    generateBinaryRecursive(prefix + "1", n - 1);
}

int main() {
    int n;
    cin >> n;
    generateBinaryRecursive("", n);
    return 0;
}
