#include <stdio.h>

int main() {
int n = 6;
int masiv[n];
int* pointer = &masiv;
for (int i = 0; i < n; i++){
    masiv[i] = (i+1) * 10;
    printf("%d\n", masiv[i]);
}

printf("Size of masiv = %ld\n", sizeof(masiv));
printf("Size of pointer = %ld", sizeof(*pointer));


return 0;

}