#include <iostream>
#include <vector>
using namespace std;

// B树节点定义
struct BTreeNode
{
    bool is_leaf;           // 标记是否为叶子节点
    int num_keys;           // 当前节点存储的键的数量（最多2个）
    int keys[2];            // 存储键的数组（容量为2）
    BTreeNode *children[3]; // 子节点指针数组（最多3个子节点）
    void *data[2];          // 存储键对应数据的指针数组
};

// 初始化
void InitBTree(BTreeNode *node, bool leaf = false)
{
    node->is_leaf = leaf; // 设置是否为叶子节点
    node->num_keys = 0;   // 初始键数为0
    for (int i = 0; i < 3; i++)
    {
        node->children[i] = nullptr; // 所有子节点指针置空
    }
}

// 查找函数
void *BTreeSearch(BTreeNode *root, int target)
{
    if (root == nullptr) // 空树直接返回nullptr
        return nullptr;

    BTreeNode *current = root; // 从根节点开始查找
    while (current != nullptr)
    {
        int i = 0;
        // 找到第一个不小于target的键的位置i
        while (i < current->num_keys && target > current->keys[i])
        {
            i++;
        }

        // 找到目标键，返回对应数据
        if (i < current->num_keys && target == current->keys[i])
        {
            return current->data[i];
        }

        // 当前是叶子节点且未找到，返回nullptr
        if (current->is_leaf)
        {
            return nullptr;
        }

        // 进入子节点继续查找
        current = current->children[i];
    }
    return nullptr;
}

// B+树内部节点
struct BPlusInternalNode
{
    bool is_leaf;      // 固定为false，表示内部节点
    int num_keys;      // 当前键的数量（最多4个）
    int keys[4];       // 键数组（阶数为5，最多4个键）
    void *children[5]; // 子节点指针数组（最多5个子节点）

    void InitBplus()
    {
        is_leaf = false; // 明确标记为非叶子节点
        num_keys = 0;    // 初始键数为0
        for (int i = 0; i < 5; i++)
            children[i] = nullptr; // 子节点指针置空
    }
};
// B+树叶子节点
struct BPlusLeafNode
{
    bool is_leaf;        // 固定为true，表示叶子节点
    int num_keys;        // 当前键的数量（最多4个）
    int keys[4];         // 键数组
    void *data[4];       // 数据指针数组
    BPlusLeafNode *next; // 指向下一个叶子节点（支持范围查询）

    void InitBplus()
    {
        is_leaf = true; // 明确标记为叶子节点
        num_keys = 0;   // 初始键数为0
        for (int i = 0; i < 4; i++)
            data[i] = nullptr; // 数据指针置空
        next = nullptr;        // 下一个叶子节点指针置空
    }
};

void *BPlusTreeSearch(void *root, int target)
{
    if (root == nullptr) // 空树直接返回nullptr
        return nullptr;

    void *current = root; // 从根节点开始查找

    // 循环直到到达叶子节点
    while (!static_cast<BPlusLeafNode *>(current)->is_leaf)
    {
        BPlusInternalNode *internal = static_cast<BPlusInternalNode *>(current);
        int i = 0;

        // 找到第一个大于等于target的键的位置i
        while (i < internal->num_keys && target >= internal->keys[i])
        {
            i++;
        }

        // 进入对应的子节点
        current = internal->children[i];
    }

    // 在叶子节点中线性查找目标键
    BPlusLeafNode *leaf = static_cast<BPlusLeafNode *>(current);
    for (int i = 0; i < leaf->num_keys; i++)
    {
        if (leaf->keys[i] == target)
        {
            return leaf->data[i];
        }
    }

    return nullptr; // 未找到
}