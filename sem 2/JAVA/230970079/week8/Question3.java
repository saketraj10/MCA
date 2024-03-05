import java.util.*;
class SquaresThread extends Thread
{
    private int n;
    SquaresThread(int n)
    {
        this.n = n;
    }
    public void run(){
        for(int i=1; i<=n; i++){
            System.out.println("Square of " + i + " is " + (i*i));
        }
    }
}

class CubesThread extends Thread 
{
    private int n;
    CubesThread(int n){
        this.n = n;
    }
    public void run(){
        for(int i=1; i<=n; i++){
            System.out.println("Cube of " + i + " is " + (i*i*i));
        }
    }
}
class Question3 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        int n = s.nextInt();
        SquaresThread s1 = new SquaresThread(n);
        CubesThread c1 = new CubesThread(n);
        s1.start();
        c1.start();

        s.close();
    }
}