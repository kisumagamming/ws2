#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm tính tổng các chữ số của một số
int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Hàm kiểm tra hợp số
bool isComposite(int n) {
    if (n < 4) return false; // 0, 1, 2, 3 không phải hợp số
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return true;
    }
    return false;
}

// Hàm tìm số nguyên tố nhỏ nhất lớn hơn N mà tổng chữ số là hợp số
int findPrimeWithCompositeDigitSum(int N) {
    int x = N + 1;
    while (true) {
        if (isPrime(x)) {
            int digitSum = sumOfDigits(x);
            if (isComposite(digitSum)) {
                return x;
            }
        }
        x++;
    }
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        int N;
        cin >> N;
        cout << findPrimeWithCompositeDigitSum(N) << endl;
    }
    return 0;
}
