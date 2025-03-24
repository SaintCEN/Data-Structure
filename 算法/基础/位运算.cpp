/*
lowbit(n)=x&-x;//返回n的最后一位1
n >> k & 1 //第k位数字
*/
#include <iostream>
using namespace std;
int main(){
	int n,a,k;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		k=0;
		while(a){
		k+=a&1;
		a=a >> 1; 
	}
	    cout << k << ' ';
	}
	return 0;
}