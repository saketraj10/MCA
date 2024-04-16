class OddThread extends Thread
{
    public void run()
    {
        System.out.println("Odd numbers: ");
        for(int i=1; i<=10; i+=2)
        {
            System.out.println(i);
        }
    }
}
class EvenThread extends Thread
{
    public void run()
    {
        System.out.println("Even numbers: ");
        for(int i=2; i<=10; i+=2)
        {
            System.out.println(i);
        }
    }
}
public class EvenandOdd {
    public static void main(String[] args) {
        OddThread t1 = new OddThread();
        EvenThread t2 = new EvenThread();
        t1.start();
        t2.start();        
    }
}
