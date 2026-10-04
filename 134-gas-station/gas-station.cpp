class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=accumulate(gas.begin(),gas.end(),0);
        int total_cost=accumulate(cost.begin(),cost.end(),0);

        if(total_gas<total_cost) return -1;
        
        int start=0;
        int currGas=0;
        for(int i=0;i<n;i++) {
            currGas+=(gas[i]-cost[i]);
            if(currGas<0) {
                currGas=0;
                start=i+1;
            }
        }

        return start;
    }
};