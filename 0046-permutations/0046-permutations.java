class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();
        f(ans,tmp,nums);
        return ans;
    }

    void f(List<List<Integer>> ans,List<Integer> tmp,int[] nums)
    {
        if(tmp.size() == nums.length)
        {
            ans.add(new ArrayList<>(tmp));
            return;
        }
        for(int num: nums)
        {
            if(tmp.contains(num))  continue;
            tmp.add(num);
            f(ans,tmp,nums);
            tmp.remove(tmp.size()-1);
        }
    }
}