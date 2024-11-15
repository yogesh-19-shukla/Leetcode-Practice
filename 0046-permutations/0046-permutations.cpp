
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(ans, tmp, nums);
        return ans;
    }

private:
    void backtrack(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int num : nums) {
            if (find(tmp.begin(), tmp.end(), num) != tmp.end()) continue;
            tmp.push_back(num);
            backtrack(ans, tmp, nums);
            tmp.pop_back();
        }
    }
};
