package bittMani;

public class ReverrseBit {
    public static void main(String[] args) {
        Long n = 0b00000010100101000001111010011100L;
       System.out.println(reverseBits(n));
    }

    public static int reverseBits(Long n) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }
        return ans;
    }
}
