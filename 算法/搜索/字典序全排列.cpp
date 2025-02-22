#include <iostream>
using namespace std;
int n;
int num[10];
int check[10];
int dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++){
            printf("%d ",num[i]);
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        if(check[i]==0){
            num[u]=i;
            check[i]=1;
            dfs(u+1);
            check[i]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    dfs(0);
    return 0;
}