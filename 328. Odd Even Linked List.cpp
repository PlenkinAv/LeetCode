//https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* makeOne(ListNode* pool, int length)
        {
            if (length)
            {
                ListNode *a, *iter, *iter2;
                a = new ListNode(pool->val);
                iter = a->next;
                iter2 = a;
                for (int i=1; i<length; i++)
                {
                    pool = pool->next->next;
                    iter = new ListNode(pool->val);
                    iter2->next = iter;
                    iter2 = iter2->next;
                    iter = iter->next;
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
    
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {return NULL;} else
        {
            ListNode *odd, *even, *iter;
            int count = howMany(head);
            int ost = count % 2;
            count -= ost;
            odd = makeOne(head, count/2 + ost);
            even = makeOne(head->next, count - count/2);

            iter = odd;
            while (iter->next != NULL)
            {
                iter = iter->next;
            }
            iter->next = even;

            return odd;
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().oddEvenList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
