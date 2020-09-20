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
var middleNode = function(head) {
    let low = head, fast = undefined == head ? {} : head;
    while(undefined != fast.next) {
        fast = undefined != fast.next.next ? fast.next.next : fast.next;
        low = low.next;
    }

    return low;
};