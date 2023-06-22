package twoDProgram;

public class LongestSubsequence {
    public static void main(String[] args) {
        String text1 = "abcde";
        String text2 = "ace";
        System.out.println(longestCommonSubsequence(text1, text2));
    }

    public static int longestCommonSubsequence(String text1, String text2) {
        if (text1.isEmpty() || text2.isEmpty()) {
            return 0;
        }
        int[][] matrix = new int[text1.length() + 1][text2.length() + 1];

        for (int i = 0; i < text2.length() + 1; i++) {
            matrix[text1.length()][i] = 0;
        }

        for (int i = 0; i < text1.length() + 1; i++) {
            matrix[i][text2.length()] = 0;
        }

        for (int i = text1.length() - 1; i >= 0; i--) {
            for (int j = text2.length() - 1; j >= 0; j--) {
                if (text1.charAt(i) == text2.charAt(j)) {
                    matrix[i][j] = matrix[i + 1][j + 1] + 1;
                } else {
                    matrix[i][j] = Math.max(matrix[i + 1][j], matrix[i][j + 1]);
                }
            }
        }

        for (int i =0; i < text1.length(); i++) {
            for (int j = 0; j<text2.length(); j++) {
                System.out.print(matrix[i][j]);
            }
            System.out.println();
        }
        

        return matrix[0][0];
    }
}
