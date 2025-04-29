#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 双亲表示法的节点结构
struct ParentNode
{
    char data;
    int parent; // -1表示没有双亲(根节点)
};

// 双亲表示法的树结构
struct ParentTree
{
    vector<ParentNode> nodes;
    int root;
};

struct ChildNode
{
    char data;
    list<int> children; // 存储孩子节点的索引（在数组中的位置）
};

// 孩子表示法的树结构
struct ChildTree
{
    vector<ChildNode> nodes; // 节点数组
    int root;                // 根节点索引（-1 表示空树）
};
