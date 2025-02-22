#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n==0) return 0;
    queue<int> q;
    int first;
    cin >> first;
    q.push(first);

    for (int i = 0; i < n - 1; i++) {
        int second;
        cin >> second;

        if (first == second) {
            int size = q.size();
            for (int j = 0; j < size - 1; j++) {
                int front = q.front();
                q.pop();
                q.push(front);
                first = front;  
            }
            q.pop(); 
        } else {
            q.push(second);
            first = second;
        }
    }
    
    if(q.size()==0) printf("NULL");
    else{
    while (q.size()!=0) {
        cout << q.front() << " ";
        q.pop();
    }
}
    return 0;
}
