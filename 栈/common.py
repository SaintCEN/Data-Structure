class SqStack:
    def __init__(self):
        self.maxsize = 100
        self.base = [None] * self.maxsize
        self.top = 0
        self.stacksize = self.maxsize

    def is_empty(self):
        return self.top == 0

    def is_full(self):
        return self.top == self.stacksize

    def push(self, e):
        if self.is_full():
            return
        self.base[self.top] = e
        self.top += 1

    def pop(self):
        if self.is_empty():
            return None
        self.top -= 1
        return self.base[self.top]

    def get_top(self):
        if self.is_empty():
            return -1
        return self.base[self.top - 1]

    def print_stack(self):
        if self.is_empty():
            return
        for i in range(self.top):
            print(self.base[i], end=" ")
        print()

    def destroy_stack(self):
        self.base = [None] * self.maxsize
        self.top = 0
        self.stacksize = self.maxsize


if __name__ == "__main__":
    s = SqStack()
    s.push(10)
    s.push(20)
    s.push(30)
    top_element = s.get_top()
    print(top_element)
    popped_element = s.pop()
    print(popped_element)
    s.print_stack()
    s.destroy_stack()