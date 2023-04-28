#include <stdio.h>

int main() {
    int hour, minute;
    printf("Enter the hour: ");
    scanf("%d", &hour);
    printf("Enter the minute: ");
    scanf("%d", &minute);
    minute += 15;
    if (minute >= 60) {
        hour += 1;
        minute -= 60;
    }
    if (hour >= 24) {
        hour -= 24;
    }
    printf("Time in 15 minutes: %02d:%02d\n", hour, minute);
    return 0;
}
