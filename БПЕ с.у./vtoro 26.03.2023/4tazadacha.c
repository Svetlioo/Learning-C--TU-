#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int num, largest = 0, smallest = 0;
    printf("Enter a series of numbers (0 to stop):\n");
    do {
        printf("Enter number: ");
        scanf("%d", &num);
        largest = max(largest, num);
        smallest = smallest == 0 ? num : min(smallest, num);
    } while (num != 0);
    printf("The largest number is %d.\n", largest);
    printf("The smallest number is %d.\n", smallest);
    return 0;
}
