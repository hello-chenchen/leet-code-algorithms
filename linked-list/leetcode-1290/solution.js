/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
var getDecimalValue = function(head) {
    let result = 0;
    while(undefined != head) {
        if(1 == head.val) {
            result = (result << 1) + 1;
        } else {
            result = result << 1;
        }
        head = head.next;
    }

    return result;
};