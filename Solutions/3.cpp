class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num_1 = 0;
        int k_1 = 0;
        
        for (int i=0; i<32; i++){
            int sum = 0;
            for (int n : nums){
                if ((n >> i) & 1){
                    sum++;
                }
            }
            
            if (sum % 2 != 0){
                k_1 = i;
                break;
            }
        }
    
        vector <int> vec;

        for (int i=0; i<nums.size(); i++){
            if ((nums[i] >> k_1) & 1){
                vec.push_back(nums[i]);
            }
        }

        for (int v : vec){
            num_1 ^= v;
        }

        int num_2 = 0;

        for (int n : nums){
            num_2 ^= n;
        }

        num_2 ^= num_1;

        vector <int> res;
        res.push_back(num_1);
        res.push_back(num_2);

        return res;

    }
};