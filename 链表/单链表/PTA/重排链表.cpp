#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    int next;
};

const int MAX_ADDRESS = 100000;

int main() {
    int head, n;
    cin >> head >> n;

    Node nodes[MAX_ADDRESS];
    for (int i = 0; i < n; ++i) {
        int address, data, next;
        cin >> address >> data >> next;
        nodes[address].data = data;
        nodes[address].next = next;
    }

    vector<int> addressList;
    int current = head;
    while (current != -1) {
        addressList.push_back(current);
        current = nodes[current].next;
    }

    vector<int> reorderedAddressList;
    int left = 0, right = addressList.size() - 1;
    while (left <= right) {
        if (left == right) {
            reorderedAddressList.push_back(addressList[right]);
        } else {
            reorderedAddressList.push_back(addressList[right]);
            reorderedAddressList.push_back(addressList[left]);
        }
        left++;
        right--;
    }

    for (int i = 0; i < reorderedAddressList.size(); ++i) {
        int address = reorderedAddressList[i];
        printf("%05d %d ", address, nodes[address].data);
        if (i < reorderedAddressList.size() - 1) {
            printf("%05d\n", reorderedAddressList[i + 1]);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}