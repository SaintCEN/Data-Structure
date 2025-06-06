#include <iostream>
using namespace std;

typedef struct Node {
    int coeff; 
    int exp;   
    Node* next; 
}Node;

void addNode(Node* &head, int coeff, int exp) {
    Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->exp = exp;
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printPoly(Node* head) {
    if (!head) {
        cout << "0 0";
        return;
    }
    while (head) {
        cout << head->coeff << " " << head->exp;
        if (head->next) {
            cout << " ";
        }
        head = head->next;
    }
}

Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* tail = NULL;

    while (poly1 || poly2) {
        int coeff = 0, exp = 0;
        if (poly1 && (!poly2 || poly1->exp > poly2->exp)) {
            coeff = poly1->coeff;
            exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly2 && (!poly1 || poly2->exp > poly1->exp)) {
            coeff = poly2->coeff;
            exp = poly2->exp;
            poly2 = poly2->next;
        } else {
            coeff = poly1->coeff + poly2->coeff;
            exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (coeff != 0) {
            if (!result) {
                result = new Node;
                result->coeff = coeff;
                result->exp = exp;
                tail = result;
            } else {
                tail->next = new Node;
                tail->next->coeff = coeff;
                tail->next->exp = exp;
                tail = tail->next;
            }
        }
    }
    if (!result) {
        result = new Node;
        result->coeff = 0;
        result->exp = 0;
    }
    return result;
}

Node* multiplyPoly(Node* poly1, Node* poly2) {
    if (!poly1 || !poly2) {
        Node* p = new Node;
        p->coeff = 0;
        p->exp = 0;
        return p; 
}
    Node* result = NULL;
    
    for (Node* p1 = poly1; p1; p1 = p1->next) {
        for (Node* p2 = poly2; p2; p2 = p2->next) {
            int newCoeff = p1->coeff * p2->coeff; 
            int newExp = p1->exp + p2->exp;     
            
            Node* temp = result;
            Node* prev = NULL;
            
            while (temp && temp->exp > newExp) {
                prev = temp;
                temp = temp->next;
            }//指数大则一直往后移

            if (temp && temp->exp == newExp) {
                temp->coeff += newCoeff;
                if (temp->coeff == 0) {
                    if (prev) {
                        prev->next = temp->next;
                    } else {
                        result = temp->next;
                    }
                    delete temp;
                }//相加后系数为0 则删除该节点
            } 
            else {
                Node* newNode = new Node;
                newNode->coeff = newCoeff;
                newNode->exp = newExp;
                if (prev) {
                    newNode->next = prev->next;
                    prev->next = newNode;
                } else {
                    newNode->next = result;
                    result = newNode;
                }
            }
        }
    }

    if (!result) {
        result->coeff = 0;
        result->exp = 0;
    }
    
    return result;
}

int main() {
    Node* poly1 = NULL; 
    Node* poly2 = NULL; 

    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int coeff, exp;
        cin >> coeff >> exp;
        addNode(poly1, coeff, exp);
    }

    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int coeff, exp;
        cin >> coeff >> exp;
        addNode(poly2, coeff, exp);
    }

    Node* product = multiplyPoly(poly1, poly2);
    Node* sum = addPoly(poly1, poly2);

    printPoly(product);
    cout << endl;
    printPoly(sum);
    cout << endl;

    return 0;
}