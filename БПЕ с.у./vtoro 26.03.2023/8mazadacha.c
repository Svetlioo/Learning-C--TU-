#include <stdio.h>

int main() {

    int n;
    char periodDenIliNosht;
    float taxiCena = 0;
    float avtobusCena = 0;
    float vlakCena = 0;
    printf("n = ");
    scanf("%d",&n);
    printf("periodDenIliNosht= ");
    scanf("%c",&periodDenIliNosht);
    
    if(periodDenIliNosht == 'D')
    {
        taxiCena = 0.70 + n * 0.79;
    }
    else if(periodDenIliNosht == 'N')
    {
        taxiCena = 0.70 + n * 0.90;
    }
    
    if(n >= 20){
        avtobusCena = n * 0.09;
    }
    
    if(n >= 100){
        vlakCena = n * 0.06;
    }
    
    
    if(vlakCena > 0)
    {
        printf("Vlak cena = %f",vlakCena);
    }
    else if(avtobusCena >0)
    {
        printf("Avtobus cena = %f",avtobusCena);
    }
    else
    {
        printf("Taxi cena = %f",taxiCena);
    }
    return 0;
}