class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output; 
        if (nums.size() < 4) return output;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-3; ++i) {
            //if (nums[i] > target) return output;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size()-2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j + 1;
                int l = nums.size() - 1;
                int diff = target - (nums[i] + nums[j]);
                while (k < l) {
                    if (2*nums[k] > diff) break;
                    if (2*nums[l] < diff) break;
                    int sum = nums[k] + nums[l];
                    if (sum == diff) {
                        output.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k < l && nums[k] == nums[k+1]) k++;
                        while(k < l && nums[l] == nums[l-1]) l--;
                        k++;
                        l--;
                    }
                    if (sum < diff) k++;
                    if (sum > diff) l--;
                }
            }
        }
        return output;
    }
};
