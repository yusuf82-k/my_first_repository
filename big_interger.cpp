#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to add two massive numbers passed as strings
std::string addStrings(const std::string& num1, const std::string& num2) {
    std::string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;

    // Schoolbook addition from right to left
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        
        carry = sum / 10;
        result += std::to_string(sum % 10);
    }

    // The result is backwards, so we reverse it
    std::reverse(result.begin(), result.end());
    return result;
}

std::string get1000thFibonacci() {
    // Base cases represented as strings
    std::string a = "0"; // F(0)
    std::string b = "1"; // F(1)

    // Iterating up to the 1000th element
    // Loop runs 999 times to find F(999) if F(0) is the 1st element
    for (int i = 0; i < 999; ++i) {
        std::string next = addStrings(a, b);
        a = b;
        b = next;
    }

    return a;
}

int main() {
    std::cout << "The 1000th Fibonacci number is:\n" << get1000thFibonacci() << std::endl;
    return 0;
}