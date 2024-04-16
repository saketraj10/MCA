class A extends Thread{
    public void run()
    {
        for(int i=1; i<=10; i++)
        {
            System.out.println("Thread A");
            try{
                sleep(1000);
            }
            catch(Exception e){ }
        }
        System.out.println("End of Thread A");
    }
}
class B extends Thread
{
    public void run()
    {
        for(int i=1; i<=10; i++)
        {
            System.out.println("Thread B");
            try
            {
                sleep(1000);
            }
            catch(Exception e){ }
        }
        System.out.println("End of Thread B");
    }
}
class C extends Thread
{
    public void run()
    {
        for(int i=0; i<=10; i++)
        {
            System.out.println("Thread C");
            try
            {
                sleep(1000);
            }
            catch(Exception e){ }
        }
        System.out.println("End of Thread C");
    }
}
public class MultiThread_Demo1 {
    public static void main(String[] args) {
        A aobj = new A();
        B bobj = new B();
        C cobj = new C();
        aobj.start();
        bobj.start();
        cobj.start();
    }
}
