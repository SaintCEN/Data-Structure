class SqQueue:
    def __init__(self):
        self.maxsize = 100
        self.base = [None] * self.maxsize
        self.front = 0
        self.rear = 0

    def is_empty(self):
        return self.front == self.rear

    def is_full(self):
        return (self.rear + 1) % self.maxsize == self.front

    def queue_length(self):
        return (self.rear - self.front + self.maxsize) % self.maxsize

    def enqueue(self, e):
        if self.is_full():
            return
        self.base[self.rear] = e
        self.rear = (self.rear + 1) % self.maxsize

    def dequeue(self):
        if self.is_empty():
            return None
        e = self.base[self.front]
        self.front = (self.front + 1) % self.maxsize
        return e

    def get_head(self):
        if not self.is_empty():
            return self.base[self.front]
        return -1

    def print_queue(self):
        if self.is_empty():
            return
        i = self.front
        while i != self.rear:
            print(self.base[i], end=" ")
            i = (i + 1) % self.maxsize
        print()

    def destroy_queue(self):
        self.base = [None] * self.maxsize
        self.front = self.rear = 0


if __name__ == "__main__":
    q = SqQueue()
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    head_element = q.get_head()
    print(head_element)  
    dequeued_element = q.dequeue()
    print(dequeued_element)  
    q.print_queue()  
    q.destroy_queue()