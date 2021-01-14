#include<iostream>
#include<vector>
#include<queue>

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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int size = lists.size();
    if (size == 0)
        return nullptr;
    if (size == 1)
        return lists[0];
    queue<ListNode *> waiting(deque<ListNode *>(lists.begin(), lists.end()));
    while (1 < waiting.size())
    {
        ListNode *l1 = waiting.front();
        waiting.pop();
        ListNode *l2 = waiting.front();
        waiting.pop();
        waiting.push(mergeTwoLists(l1, l2));
    }
    return waiting.front();
}

int main() {}