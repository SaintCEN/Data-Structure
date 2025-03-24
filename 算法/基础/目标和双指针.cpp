#include <iostream>
using namespace std;
const int N = 100001;
int m,n,x;
int a[N];
int b[N];
int main(){
	cin >> m >> n >> x;
	for(int i=0;i<m;i++){
		cin >> a[i];
	}
	for(int j=0;j<n;j++){
		cin >> b[j];
	}
	for (int i = 0, j = n - 1; i < m; i ++) {
        while(j >= 0 && a[i] + b[j] > x) j --;
        if(j >= 0 && a[i] + b[j] == x) printf("%d %d\n", i, j);
    }
	return 0;
}