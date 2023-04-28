#include <stdio.h> 
int main(){
    float v, debit1, debit2, n, obshta;

    printf("Baseina obem: ");
    scanf("%f", &v);

    printf("Purva truba: ");
    scanf("%f", &debit1);

    printf("Vtora truba: ");
    scanf("%f", &debit2);

    printf("Vreme: ");
    scanf("%f", &n);

    obshta = (debit1 + debit2) * n;


    if (obshta > v)
    {
        printf("Baseina e prepulnen\n");
    }
    else
    {
        printf("Baseina e pulen %.2f litra.\n", obshta);
    }

    return 0;
}

