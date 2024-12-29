class Solution {
public:
    
    bool fun(vector<int> &ranks, int cars, long long time) {
        
        for(int it: ranks) {
            int car = floor(sqrt(time / it));
            if(car >= cars) return true;
            cars -= car;
        }
        
        return cars == 0;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        
        long long low = 1, high = 1e15;
        long long ans = -1;
        
        while(low <= high) {
            
            long long mid = low + (high - low) / 2;
            
          //  cout << mid <<"\n";
            if(fun(ranks, cars, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return ans;
    }
};