class DulNode:
    def __init__(self, data=None):
        self.data = data
        self.prior = None
        self.next = None

# 初始化双链表
def init_list():
    head = DulNode()
    return head

# 创建双链表
def create_list(n):
    head = init_list()
    p = head
    for i in range(n):
        new_node = DulNode()
        new_node.data = int(input())
        new_node.prior = p
        new_node.next = None
        p.next = new_node
        p = new_node
    return head

# 插入操作
def insert_node(head, pos, value):
    p = head
    i = 0
    while p and i < pos:
        p = p.next
        i += 1
    if not p or i > pos:
        print("Invalid.")
        return
    new_node = DulNode(value)
    new_node.next = p.next
    new_node.prior = p
    if p.next:
        p.next.prior = new_node
    p.next = new_node

# 删除操作
def delete_node(head, pos):
    p = head.next
    i = 0
    while p and i < pos:
        p = p.next
        i += 1
    if not p or i > pos:
        print("Invalid.")
        return
    if p.prior:
        p.prior.next = p.next
    if p.next:
        p.next.prior = p.prior
    del p

# 正向遍历
def traverse_forward(head):
    p = head.next
    while p:
        print(p.data, end=" ")
        p = p.next
    print()

# 反向遍历
def traverse_backward(head):
    p = head
    while p.next:
        p = p.next
    while p != head:
        print(p.data, end=" ")
        p = p.prior
    print()

if __name__ == "__main__":
    head = create_list(5)
    traverse_forward(head)
    traverse_backward(head)
    insert_node(head, 2, 99)
    delete_node(head, 3)