package backtrack;

public class WordSearch {
    public static void main(String[] args) {
        char[][] board = { { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
        System.out.println(exist(board, "ABCCED"));
    }

    public static boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, m, n, 0))
                    return true;
            }
        }
        return false;
    }

    private static boolean dfs(char[][] board, String word, int i, int j, int m, int n, int cur) {
        if (cur >= word.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word.charAt(cur)) {
            return false;
        }
        boolean exist = false;
        if (word.charAt(cur) == board[i][j]) {
            board[i][j] += 100;
            
            exist = dfs(board, word, i + 1, j, m, n, cur + 1) ||
                    dfs(board, word, i, j + 1, m, n, cur + 1) ||
                    dfs(board, word, i - 1, j, m, n, cur + 1) ||
                    dfs(board, word, i, j - 1, m, n, cur + 1);
            board[i][j] -= 100;
        }
        return exist;
    }
}
