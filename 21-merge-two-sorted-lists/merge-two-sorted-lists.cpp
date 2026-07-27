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
    vector<int> array(ListNode* head) {
        vector<int> ans;
        if (head == nullptr)
            return ans;
        while (head != nullptr) {
            ans.push_back(head->val);
            head = head->next;
        }
        return ans;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> one;
        vector<int> two;

        one = array(list1);
        two = array(list2);
        vector<int> ans;
        for (int i = 0; i < one.size(); i++) {
            ans.push_back(one[i]);
        }
        for (int i = 0; i < two.size(); i++) {
            ans.push_back(two[i]);
        }
        if(ans.empty()) return nullptr;
        sort(ans.begin(), ans.end());
        ListNode* head = new ListNode(ans[0]);
        ListNode* current = head;

        for (size_t i = 1; i < ans.size(); i++) {
            current->next = new ListNode(ans[i]);
            current = current->next;
        }

        return head;
    }
};