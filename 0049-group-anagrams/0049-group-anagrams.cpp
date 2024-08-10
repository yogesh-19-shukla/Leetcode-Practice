class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            string key = getkey(strs[i]);
            mp[key].push_back(strs[i]);
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }

    string getkey(string s){
        int count[26] = {0};
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        string key = "";
        for(int i=0;i<26;i++){
            key.append(to_string(count[i]) + "&");
        }
        return key;
    }
};