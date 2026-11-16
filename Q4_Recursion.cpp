#include <iostream>
using namespace std;

long long sumN(int n) {
    if (n <= 0) return 0;
    return n + sumN(n - 1);
}

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// This version defines the first Fibonacci term as F(0) = 0.
long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacciTerms(int n) {
    for (int i = 0; i < n; ++i)
        cout << fibonacci(i) << " ";
    cout << '\n';
}

int main() {
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    if (n < 0) {
        cout << "Please enter a non-negative integer.\n";
        return 1;
    }
    cout << "Sum of first " << n << " natural numbers = " << sumN(n) << '\n';
    cout << "Factorial of " << n << " = " << factorial(n) << '\n';
    cout << "Fibonacci term F(" << n << ") = " << fibonacci(n) << '\n';
    cout << "First " << n << " Fibonacci terms: ";
    printFibonacciTerms(n);
    return 0;
}