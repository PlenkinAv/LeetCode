//https://leetcode.com/problems/split-linked-list-in-parts/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* makeOne(ListNode* &pool, int length)
        {
            if (length)
            {
                ListNode *a, *iter, *iter2;
                a = new ListNode(pool->val);
                iter = a->next;
                iter2 = a;
                pool = pool->next;
                for (int i=1; i<length; i++)
                {
                    iter = new ListNode(pool->val);
                    iter2->next = iter;
                    iter2 = iter2->next;
                    iter = iter->next;
                    pool = pool->next;
                }
                return a;
            }
            else
            {
                return NULL;
            }
        }
    
    int howMany(ListNode* root)
    {
        ListNode *iter;
        int count=0;
        iter = root;
        if (iter == NULL) {return 0;} else
        {
            while (iter != NULL)
            {
                iter = iter->next;
                count++;
            }
        }
        return count;
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {        
        vector<ListNode*> ans(k, NULL);
        int count = howMany(root), left= count;
        int complete = (count % k);
        int uncomplete = (k - complete);
        int inOne = (count / k);
        
        for (int i=0; i<complete; i++)
        {
            ans[i] = makeOne(root, inOne+1);
        }
        
        for (int i=0; i<uncomplete; i++)
        {
            ans[i+complete] = makeOne(root, inOne);
        }
        return ans;
        
    }
};