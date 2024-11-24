class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tg = 0;
        int tc = 0;
        for(int i=0;i<gas.size();i++){
            tg += gas[i];
            tc += cost[i];
        }
        if(tg<tc)  return -1;
        int start = 0;
        int total = 0;
        for(int i=0;i<gas.size();i++){
            total += gas[i] - cost[i];
            if(total<0){
                start = i+1;
                total = 0;
            }
        }
        return start;
    }
};