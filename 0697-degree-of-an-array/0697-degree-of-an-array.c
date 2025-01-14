// Helper structure to store frequency, first and last occurrence
typedef struct {
    int frequency;
    int firstIndex;
    int lastIndex;
} ElementInfo;

int findShortestSubArray(int* nums, int numsSize) {
    ElementInfo map[50000] = {0}; // Assuming nums[i] is between 0 and 49,999
    int degree = 0;
    int minLength = INT_MAX;

    // Traverse the array to populate the map
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];

        if (map[num].frequency == 0) {
            map[num].firstIndex = i;
        }

        map[num].lastIndex = i;
        map[num].frequency++;

        if (map[num].frequency > degree) {
            degree = map[num].frequency;
        }
    }

    // Find the smallest subarray length with the same degree
    for (int i = 0; i < 50000; i++) {
        if (map[i].frequency == degree) {
            int length = map[i].lastIndex - map[i].firstIndex + 1;
            if (length < minLength) {
                minLength = length;
            }
        }
    }

    return minLength;
}