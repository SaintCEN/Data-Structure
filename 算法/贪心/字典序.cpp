#include <iostream>
using namespace std;
int n;
char s[1000001];
int main(){
	cin>>n;
	int a=0;
	int b=n-1;
	while(a<=b){
		bool left = false;
		for(int i=0;a+i<=b;i++){
			if(s[a+i]<s[b-i]){
				left=true;
				break;
			}
			else if(s[a+i]>s[b-i]){
				left=false;
				break;
			}
		}
		if(left){
			putchar(s[a]);
			a++;
		}
		else{
			putchar(s[b]);
			b--;
		}
	}
	return 0;
}