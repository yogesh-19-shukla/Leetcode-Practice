class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0;
        int n = people.size();
        int i=0, j=n-1;
        sort(people.begin(),people.end());
        while(i<=j){
            int sum = people[i] + people[j];
            if(sum<=limit){
                i++;
                j--;
                cnt++;
            }else{
                j--;
                cnt++;
            }

        }
        return cnt;
    }
};