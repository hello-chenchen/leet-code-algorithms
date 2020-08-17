function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val);
    this.next = (next===undefined ? null : next);
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
    if(undefined == head) return head;
    var result = new ListNode(head.val, undefined);
    var temp = result.val;
    var temp1 = result;
    while(undefined != head.next) {
        // console.log(head.next.val + " " + temp);
        if(temp != head.next.val) {
            result.next = new ListNode(head.next.val, undefined);
            result = result.next;
            // console.log(temp1);
            temp = head.next.val;
        }
        head.next = head.next.next;
    }

    return temp1;
};