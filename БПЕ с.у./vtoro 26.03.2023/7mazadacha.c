#include <stdio.h> 

int main()
{
    int tochki;
    float bonusTochki;
    printf("Enter tochki: ");
    scanf("%d",&tochki);
    
    if(tochki <= 100)
    {
        bonusTochki +=5;
    }
    else if(tochki > 100 && tochki <=1000)
    {
        bonusTochki += (float)tochki / 5;
    }
    else if(tochki > 1000)
    {
        bonusTochki += (float)tochki / 10;
    }
    
    if(tochki % 2 == 0)
    {
        bonusTochki += 1;
    }
    else if(tochki % 10 == 5)
    {
        bonusTochki += 2;
    }
    
    printf("Bonus tochki = %.2f \n",bonusTochki);
    printf("Tochki  = %.2f",bonusTochki + tochki);
    

    return 0;
}