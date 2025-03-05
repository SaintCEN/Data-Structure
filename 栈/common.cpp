#include<bits/stdc++.h>
using namespace std;

#define maxsize 100
typedef int ElemType;

typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;
//初始化
void InitStack(SqStack &s){
    s.base = new ElemType[maxsize];
    if(!s.base) return;
    s.top = s.base;
    s.stacksize = maxsize;
}
//是否为空
bool IsEmpty(SqStack s){
    return s.top == s.base;
}
//是否已满
bool IsFull(SqStack s){
    return s.top - s.base == s.stacksize;
}
//进栈
void Push(SqStack &s, ElemType e){
    if(IsFull(s)){
        return;
    }
    *s.top = e;
    s.top++;
}
//出栈
void Pop(SqStack &s, ElemType &e){
    if(IsEmpty(s)){
        cout << "Stack is empty. Cannot pop element." << endl;
        return;
    }
    s.top--;
    e = *s.top;
}
// 获取栈顶元素
ElemType GetTop(SqStack s){
    if(IsEmpty(s)){
        return -1; 
    }
    return *(s.top - 1);
}
// 打印栈中的所有元素
void PrintStack(SqStack s){
    if(IsEmpty(s)){
        return;
    }
    for(ElemType *p = s.base; p != s.top; p++){
        cout << *p << " ";
    }
    cout << endl;
}
// 销毁栈
void DestroyStack(SqStack &s){
    delete[] s.base;
    s.base = s.top = nullptr;
    s.stacksize = 0;
}

int main(){
    SqStack s;
    InitStack(s);
    Push(s, 10);
    Push(s, 20);
    Push(s, 30);
    ElemType topElement = GetTop(s);
    cout << topElement << endl; 
    ElemType poppedElement;
    Pop(s, poppedElement);
    cout << poppedElement << endl; 
    PrintStack(s); 
    DestroyStack(s);
    return 0;
}
/*
#include<stack>
stack<int> s1;
s1.push(2);
s1.push(1);
stack<int> s2(s1);
s1.pop();
cout << s1.size() << " " << s2.size() << std::endl;  // 1 2
cout << s1.top() << " " << s2.top() << std::endl;    // 2 1
s1.pop();
cout << s1.empty() << " " << s2.empty() << std::endl;  // 1 0
*/