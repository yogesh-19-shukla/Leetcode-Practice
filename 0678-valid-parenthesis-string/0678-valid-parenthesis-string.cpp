/*
make 2 variables cmin,cmax if '(' increase both 
if ')' decrease both and else min-- , max++;
at any point if max is -ve return false and if min is -ve make it 0
return min == 0 ; 
*/

class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0 , cmax = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')    {
                cmin++;  
                cmax++;
            }
            else if(s[i]==')') {
                cmin--;
                cmax--;
            } 
            else {
                cmin--;
                cmax++;
            }
            if(cmax<0)   return false;
            if(cmin<0)   cmin = 0;
        }
        return cmin == 0;
    }
};