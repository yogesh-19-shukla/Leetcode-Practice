class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>res;
        string prevword = "";
        for(auto word: words){
            string sortedword = word;
            sort(sortedword.begin(),sortedword.end());
            if(prevword!=sortedword){
                res.push_back(word);
                prevword = sortedword;
            } 
        }
        return res;
    }
};