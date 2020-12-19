// Time: O(n)
// Space: O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num_1 = 0;
        int k_1 = 0;
        
        // Duyệt từng bit
        for (int i=0; i<32; i++){
            int sum = 0;
            for (int n : nums){
                if ((n >> i) & 1){
                    sum++;
                }
            }
            
            // Dừng khi gặp bit của số đầu tiên
            if (sum % 2 != 0){
                k_1 = i;
                break;
            }
        }

        // Tìm các số có bit 1 ơ vị trí k_1  
        for (int i=0; i<nums.size(); i++){
            if ((nums[i] >> k_1) & 1){
                num_1 ^= nums[i];   // Xor để tìm num_1
            }
        }
        
        int num_2 = 0;

        for (int n : nums){
            num_2 ^= n;
        }

        // Xor num_1 để tìm num_2 (vì num_2 lúc này bằng num_1^num_2)
        num_2 ^= num_1;

        return {num_1, num_2};

    }
};