/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {

        ListNode ans=new ListNode();
        ans.next=head;
        ListNode temp=ans;
        while(temp!=null){
            ListNode curr=temp.next;
             int sum=0;
            while(curr!=null){

                sum+=curr.val;
                if(sum==0){
                    temp.next = curr.next;
                    
                }
                curr = curr.next;
            }
            temp = temp.next;
        }
        return ans.next;
    }

}