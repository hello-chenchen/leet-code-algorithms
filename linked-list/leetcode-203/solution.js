/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    // let sentinel = new ListNode(0);
    // sentinel.next = head;

    // let prev = sentinel, curr = head;
    // while (curr != null) {
    //   if (curr.val == val) prev.next = curr.next;
    //   else prev = curr;
    //   curr = curr.next;
    // }
    // return sentinel.next;
    while(null != head && val == head.val) {
        head = head.next;
    }
    if(null == head) return head;

    let temp = head.next;
    let parent = head;
    while(null != temp) {
        if(val == temp.val) {
            parent.next = temp.next;
        } else {
            parent = temp;
        }

        temp = temp.next;
    }

    return head;
};