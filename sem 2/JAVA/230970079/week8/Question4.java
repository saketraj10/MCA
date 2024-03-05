import java.util.*;
class MatrixSumThread extends Thread{
    private int[] row;
    private int sum;

    MatrixSumThread(int[] row){
        this.row = row;
        this.sum = 0;
    }
    int getSum(){
        return sum;
    }

    public void run(){
        for(int num : row){
            sum += num;
        }
    }
}
class Question4 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = 3;
        int[][] matrix = new int[n][n];
        System.out.println("Enter the value of square matrix of " + n + " size: ");
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = s.nextInt();
            }
        }

        MatrixSumThread[] threads = new MatrixSumThread[n];

        for(int i=0; i<matrix.length; i++){
            threads[i] = new MatrixSumThread(matrix[i]);
            threads[i].start();
        }

        int totalSum = 0;
        for(MatrixSumThread thread : threads){
            try{
                thread.join();
                totalSum += thread.getSum();
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
        }

        System.out.println("Sum of all elements: " + totalSum);
        s.close();
    }
}
