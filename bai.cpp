
#include <iostream>
using namespace std;

// Tính tổng các số từ 1 đến n
int tinhTong(int n) {
    if (n == 1) return 1;
    return n + tinhTong(n - 1);
}

// Tính giai thừa của n (n!)
unsigned long long tinhGiaiThua(int n) {
    if (n == 0 || n == 1) return 1;
    return n * tinhGiaiThua(n - 1);
}

// Tính số Fibonacci thứ n
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Tính lũy thừa x^n
unsigned long long tinhLuyThua(int coSo, int soMu) {
    if (soMu == 0) return 1;
    return coSo * tinhLuyThua(coSo, soMu - 1);
}

// Đếm số chữ số của số nguyên dương n
int demSoChuSo(int n) {
    if (n < 10) return 1;
    return 1 + demSoChuSo(n / 10);
}

// Tính tổng các chữ số của số nguyên dương n
int tongCacChuSo(int n) {
    if (n < 10) return n;
    return (n % 10) + tongCacChuSo(n / 10);
}

// Đảo ngược số nguyên dương n
int daoNguocSo(int n, int soDao = 0) {
    if (n == 0)
        return soDao;
    return daoNguocSo(n / 10, soDao * 10 + n % 10);
}
