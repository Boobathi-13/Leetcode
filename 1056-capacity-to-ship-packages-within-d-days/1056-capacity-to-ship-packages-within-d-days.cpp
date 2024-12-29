class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
    int start = *max_element(weights.begin(), weights.end());
    int end = accumulate(weights.begin(), weights.end(), 0);
    int ans = end;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int dayCount = 1, currentWeight = 0;

        for (int weight : weights) {
            if (currentWeight + weight > mid) {
                dayCount++;
                currentWeight = 0;
            }
            currentWeight += weight;
        }

        if (dayCount <= days) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

};