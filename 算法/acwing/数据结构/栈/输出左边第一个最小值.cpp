#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x;
    stack<int> t;
    for (int i = 0; i < n; i ++ ){
        cin>>x;
        while(t.size() && t.top()>=x)t.pop();
        if(t.empty()){
            cout<<"-1"<<' ';
        }else{
            cout<<t.top()<<' ';
        }
        t.push(x);
    }

    return 0;
}