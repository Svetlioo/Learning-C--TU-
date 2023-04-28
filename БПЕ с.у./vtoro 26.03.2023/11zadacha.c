#include <stdio.h>

int main()
{
    int p1,p2,p3,p4,p5;
    
    int n;
    printf("N = ");
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++){
        int num;
        printf("Enter num: ");
        scanf("%d",&num);
        
        if(num>=1 && num <200)
        {
            p1++;
        }
        else if(num >= 200 && num < 400)
        {
            p2++;
        }
        else if(num>=400 && num<600)
        {
            p3++;
        }
        else if(num>=600 && num<800)
        {
            p4++;
        }
        else if(num>=800 )
        {
            p5++;
        }
    }
    printf("P1 = %.2f \n",(float)p1/n*100);
    printf("P2 = %.2f \n",(float)p2/n*100);
    printf("P3 = %.2f \n",(float)p3/n*100);
    printf("P4 = %.2f \n",(float)p4/n*100);
    printf("P5 = %.2f \n",(float)p5/n*100);
    return 0;
}
