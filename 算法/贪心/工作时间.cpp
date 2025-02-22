#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main(){
	cin>>n;
int s[n];
int t[n];
pair<int,int> itv[n];
	for(int i=0;i<n;i++){
			cin>>s[i]>>t[i];
			itv[i].first=t[i];
			itv[i].second=s[i];
		}
		sort(itv,itv+n);
		int ans=0;
		int k=0;
		for(int i=0;i<n;i++){
			if(k<itv[i].second){
				ans++;
				k=itv[i].first;
			}
		}
		cout << ans;
	return 0;
}