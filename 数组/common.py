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
        print("\n请选择操作：")
        print("1. 获取元素")
        print("2. 查找元素")
        print("3. 插入元素")
        print("4. 删除元素")
        print("5. 退出程序")
        choice = input()
        if choice == '1':
            i = int(input("请输入要获取的元素位置："))
            result = sqlist.get_element(i)
            if result is not None:
                print(f"第{i}个元素是：{result}")
            else:
                print("无效的位置！")
        elif choice == '2':
            e = int(input("请输入要查找的元素值："))
            pos = sqlist.find_element(e)
            if pos != 0:
                print(f"元素{e}在位置{pos}")
            else:
                print("未找到该元素！")
        elif choice == '3':
            insert_pos = int(input("请输入插入的位置："))
            value = int(input("请输入要插入的值："))
            sqlist.insert_element(insert_pos, value)
            print("插入成功！")
        elif choice == '4':
            delete_pos = int(input("请输入要删除的位置："))
            sqlist.delete_element(delete_pos)
            print("删除成功！")
        elif choice == '5':
            print("退出程序。")
            break
        else:
            print("无效的选项，请重新输入！")

if __name__ == "__main__":
    main()
