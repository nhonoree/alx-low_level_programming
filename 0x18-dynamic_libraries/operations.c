#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    if (b == 0) {
        return 0;  // Handle division by zero
    }
    // Adjust for negative division behavior
    int result = a / b;
    if (a % b != 0 && (a < 0) != (b < 0)) {
        result--;
    }
    return result;
}

int mod(int a, int b) {
    if (b == 0) {
        return 0;  // Handle division by zero
    }
    return a % b;
}
