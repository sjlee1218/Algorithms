#include <stdio.h>

int main(void)
{
    int a;
    int i,j;
    scanf("%d",&a);
    for(i=1;i<=a;i++)
    {
    for(j=1;j<=i;j++)
    {
        printf("*");
    }
    printf("\n");
    }
    return 0;
}
