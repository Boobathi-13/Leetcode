class Solution {
    public int maxSum(List<Integer> nums, int k) {
        long mod=1000000007;
        long result=0;
        int countBits[]=new int[32];    //counting bits at every position
        for(int i=0;i<nums.size();i++){//TC : 32*no.of elements
            for(int j=0;j<32;j++){
                if((nums.get(i) & (1<<j)) !=0)  //jth bit is set or not
                    countBits[j]++;
            }
        }
//we have count[] array that keeps tracks of no of sets bits at each position in the whole array
long cur=0;
        for(int i=0;i<k;i++){//K elements
         cur=0;
            for(int j=0;j<32;j++){  //32 bits
                if(countBits[j]>0)  //no of set bits at jth index is >0
                {
                    countBits[j]--;
                    cur +=(1<<j);    //jth time left shift
                }
            }
            result=(result + cur*cur%mod)%mod;
        }
        return (int)result;
    }
}
//Dry run on Sample input

/*nums = [2,6,5,8], k = 2
binary representation of i/p
Bit pos: 3 2 1 0  
         0 0 1 0 -> 2
         0 1 1 0 -> 6
         0 1 0 1 -> 5
         1 0 0 0 -> 8
----------------------
BitCount:1 2 2 1

index    :  0   1   2   3   4   5 .....     30  31  32
countBits:  1   2   2   1   0   0           0   0   0

res=0;
cur=0;  

for i=0 -> i<k
for(j=0;j<32;j++)
index    :  0   1   2   3   4   5 .....     30  31  32
countBits:  0   1   1   0   0   0           0   0   0
cur      :  1 + 2 + 4 + 8 + 0 + ......               -> 15
result-> 15*15 =225

for i=1 -> i<k=2
for(j=0;j<32;j++)
index    :  0   1   2   3   4   5 .....     30  31  32
countBits:  0   0   0   0   0   0           0   0   0
cur      :  0 + 2 + 4 + 0 + 0 + .......             -> 6
result->225+ 6*6 =261

result =261 */