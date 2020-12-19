// Time: O(n)
// Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int e : nums){
            res ^= e;
        }
        return res;
    }
};