class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>>mp;
        for(auto it : strs){
            string key = getkey(it);
            mp[key].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }

    string getkey(string s){
        int count[26] = {0};
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
        }
        string key = "";
        for(int i=0;i<26;i++){
            key.append(to_string(count[i]) + "#");
        }
        return key;
    }
};