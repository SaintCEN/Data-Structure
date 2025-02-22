#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int r;
	cin>>n;
	cin>>r;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=0;
	int ans=0;
	while(i<n){
		int s=a[i];
		i++;
		while(i<n&&a[i]<=s+r){
			i++;
		}
		int p=a[i-1];
		while(i<n&&a[i]<=p+r){
			i++;
		}
		ans++;
	}
}