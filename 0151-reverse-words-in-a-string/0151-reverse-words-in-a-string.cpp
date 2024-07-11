class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int left = 0;
        int right = n-1;
        string temp = "";
        string ans = "";
        while(left<=right)
        {
            char ch = s[left];
            if(ch!=' '){
               temp += ch;
            }
            else{
                if(ans!="")  ans = temp +(temp==""?"":" ") + ans;
                else ans = temp;
                temp = "";
                
            }
            left++;
        }
        // last word
        if(temp!=""){
            if(ans!="")  ans = temp + " " + ans;
            else ans = temp;
        }
        return ans;
    }
};