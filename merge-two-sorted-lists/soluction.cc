#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mergeList = new ListNode(0);
        ListNode* temp = mergeList;
        while((NULL != l1) && (NULL != l2)) {
            temp->next = compareList(l1, l2);
            temp = temp->next;
        }

        temp->next = NULL == l1 ? l2 : l1;
        return mergeList->next;
    }

private:
    ListNode* compareList(ListNode*& l1, ListNode*& l2) {
        ListNode* result = NULL;
        if(l1->val < l2->val) {
            result = l1;
            l1 = l1->next;
        } else {
            result = l2;
            l2 = l2->next;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution aa;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* bb = aa.mergeTwoLists(l1, l2);
    while(bb != NULL) {
        cout << bb->val << endl;
        bb = bb->next;
    }
    return 0;
}
