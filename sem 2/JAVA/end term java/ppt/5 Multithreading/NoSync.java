class SumArray
{
    private int sum;
    int sumArray(int[] nums)
    {
        sum =0;
        for(int i=0; i<nums.length; i++)
        {
            sum += nums[i];
            System.out.println("Running total for " + Thread.currentThread().getName() + " is " + sum);
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException exc)
            {
                System.out.println("Thread interrupted.");
            }
        }
        return sum;
    }
}
class MyThread extends Thread
{
    static SumArray sa = new SumArray();
    int[] a;
    int answer;
    MyThread(String name, int[] nums)
    {
        a = nums;
        setName(name);
        start();
    }
    public void run()
    {
        int sum;
        System.out.println(getName() + " starting.");
        answer = sa.sumArray(a);
        System.out.println("Sum for " + getName() + " is " + answer);
        System.out.println(getName() + " terminating.");
    }
}
public class NoSync {
    public static void main(String[] args) {
        int[] a = {1,2,3,4,5};
        int[] b = {10,20,30,40,50};

        MyThread mt1 = new MyThread("Child #1", a);
        MyThread mt2 = new MyThread("Child #2", b);

        try
        {
            mt1.join();
            mt2.join();
        }
        catch(InterruptedException exc)
        {
            System.out.println("Main thread interrupted.");
        }
    }
}
