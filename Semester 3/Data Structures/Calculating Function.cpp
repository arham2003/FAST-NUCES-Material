#include <iostream>

int main() {
    int n;
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    int result = 0;
    int sign = 1; // Start with a positive sign

    for (int i = 1; i <= n; i++) {
        result += sign * i;
        sign = -sign; // Toggle the sign for the next iteration
    }

    std::cout << "f(" << n << ") = " << sign * result << std::endl;

    return 0;
}

