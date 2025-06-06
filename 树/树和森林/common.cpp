#define MAXSIZE 100

// 双亲表示法
typedef struct
{
    char data;
    int parent;
} PTNode;
typedef struct
{
    PTNode nodes[MAXSIZE];
    int n;
} PTree;

// 孩子表示法
typedef struct CSNode
{
    char data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;