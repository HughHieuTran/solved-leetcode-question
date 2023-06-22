package oneProgram;

import java.util.Arrays;

public class LoongestSubsequence {
    public static void main(String[] args) {
        int[] nums = { 10, 9, 2, 5, 3, 7, 101, 18 };

        System.out.println(lengthOfLIS(nums));
    }

    public static int lengthOfLIS(int[] nums) {
        if (nums.length == 1)
            return 1;
        int[] LTS = new int[nums.length];
        int max = 1;
        Arrays.fill(LTS, 1);

        for (int i = nums.length - 1; i >= 0; i--) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] < nums[j]) {
                    LTS[i] = Math.max(LTS[i], LTS[j] + 1);
                }
            }
            max = Math.max(max, LTS[i]);
        }

        return max;

    }
}
