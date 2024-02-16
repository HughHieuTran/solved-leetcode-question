package bittMani;

public class MissinNum {
    public static void main(String[] args) {
        int[] arr = { 3, 0, 1 };

        System.out.println(missingNumber(arr));
    }

    public static int missingNumber(int[] nums) {

        int sum = nums.length;
        
        for (int i = 0; i < nums.length; i++) {
            sum += ( i - nums[i] );
        }
        return  sum;

    }
}
