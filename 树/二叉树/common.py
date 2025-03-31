class BiTNode:
    def __init__(self, data=None):
        self.data = data
        self.lchild = None
        self.rchild = None

# 递归中序遍历
def in_order_traverse(root):
    if root:
        in_order_traverse(root.lchild)
        print(root.data, end='')
        in_order_traverse(root.rchild)

# 递归先序遍历
def pre_order_traverse(root):
    if root:
        print(root.data, end='')
        pre_order_traverse(root.lchild)
        pre_order_traverse(root.rchild)

# 递归后序遍历
def post_order_traverse(root):
    if root:
        post_order_traverse(root.lchild)
        post_order_traverse(root.rchild)
        print(root.data, end='')

# 非递归中序遍历
def in_order_non_recursive(root):
    stack = []
    p = root
    while p or stack:
        if p:
            stack.append(p)
            p = p.lchild
        else:
            node = stack.pop()
            print(node.data, end='')
            p = node.rchild

# 创建二叉树（前序输入）
def create_bi_tree(s):
    def helper(it):
        try:
            ch = next(it)
            if ch == '#':
                return None
            node = BiTNode(ch)
            node.lchild = helper(it)
            node.rchild = helper(it)
            return node
        except StopIteration:
            return None
    return helper(iter(s))

# 复制二叉树
def copy_bi_tree(root):
    if not root:
        return None
    new_node = BiTNode(root.data)
    new_node.lchild = copy_bi_tree(root.lchild)
    new_node.rchild = copy_bi_tree(root.rchild)
    return new_node

# 计算二叉树深度
def depth(root):
    if not root:
        return 0
    return max(depth(root.lchild), depth(root.rchild)) + 1

# 统计节点个数
def node_count(root):
    if not root:
        return 0
    return node_count(root.lchild) + node_count(root.rchild) + 1