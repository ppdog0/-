#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode;
    ListNode *init = ans;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            ans->next = l1;
            l1 = l1->next;
        }
        else
        {
            ans->next = l2;
            l2 = l2->next;
        }
        ans = ans->next;
    }
    ans->next = l1 ? l1 : l2;
    return init->next;
}

int main() {
    ListNode *l1, *l2;
    l1 = new ListNode(1);
    l2 = new ListNode(1);
    ListNode *l3, *l4;
    l3 = new ListNode(2);
    l4 = new ListNode(3);
    ListNode *l5, *l6;
    l5 = new ListNode(4);
    l6 = new ListNode(4);

    l1->next = l3;
    l3->next = l5;
    l2->next = l4;
    l4->next = l6;
    ListNode* ans = mergeTwoLists(l1, l2);

    while(ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
}