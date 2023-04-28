#include <stdio.h>
int main() {
int chislo;
printf("Enter number: ");
scanf("%d", &chislo);
switch(chislo){
    case 0:
    printf("nula");
    break;
    case 1:
    printf("edno");
    break;
    case 2:
    printf("dve");
    break;
    case 3:
    printf("tri");
    break;
    case 4:
    printf("chetiri");
    break;
    case 5:
    printf("pet");
    break;
    case 6:
    printf("shest");
    break;
    case 7:
    printf("sedem");
    break;
    case 8:
    printf("osem");
    break;
    case 9:
    printf("devet");
    break;
    default:
    printf("nqma takova");
}

  return 0;
}