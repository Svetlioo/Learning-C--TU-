#include <stdio.h>

int main() {
int n = 10;
int masiv[n];
int y = 0;
for (int i = 0; i < n; i++){
    masiv[i] = y+=11;
    printf("%d\n", masiv[i]);

}
printf("\n\n\n");
for (int i = 0; i < n; i++){
    masiv[i] = i+11;
    printf("%d\n", masiv[i]);

}
    return 0;
}