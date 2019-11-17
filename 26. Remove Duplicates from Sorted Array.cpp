//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {return 0;} else {
            if (nums.size() == 1) {return 1;} else {
                int i = 0;
                int j = 1;
                bool dif;
                while (i < nums.size() && j < nums.size()){
                    dif = (nums[i] != nums[j]);
                    while (!dif && j<nums.size())
                        if (nums[i] == nums[j]) {
                            j++;
                        } else {
                            dif = true;
                        }
                    if (dif) {
                        for (int k = i+1; k<j; k++)
                            nums[k] = nums[j];
                        i++;
                        j = i+1;  
                    }
                }
                return i+1;
            }
        }
    }       
};