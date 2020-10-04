class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        if (nums.size() < 3) return output;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            if (nums[i] > 0) return output;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    output.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
                if (sum < 0) j++;
                if (sum > 0) k--;
            }
        }
        return output;
    }
};
