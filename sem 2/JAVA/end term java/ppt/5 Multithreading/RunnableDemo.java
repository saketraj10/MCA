class MyThread implements Runnable
{
    public void run()
    {
        System.out.println("child thread is starting.");
        for(int count=0; count<10; count++)
        {
            System.out.println("In child thread, count is " + count);
            try
            {
                Thread.sleep(400);
            }
            catch(InterruptedException exc)
            { }
        }
        System.out.println("child thread is terminating..");
    }
}
public class RunnableDemo {
    public static void main(String[] args) {
        MyThread mt = new MyThread();
        Thread newThrd =new Thread(mt);

        newThrd.start();
        for(int i=0; i<5; i++)
        {
            System.out.println("In Main thread..");
            try{
                Thread.sleep(1000);
            }
            catch(InterruptedException exc){}
        }
        System.out.println("Main thread ending.");
    }
}

