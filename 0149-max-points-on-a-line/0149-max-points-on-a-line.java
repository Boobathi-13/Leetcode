class Solution {
    public int gcd(int a,int b){
        if(a==0){
            return b;
        }
        return gcd(b%a,a);
    }
    
    public int maxPoints(int[][] points) {
        int res=0,n=points.length;
        // if we have less or equal 2 points then we can only have one line(two point) or one/zero point
        if (points.length<=2) return points.length;

        for(int i=0;i<n;i++){

            HashMap<String,Integer> slopCount=new HashMap<>();
            //same x cordinates or same y cordinates
            int duplicate = 0;
            //max
            int  max= 0;

            for(int j=i+1;j<n;j++){
                int x=points[j][0]-points[i][0];
                int y=points[j][1]-points[i][1];
                //if both point are same the that are on same line
                if (x==0&&y==0){
        			duplicate++;
        			continue;
        		}
                //if slop is new then for that line one point added
                //if slop already exist then the new point will be on that line
                int g=gcd(x,y);
                int dx=x/g;
                int dy=y/g;
                String s=dx+"/"+dy; 
                
                slopCount.put(s,slopCount.getOrDefault(s,0)+1);

                max=Math.max(max,slopCount.get(s));
            }
            // slop+duplicate points+1 for point it self
            res=Math.max(max+duplicate+1,res);
        }
        
        return res;

    }
}