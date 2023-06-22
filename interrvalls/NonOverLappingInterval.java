package interrvalls;

import java.util.Arrays;

public class NonOverLappingInterval {
    public static void main(String[] args) {
        //int[][]  nums = {{1,2},{2,3},{3,4},{1,3}};
        int[][]  nums = {{1,2},{1,2},{1,2}};
        System.out.println(eraseOverlapIntervals(nums));

    }

    public static int eraseOverlapIntervals(int[][] intervals) {
        int count = 0;
        Arrays.sort(intervals, (a,b)-> Integer.compare(a[0], b[0]));

        for(int i =0; i < intervals.length -1; i++){
            if(intervals[i][1] > intervals[i+1][0]){
                count++;
                intervals[i+1][1] = Math.min(intervals[i][1], intervals[i+1][1]);
                
            }
        }
     
        return count;   
    }
}
