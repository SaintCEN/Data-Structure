#include<iostream>
using namespace std;
const int N=100010;
int a[N],b[N];
int main()
{
    int n;
    cin>>n;
    int maxl=1;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0,j=0;i<n;i++)//i为右指针，j为左指针
    {
        b[a[i]]++;
        while(b[a[i]]>1)
            b[a[j++]]--;
        maxl=max(maxl,i-j+1);
    }
    cout<<maxl;
    return 0;
}