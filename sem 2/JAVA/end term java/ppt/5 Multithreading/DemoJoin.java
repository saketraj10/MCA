class Newthread extends Thread
{
    String name;
    Newthread(String threadname)
    {
        name = threadname;
        System.out.println("New thread: " + name);
        start();
    }
    public void run()
    {
        try
        {
            for(int i=5; i>0; i--)
            {
                System.out.println(name + ": " + i);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e)
        {
            System.out.println(name + " interrupted.");
        }
        System.out.println(name + " exiting.");
    }
}
public class DemoJoin {
    public static void main(String[] args) {
        Newthread ob1 = new Newthread("one");
        Newthread ob2 = new Newthread("two");
        Newthread ob3 = new Newthread("three");

        System.out.println("Thead one is alive: " + ob1.isAlive());
        System.out.println("Thead two is alive: " + ob2.isAlive());
        System.out.println("Thead three is alive: " + ob3.isAlive());

        try
        {
            System.out.println("Waiting for threads to finish.");
            ob1.join();
            ob2.join();
            ob3.join();
        }
        catch(InterruptedException e)
        {
            System.out.println("Main thread Interruptec");
        }

        System.out.println("Thread one is alive: " + ob1.isAlive());
        System.out.println("Thread two is alive: " + ob2.isAlive());
        System.out.println("Thread three is alive: " + ob3.isAlive());
    }
}
