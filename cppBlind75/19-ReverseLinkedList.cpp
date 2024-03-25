/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

int main()
{
    ListNode head(1);
    ListNode second(2);
    ListNode third(3);
    head.next = &second;
    second.next = &third;

    ListNode *headptr = &head;
    Solution so;
    headptr = so.reverseList(headptr);
    
    while (headptr != nullptr)
    {
        cout << headptr->val << endl;
        headptr = headptr->next;
    }
}