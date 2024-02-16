package Maath;

public class RotateiImage {
    public static void main(String[] args) {

    }

    public static void rotate(int[][] matrix) {
        int l = 0;
        int r = matrix.length;
        while(l<r){
            for(int i =0; i < r-l; i++){
                int top = l;
                int bottom = r;
                int topleft = matrix[top][l+i];

                matrix[top][l+i] = matrix[bottom][l+i];
                matrix[bottom-i][l] = matrix[bottom][r-i];
                matrix[bottom][r-i] = matrix[top+i][r];
                matrix[top+i][r] = topleft;

            }
            l++;
            r--;
        }
        
    }
}
