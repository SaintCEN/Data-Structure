#include <iostream>
#include <vector>
#include <list>

using namespace std;

static const int tableSize = 10;

// 哈希表数组，包含链表来处理冲突
vector<list<pair<int, string>>> table(tableSize);

// 哈希函数
int hashFunction(int key)
{
    return key % tableSize;
}

// 插入操作
void insert(int key, string value)
{
    int index = hashFunction(key);
    // 通过链表的方式处理哈希冲突
    table[index].push_back(make_pair(key, value));
}

// 查找操作
string search(int key)
{
    int index = hashFunction(key);
    for (auto &pair : table[index])
    {
        if (pair.first == key)
        {
            return pair.second;
        }
    }
    return;
}

// 删除操作
void remove(int key)
{
    int index = hashFunction(key);
    auto &chain = table[index];
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        if (it->first == key)
        {
            chain.erase(it);
            return;
        }
    }
}