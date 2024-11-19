class Solution {
    public String toHex(int num) {
        int[] bitRep = getBinaryRepresentation(num);

        StringBuilder sb = new StringBuilder();
        for(int i =0; i < 32; i+= 4) {
            int no = 8*bitRep[i] + 4*bitRep[i+1] + 2*bitRep[i+2] + bitRep[i+3];

            if(no == 0) {
                if(!sb.isEmpty()) {
                    sb.append(no);
                }
            } else if(no >=10) {
                sb.append((char)('a' + (no - 10)));
            } else {
                sb.append(no);
            }
        }

        return sb.isEmpty() ? "0" : sb.toString();
    }

    int[] getBinaryRepresentation(int num) {
        // By default, the number is already saved in two complement method
        //In java
        int[] bitRep = new int[32];

        for(int i = 31; i >=0; i--) {
            bitRep[i] = num & 1 ; 
            num >>= 1;
        }

        return bitRep;
    }
}