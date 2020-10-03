class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_index;
        vector<int> output(2, 0);
        for(int i = 0; i < nums.size(); ++i) {
            if (value_index.find(nums[i]) != value_index.end()) {
                output[0] = value_index[nums[i]];
                output[1] = i;
                return output;
            }
            value_index[target - nums[i]] = i;
        }
        return output; 
    }
};
