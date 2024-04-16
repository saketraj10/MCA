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
        System.out.println("Thread-" + Thread_num + ", priority = " + getPriority());
    }
}
public class MultiThread_Demo6 {
    public static void main(String[] args) {
        MyThread t1 = new MyThread(1);
        MyThread t2 = new MyThread(2);
        Thread main_thread = Thread.currentThread();
        System.out.println("Mainthread,priority = " + main_thread.getPriority());
    }
}
