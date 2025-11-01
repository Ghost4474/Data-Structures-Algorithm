class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int size=0;
        while (temp!=nullptr){
            size++;
            temp=temp->next;
        }
        if (n==1 && size==1) return head->next;
        if (n==size){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp=head;
        for (int i=0;i<size-n-1;i++){
            temp=temp->next;
        }
        ListNode* res=temp->next;
        temp->next=temp->next->next;
        delete res;
        return head;
    }
};