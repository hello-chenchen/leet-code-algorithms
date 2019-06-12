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
        if(NULL == l1 && NULL == l2) {
            return NULL;
        }

        int index1 = 0;
        int index2 = 0;
        int val = 0;
        val = compareVal(l1, l2);
        ListNode* mergeList = new ListNode(val);
        ListNode* temp = mergeList;
        while((NULL != l1) || (NULL != l2)) {
            temp->next = compareList(l1, l2);
            temp = temp->next;
        }
        return mergeList;
    }

private:
    ListNode* compareList(ListNode*& l1, ListNode*& l2) {
        ListNode* result = NULL;
        if(NULL == l1 || NULL == l2) {
            if(NULL != l1) {
                result = l1;
                l1 = l1->next;
            } else {
                result = l2;
                l2 = l2->next;
            }
            return result;
        }

        if(l1->val < l2->val) {
            result = l1;
            l1 = l1->next;
        } else {
            result = l2;
            l2 = l2->next;
        }
        return result;
    }

    int compareVal(ListNode*& l1, ListNode*& l2) {
        int result = 0;
        if(NULL == l1 || NULL == l2) {
            if(NULL != l1) {
                result = l1->val;
                l1 = l1->next;
            } else {
                result = l2->val;
                l2 = l2->next;
            }
            return result;
        }

        if(l1->val < l2->val) {
            result = l1->val;
            l1 = l1->next;
        } else {
            result = l2->val;
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
