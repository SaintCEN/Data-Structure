#include <iostream>
#include <queue>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans = 0;
	priority_queue< int,vector<int>,greater<int> > que;
	for(int i=0;i<n;i++){
		que.push(a[i]);
	}
	while(que.size()>1){
		int l1,l2;
		l1=que.top();
		que.pop();
		l2=que.top();
		que.pop();
		que.push(l1+l2);
		ans+=l1+l2
	}
	cout << ans;
	return 0;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	while(n>1){
	int min1=0,min2=1;
	if(a[min1]>a[min2]){
		swap(min1,min2);
	}
	for(int i=2;i<n;i++){
		if(a[i]<a[min1]){
			min2=min1;
			min1=i;
		}
		else if(a[i]<a[min2]){
			min2=i;
		}
	}
	int t=a[min1]+a[min2];
	ans+=t;
	if(min1==n-1){
		swap(min1,min2);
	}
	a[min1]=t;
	a[min2]=a[n-1];
	n--;
}
    cout << ans;
	return 0;
}
*/