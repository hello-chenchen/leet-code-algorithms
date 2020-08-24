/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    if(undefined == headA || undefined == headB) return null;
    let tempA = headA;
    let tempB = headB;
    while(tempA != tempB && !(undefined == tempA.next && undefined == tempB.next)) {
        tempA = undefined == tempA.next ? headB : tempA.next;
        tempB = undefined == tempB.next ? headA : tempB.next;
    }

    if(tempA == tempB) return tempA;

    return null;
};