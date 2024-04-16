class MyThread implements Runnable
{
    Thread t;
    MyThread()
    {
        t = new Thread(this);
        t.start();
    }
    public void run()
    {
        System.out.println("child thread is starting.");
        for(int count=0; count<10; count++)
        {
            System.out.println("In child thread, count is " + count);
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException exc){}
        }
        System.out.println(" child thread is terminating..");
    }
}
public class RunnableDemoImproved {
    public static void main(String[] args) {
        System.out.println("Main thread starting.");
        MyThread mt = new MyThread();
        for(int i=0; i<5; i++)
        {
            System.out.println("In Main thread..");
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException exc){}
        }
        System.out.println("Main thead ending");
    }
}
