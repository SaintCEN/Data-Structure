#include<iostream>
#include<queue>
using namespace std;
const int N = 10001
int main(){
	int l,p,n
	cin >> l >> p >> n;
	int a[N];
	int b[N];
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	a[n]=L;
	b[n]=0;
	n++;
	priority_queue<int> que;
	int ans = 0,pos=0,tank=p;
	for(int i=0;i<n;i++){
		int d = a[i] - pos ;
		while(tank - d < 0){
			if(que.empty()){
				puts(-1);
			}
			tank += que.top();
			que.pop();
			ans ++ ;
		}
		tank - = d;
		pos=a[i];
		que.push(b[i]);
	}
	cout << ans << endl;
	return 0;
}