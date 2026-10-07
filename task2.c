#include <stdio.h>

int main(void) {
    int n = 5;
    int factorial = 1;

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    printf("Task 2: factorial(%d) = %d\n", n, factorial);
    return 0;
}
