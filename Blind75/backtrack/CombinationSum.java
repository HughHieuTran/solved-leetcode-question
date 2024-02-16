package backtrack;

import java.util.ArrayList;
import java.util.List;

public class CombinationSum {
    public static void main(String[] args) {
        int[] arr = {2,3,6,7};
        System.out.println(combinationsSum(arr,7));
    }

    public static List<List<Integer>> combinationsSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();

        backttrack(candidates, target, ans, cur, 0);

        return ans;
    }

    public static void backttrack(int[] candidates, int target, List<List<Integer>> ans, List<Integer> cur, int index) {
        if (target == 0) {
            ans.add(new ArrayList<>(cur));
        } else if (target < 0 || index >= candidates.length) {
            return;
        } else{
            cur.add(candidates[index]);
            backttrack(candidates, target - candidates[index], ans, cur, index);
            cur.remove(cur.size()-1);
            backttrack(candidates, target, ans, cur, index + 1);
            
        }
    }
}
