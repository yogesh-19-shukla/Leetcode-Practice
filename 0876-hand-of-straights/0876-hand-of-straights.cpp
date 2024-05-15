/*
make a map with {cardval -> count}. Loop through map see if value present and group can be made
if not return false else reduce count and check again while map is not empty.

Time: O(n log n)
    Space: O(n)
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0)  return false;
        map<int,int> mp;
        for(auto i : hand){
            mp[i]++;
        }
        while(!mp.empty()){
            int curr = mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp[curr+i]==0)  return false;
                mp[curr+i]--;
                if(mp[curr+i]<1)  mp.erase(curr+i);
            }
        }
        return true;
    }
};