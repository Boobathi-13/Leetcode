class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1; 
        for(auto x:piles) right = max(x,right);
        while(left<right){
            int mid = (right+left)/2;
            int val = 0;
            for(auto x:piles){
                val += x/mid;
                if(x%mid) val++;
            }

            cout<<" | "<<mid;

            cout<<" - "<<val;

            cout<< "\n"<< "Left:" << left<< "\n";
            cout<< "\n"<< "Right:" << right<< "\n";
        
        
                if(val<=h) right = mid;
            else left = mid+1;
        }
        return left;
    }
};