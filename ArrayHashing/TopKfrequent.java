package ArrayHashing;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class TopKfrequent {
    public int[] topKFrequent(int[] nums, int k) {
        int[] arr = new int[k];
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums) map.put(num, map.getOrDefault(num, 0) + 1);
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(
                (a, b) ->
            a.getValue() - b.getValue()
        );
        for (Map.Entry<Integer, Integer> it : map.entrySet()) {
            pq.add(it);
            if (pq.size() > k) pq.poll();
        }
        int i = k;
        while (!pq.isEmpty()) {
            arr[--i] = pq.poll().getKey();
        }
        return arr;
    }

    public int[] topKFrequent2(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        List<List<Integer>> bucket = new ArrayList<>(nums.length + 1);

        for (int num : nums)
            count.put(num, count.getOrDefault(num, 0) + 1);

        for (int i = 0; i < nums.length + 1; i++) {
            bucket.add(new ArrayList<>());
        }

        for (int key : count.keySet()) {
            int freq = count.get(key);

            bucket.get(freq).add(key);
        }

        int index = 0;
        int[] res = new int[k];
        for (int i = nums.length; i >= 0; i--)
            if (bucket.get(i) != null)
                for (int val : bucket.get(i)) {
                    res[index++] = val;
                    if (index == k)
                        return res;
                }
        return res;
    }
}
