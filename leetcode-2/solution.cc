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
        ListNode* res = new ListNode(0);
        ListNode* result = res;
        while((l1 != NULL) && (l2 != NULL)) {
            int val = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            if(val < 10) {
                result->next = new ListNode(val);
                result = result->next;
            } else {
                int modVal = val % 10;
                int divVal = val / 10;
                result->next = new ListNode(modVal);
                result = result->next;

                if(NULL == l1) {
                    l1 = new ListNode(divVal);
                } else if(NULL == l2) {
                    l2 = new ListNode(divVal);
                } else {
                    l1->val += divVal;
                }
            }
        }

        if(NULL != l1) {
            result->next = l1;
        } else if(NULL != l2) {
            result->next = l2;
        }

        return res->next;
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
