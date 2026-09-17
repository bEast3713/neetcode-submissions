class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int,int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        for (auto& [num, count] : mpp) {
            buckets[count].push_back(num);
        }
        vector<int> ans;
        for (int i = nums.size(); i >= 0 && ans.size() < k; i--) {
            for (int num : buckets[i]) {
                if (ans.size() == k) break;
                ans.push_back(num);
            }
        }
        return ans;
    }
};