#include<bits/stdc++.h>
using namespace std;
int opt,n,t[100001],p[100001],ans,top,m=1,yh[100001],sj[100001],k;
bool r[100001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&opt,&p[i],&t[i]);
		if(opt==0) yh[++top]=p[i],sj[top]=t[i],ans+=p[i];
		else{
			k=0;
			for(int j=m;j<=top;j++){
				if(r[j]) continue;
				if(t[i]-sj[j]>45) m=j;
				else if(yh[j]>=p[i]){
					k=j;
					r[k]=true;
					break;
				}
			}
			if(!k) ans+=p[i];
		}
	} 
	printf("%d",ans);
}
/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Ticket {
    int price;
    int time;
    int used;
};

struct Compare {
    bool operator()(const Ticket& a, const Ticket& b) {
        if (a.price == b.price) return a.time > b.time;
        return a.price > b.price; 
    }
};

int main() {
    int n;
    cin >> n;
    vector<Ticket> tickets; 
    priority_queue<Ticket, vector<Ticket>, Compare> pq; 
    int cost = 0;
    for (int i = 0; i < n; i++) {
        int op, price, time;
        cin >> op >> price >> time;
        if (op == 0) {
            cost += price;
            tickets.push_back({price, time + 45, 0}); 
            pq.push({price, time + 45, 0}); 
        } else {
            bool flag = false;
            while (!pq.empty()) {
                Ticket top = pq.top();
                pq.pop();
                if (price <= top.price && time <= top.time && top.used == 0) {
                    top.used = 1; 
                    flag = true;
                    break;
                }
                tickets.push_back(top);
            }
            if (!flag) {
                cost += price;
                tickets.push_back({price, time + 45, 0});
                pq.push({price, time + 45, 0});
            }
        }
    }
    cout << cost << endl;
    return 0;
}*/