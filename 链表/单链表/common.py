class Sqlist:
    MAXSIZE = 100

    def __init__(self):
        self.elem = [0] * Sqlist.MAXSIZE  
        self.length = 0              

    def get_element(self, i):
        if i < 1 or i > self.length:
            return None 
        return self.elem[i - 1]

    def find_element(self, e):
        for idx in range(self.length):
            if self.elem[idx] == e:
                return idx + 1  
        return 0

    def insert_element(self, i, e):
        if i < 1 or i > self.length + 1:
            return  
        if self.length >= Sqlist.MAXSIZE:
            return  
        self.elem.insert(i - 1, e)
        self.length += 1

    def delete_element(self, i):
        if i < 1 or i > self.length:
            return 
        del self.elem[i - 1]
        self.length -= 1


def main():
    sqlist = Sqlist()
    while True:
        print("1. 获取元素")
        print("2. 查找元素")
        print("3. 插入元素")
        print("4. 删除元素")
        print("5. 退出程序")
        choice = input()
        if choice == '1':
            i = int(input())
            result = sqlist.get_element(i)
            if result is not None:
                print(result)
            else:
                print("Invalid")
        elif choice == '2':
            e = int(input())
            pos = sqlist.find_element(e)
            if pos != 0:
                print(pos)
            else:
                print("Invalid.")
        elif choice == '3':
            insert_pos = int(input())
            value = int(input())
            sqlist.insert_element(insert_pos, value)
        elif choice == '4':
            delete_pos = int(input())
            sqlist.delete_element(delete_pos)
        elif choice == '5':
            break
        else:
            print("Invalid.")

if __name__ == "__main__":
    main()
