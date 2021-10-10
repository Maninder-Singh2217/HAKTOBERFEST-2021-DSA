#include<bits/stdc++.h>
using namespace std;

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

ListNode* start=NULL;
ListNode* reverse(ListNode* head) 
{
    if(!head)
    return head;
        
    if(head->next)
    {
        ListNode* node = reverse(head->next);
        node->next=head;
        node=head;
        head->next=NULL;
        return node;
    }
    start=head;
    return head;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head)
         return head;
          
         start=NULL;
         reverse(head);
         return start;
    }
};