class MyThread extends Thread
{
    int Thread_num;
    MyThread(int num)
    {
        Thread_num = num;
        start();
    }
    public void run()
    {
        for(int i=0; i<5; i++)
        {
            System.out.println("Thread-"+Thread_num + ", i=" + i);
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException e) {}
        }
    }
}
public class MultiThread_Demo3 {
    public static void main(String[] args) {
        MyThread t1 = new MyThread(1);
        MyThread t2 = new MyThread(2);
        MyThread t3 = new MyThread(3);
        for(int i=0; i<5; i++)
        {
            System.out.println(" Main Thread ");
            try
            {
                Thread.sleep(2000);
            }
            catch(Exception e) { }
        }
    }
}