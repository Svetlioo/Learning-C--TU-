#include <stdio.h>
int main() {
int length;
    printf("Enter length: ");
    scanf("%d", &length);
    for (int i = 0; i < length; i++){
        for(int x = 0; x < length; x++){
        int num = i+x+1;
        if(num>length) {
            num = 2*length-num;
        }
        printf("%d ", num);
        }
        printf("\n");
    }

    return 0;
}
