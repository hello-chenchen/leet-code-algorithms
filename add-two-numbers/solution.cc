#include <iostream>
#include <string>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string strLen1 = "";
        string strLen2 = "";

        int index1 = 0;
        while(NULL != l1) {
            strLen1.insert(index1++, to_string(l1->val));
            l1 = l1->next;
        }

        int index2 = 0;
        while(NULL != l2) {
            strLen2.insert(index2++, to_string(l2->val));
            l2 = l2->next;
        }

        long long value1 = stoll(strLen1);
        long long value2 = stoll(strLen2);
        long long value3 = value1 + value2;
        string value = to_string(value3);
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        int valLen = value.size();
        for(int i = 0; i < valLen; i++) {
            char a = value[valLen-1 - i];
            temp->next = new ListNode(a - ('1' - 1));
            temp = temp->next;
        }

        return result->next;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    ListNode* a = new ListNode(2);
    a->next = new ListNode(4);
    a->next->next = new ListNode(3);
    ListNode* b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(4);
    Solution aa;
    ListNode* bb = aa.addTwoNumbers(a, b);
    while(bb != NULL) {
        cout << "bb->val: " << bb->val << endl;
        bb = bb->next;
    }
    return 0;
}
