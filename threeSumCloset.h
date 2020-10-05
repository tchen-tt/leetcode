class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int presum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            int sum;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(target - presum)) presum = sum; 
                if (sum == target) return target;
                if (sum < target) j++;
                if (sum > target) k--;
            }   
        }
        return presum;
    }
};
