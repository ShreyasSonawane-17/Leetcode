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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = arr.size() - 1;

        queue<int> q;

        while (i <= j) {
            q.push(arr[i]);

            if (i != j) {
                q.push(arr[j]);
            }

            i++;
            j--;
        }

        temp = head;

        while (!q.empty()) {
            temp->val = q.front();
            q.pop();
            temp = temp->next;
        }
    }
    };