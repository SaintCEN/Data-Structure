#include <iostream>
#include <vector>
using namespace std;

vector<int> postorder;
vector<int> tree;
int N;

void buildTree(int root, int &index)
{
    if (root >= N)
        return;
    buildTree(2 * root + 1, index);
    buildTree(2 * root + 2, index);
    tree[root] = postorder[index];
    index++;
}

int main()
{
    cin >> N;
    postorder.resize(N);
    tree.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> postorder[i];
    }
    int index = 0;
    buildTree(0, index);
    for (int i = 0; i < N; ++i)
    {
        if (i != 0)
            cout << " ";
        cout << tree[i];
    }
    cout << endl;
    return 0;
}