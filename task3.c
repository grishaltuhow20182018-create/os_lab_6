#include <stdio.h>

int main(void) {
    int numbers[] = {3, 1, 4, 1, 5};
    int size = (int)(sizeof(numbers) / sizeof(numbers[0]));
    int max = numbers[0];

    for (int i = 1; i < size; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    printf("Task 3: max value = %d\n", max);
    return 0;
}
