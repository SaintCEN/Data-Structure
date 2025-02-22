#include <iostream>
#include <queue>
using namespace std;
int N,a,b;
int L[201];
int ans[201]={0};
int check[201]={0};
int options[3] = {1,0,-1};
int bfs(int *L,int a,int b,int N){
	int steps = 0;
	int n = sizeof(L);
	typedef pair<int,int> p;
	queue <p> que;
	que.push({a,ans[a]});
	check[a]=1;
	while(que.size()>0){
		int count =0;
		int m = que.front().first;
		int n = que.front().second;
		int floor;
		que.pop();
		if(m == b) return n;
		for (int j=0;j<3;j++){
				floor = m+L[m]*options[j];
				if(check[floor]==0&&floor>0&&floor<=N){
					que.push({floor,ans[m]+1});
					ans[floor] = ans[m]+1;
					check[floor]=1;
				}
			}
		}
	return -1;
}
int main(){
	cin >> N >> a >> b;
	for(int i=1;i<=N;i++){
		cin >> L[i];
	}
	int ans = bfs(L,a,b,N);
	cout << ans << endl;
	return 0;
}
