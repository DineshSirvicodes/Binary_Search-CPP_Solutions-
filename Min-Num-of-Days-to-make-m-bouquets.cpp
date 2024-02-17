class Solution {
public:
    bool possible(vector<int> &bloomDay,int day,int m,int k ){
        int cnt = 0;
        int NumofB = 0;
        for(int i = 0 ; i<bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                NumofB += (cnt/k);
                cnt = 0;
            }
        }
        NumofB += (cnt/k);
        return NumofB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        if(val > bloomDay.size()) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        mini = *min_element(bloomDay.begin(),bloomDay.end());
        maxi = *max_element(bloomDay.begin(),bloomDay.end());
        int low = mini, high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
