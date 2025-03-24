#include <stdio.h>
void max(int x , int y , int *px);
int main()
{
    int a,b;
    int m,n;
    scanf("%d %d",&a,&b);
    max(a,b,&m);
    n=a/m*b/m*m;
    printf("%d %d",m,n);
    return 0;
}
void max(int x ,int y ,int *px)
{
 while (y>0)
    {
    	int i;
        i=x%y;
        x=y;
        y=i;
    }
    *px=x;
}
