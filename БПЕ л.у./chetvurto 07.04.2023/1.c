#include <stdio.h>
#include <stdlib.h>
int main(void)
{
char str[80] = "This is a file system test. \n";
FILE *fp;
char *p;
int i;
/* отваря myfile за изход */
if((fp = fopen("myfile", "w"))==NULL)
{
printf("Cannot open file. \n");
exit(1);
}
/* записва str на диска */
p = str;
while(*p)
{
if(fputc(*p, fp)==EOF)
{
printf("Error writing file. \n");
exit(1);
}
p++;
}
fclose(fp);
/* отваря myfile за вход */
if((fp = fopen("myfile", "r"))==NULL)
{
printf("Cannot open file. \n");
exit(1);
}
/* чете отново файла */
for(;;)
{
i = getc(fp);
if(i == EOF) break;
putchar(i);
}
fclose(fp);
return 0;
}       