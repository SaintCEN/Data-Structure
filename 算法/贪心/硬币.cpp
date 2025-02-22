#include <iostream>
#include <algorithm>
using namespace std;
const int V[6] = {1,5,10,50,100,500};
int C[6];
int A;
int main(){
	cin >> A;
	for(int j=0;j<6;j++){
		cin >> C[j];
	}
	int ans=0;
	for(int i=5;i>=0;i--){
		int t = min(A/V[i],C[i]);
		A -= t * V[i];
		ans+=t;
	}
	cout << ans ;
}