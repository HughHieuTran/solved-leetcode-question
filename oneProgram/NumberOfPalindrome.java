package oneProgram;

public class NumberOfPalindrome {
    public static void main(String[] args) {
        String s = "abc";
        System.out.println(countSubstrings(s));
    }

    public static int countSubstrings(String s) {
        if (s == null || s.length() < 1) return 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count = expandAroundCenter(s, i, i,count);
            count = expandAroundCenter(s, i, i + 1,count);
        }
        return count;
    }

    private static int expandAroundCenter(String s, int left, int right,int count) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
            count++;
            L--;
            R++;
        }
        return count ;
    }
}