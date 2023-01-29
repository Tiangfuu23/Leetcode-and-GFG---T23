/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // mergesort - divide and conquer strategy
 // time O(nlogk) where k is no of linked list
class Solution {
public:
    ListNode* merge(ListNode* first, ListNode* second){
           ListNode* dummy_head = new ListNode;
           ListNode* tail = dummy_head;
           while(first != NULL && second != NULL){
               if(first->val < second->val){
                   tail->next = first;
                   first = first->next;
               }else{
                   tail->next = second;
                   second = second->next;
               }
               tail = tail->next;
           }
        if(first != NULL) tail->next = first;
        if(second != NULL) tail->next = second;
        return dummy_head->next;
    }
    ListNode* mergeSort(vector<ListNode*>& lists, int l, int r){
        if(l==r) return lists[l];
        int mid = l + (r-l)/2;
        ListNode* first = mergeSort(lists,l,mid);
        ListNode* second = mergeSort(lists,mid+1,r);
        return merge(first,second);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.size() == 0) return NULL;
       return mergeSort(lists,0,lists.size()-1);
    }
};