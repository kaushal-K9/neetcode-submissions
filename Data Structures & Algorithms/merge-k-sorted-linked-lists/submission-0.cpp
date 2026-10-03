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
class Solution {
public: 
    //bring in two sorted linked lists and merge them
    //recursively
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    ListNode* partitionAndMerge(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return NULL;

        if (start == end) return lists[start];

        int mid = start + (end - start) / 2;

        ListNode* L1 = partitionAndMerge(lists, start, mid);
        ListNode* L2 = partitionAndMerge(lists, mid + 1, end);

        return mergeTwoLists(L1, L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        return partitionAndMerge(lists, 0, n - 1);
    }
};