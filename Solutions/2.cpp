// Time: O(n)
// Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int er = 0;
        
        // Duyệt từng bit
        for (int i=0; i<32; i++){
            int sum = 0;
            
            for (int j=0; j<nums.size(); j++){
                if (((nums[j] >> i) & 1) != 0){
                    sum++;
                }
            }
            
            // Nếu là bit của số xuất hiện 1 lần thì thêm vào er
            if (sum % 3 == 1){
                er |= (1 << i);
            }
        }
        
        return er;
    }
};