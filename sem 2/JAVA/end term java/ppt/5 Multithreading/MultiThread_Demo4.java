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
        System.out.println("Thread-"+Thread_num);
    }
}
public class MultiThread_Demo4 {
    public static void main(String[] args) {
        MyThread t1 = new MyThread(1);
        MyThread t2 = new MyThread(2);
        Thread main_thread = Thread.currentThread();

        System.out.println("t1 is alive = " + t1.isAlive());
        System.out.println("t2 is alive = " + t2.isAlive());
        System.out.println("main is alive = " + main_thread.isAlive());
    }
}
