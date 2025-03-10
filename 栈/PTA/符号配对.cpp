#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isLeft(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isRight(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool tipLeft(const string& line, int i) {
    return line[i] == '/' && i + 1 < line.size() && line[i + 1] == '*';
}

bool tipRight(const string& line, int i) {
    return line[i] == '*' && i + 1 < line.size() && line[i + 1] == '/';
}

char Match(char right) {
    switch (right) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default: return '\0';
    }
}

int main() {
    stack<char> s;  
    string line;
    bool istip = false;  
    bool isError = false;  
    char firstError = '\0';  
    int symbolCount = 0;  

    while (getline(cin, line)) {
        if (line == ".") break; 
        
        for (int i = 0; i < line.size(); i++) {
            if (symbolCount >= 100) {  
                isError = true;
                firstError = 'E'; 
                break;
            }

            if (istip) {
                if (tipRight(line, i)) {
                    if (s.empty() || s.top() != '/') {  
                        isError = true;
                        firstError = '*';  
                        break;
                    }
                    s.pop();  
                    istip = false;  
                    i++;  
                    symbolCount++;  
                }
            } else {
                if (tipLeft(line, i)) {  
                    s.push('/');  
                    istip = true; 
                    i++;  
                    symbolCount++;  
                } else if (isLeft(line[i])) {  
                    s.push(line[i]);
                    symbolCount++;  
                } else if (isRight(line[i])) {  
                    if (s.empty() || s.top() != Match(line[i])) {  
                        isError = true;
                        firstError = line[i];  
                        break;
                    }
                    s.pop();  
                    symbolCount++;  
                }
            }
        }
        if (isError) break; 
    }

    if (isError) {
        if (firstError == 'E') {
            cout << "NO" << endl;
        } else {
            cout << "NO" << endl;
            if (firstError == '*') {
                cout << "?-*/" << endl;  
            } else {
                cout << "?-" << firstError << endl; 
            }
        }
    } else {
        if (s.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            char topSymbol = s.top();
            if (topSymbol == '/') {
                cout << "/*-?" << endl; 
            } else {
                cout << topSymbol << "-?" << endl; 
            }
        }
    }
    return 0;
}
