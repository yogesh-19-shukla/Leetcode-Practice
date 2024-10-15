class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n!=1){
            int tmp = sumw(n);
            if(st.find(tmp)==st.end()){
                st.insert(tmp);
                n = tmp;
            }
            else return false;
        }
        return true;
    }
    int sumw(int n){
        int sum =0;
        while(n>0){
            int digit = n%10;
            sum = sum + digit*digit;
            n = n/10;
        }
    return sum;
    }
};