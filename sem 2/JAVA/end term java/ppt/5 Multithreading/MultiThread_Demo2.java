class MyThread extends Thread
{
    String thrdName;
    MyThread(String name)
    {
        thrdName = name;
        this.start();
    }
    public void run()
    {
        System.out.println(thrdName + " starting.");
        for(int count=0; count<5; count++)
        {
            System.out.println("In " + thrdName + ", count is " + count);
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException exc)
            { }
        }
        System.out.println(thrdName + " terminating.");
    }
}
public class MultiThread_Demo2 {
    public static void main(String[] args) {
        System.out.println("Main thread starting.");
        MyThread m1 = new MyThread("Child #1");
        for(int i=0; i<10; i++)
        {
            System.out.println("In main thread..count=" + i);
            try
            {
                Thread.sleep(2000);
            }
            catch(InterruptedException exc)
            { }
        }
        System.out.println("Main thread ending");
    }
}
