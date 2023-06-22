package bittMani;

public class CounttBits {
    public static void main(String[] args) {
        int[] res = countBits(5);
        for (int i : res) {
            
            System.out.println(i);
        }
    }

    public static int[] countBits(int n) {
        int[] result = new int[n+1];

        for(int i =0; i<= n; i++){
            result[i] = hammingWeight(i);
        }

        return result;
    }

    public static int hammingWeight(int n) {
        int count = 0;
        int mask = 1;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) != 0) {
                count++;
            }
            n >>= 1;
        }
        return count;
    }
}
