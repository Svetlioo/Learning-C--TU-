#include <stdio.h>
int main() {

int masiv[5];
for(int i = 0; i < 5; i++) {
    printf("Enter chislo: ");
    scanf("%d", &masiv[i]);
}


for (int i = 2; i < 5; i += 2) {
    if (masiv[i] < masiv[i - 1] && masiv[i-1] > masiv[i - 2]) {
}
    else {
        printf("False");
        return 0;
    }
}
    printf("True");
    return 0;
}
 