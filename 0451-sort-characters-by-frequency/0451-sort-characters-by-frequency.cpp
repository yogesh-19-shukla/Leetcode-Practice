class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto it: s){
            mp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        string res;
        for(auto element:mp){
            pq.push({element.second,element.first});
        }
        while(!pq.empty()){
            auto el = pq.top();
            pq.pop();
            res.append(el.first,el.second);
        }
        return res;
    }
};