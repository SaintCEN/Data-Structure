#include <stdio.h>
int max_num(int a,int b, int c);
int main()
{
	int a[100];
	int n;
	int t,i,j,k;
	int max=0;
	scanf("%d",&n);
	for(t=0;t<n;t++){
		scanf("%d",&a[t]);
	}
	//i<j<k
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				int len=a[i]+a[j]+a[k];
				int ma=max_num(a[i],a[j],a[k]);
				int rest=len-ma;
				if(ma<rest){
					if(len>max){
						max=len;
					}
				}
			}
		}
	}
	printf("%d",max);
	return 0;
}
int max_num(int a,int b,int c){
	int max=0;
	if (a>max){
		max=a;
	}
	if(b>max)
	{
		max=b;
	}
	if(c>max){
		max=c;
	}
	return max;
}