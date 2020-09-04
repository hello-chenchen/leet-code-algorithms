/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if(null == head) return head;
    var result = new ListNode();
    result.val = head.val;
    while(null != head.next) {
        result = new ListNode(head.next.val, result);
        head = head.next;
    }

    return result;
};