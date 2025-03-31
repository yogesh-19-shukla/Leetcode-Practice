class Solution {
public:
    int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxProd = nums[0], minProd = nums[0], globalMax = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) 
            swap(maxProd, minProd); // Swap because multiplying by a negative flips max/min

        maxProd = max(nums[i], nums[i] * maxProd);
        minProd = min(nums[i], nums[i] * minProd);

        globalMax = max(globalMax, maxProd);
    }

    return globalMax;
}
};