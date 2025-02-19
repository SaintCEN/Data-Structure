class Node:
    def __init__(self, data):
        self.next = None
        self.data = data

class LinkedList:
    def __init__(self):
        self.head = None

    def GetElem(self, i):
        p = self.head
        j = 0
        while p and j < i:
            p = p.next
            j += 1
        if not p or j > i:
            return None
        return p.data

    def insert(self, i, e):
        p = self.head
        j = 0
        while p and j < i - 1:
            p = p.next
            j += 1
        if not p or j > i - 1:
            return
        s = Node(e)
        s.next = p.next
        p.next = s

    def delete(self, i):
        p = self.head
        j = 0
        while p and j < i - 1:
            p = p.next
            j += 1
        if not p or not p.next or j > i - 1:
            return
        q = p.next
        p.next = q.next
        del q

    def create_H(self, n):
        self.head = Node(None)
        for _ in range(n):
            data = int(input("Enter data: "))
            p = Node(data)
            p.next = self.head.next
            self.head.next = p

    def create_R(self, n):
        self.head = Node(None)
        r = self.head
        for _ in range(n):
            data = int(input("Enter data: "))
            p = Node(data)
            p.next = None
            r.next = p
            r = p

    def print_list(self):
        p = self.head.next
        while p:
            print(p.data, end=" -> ")
            p = p.next
        print("None")

def main():
    ll = LinkedList()
    n = int(input("Enter the number of elements: "))
    ll.create_R(n)
    ll.print_list()

    ll.insert(2, 10)
    ll.print_list()

    ll.delete(1)
    ll.print_list()

    elem = ll.GetElem(1)
    print(f"Element at position 1: {elem}")

if __name__ == "__main__":
    main()