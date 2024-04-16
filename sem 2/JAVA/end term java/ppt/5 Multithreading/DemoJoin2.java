class NewThread extends Thread
{
    int Thread_num, val;
    int[] arr;
    NewThread(int no, int a[], int v)
    {
        Thread_num = no;
        val = v;
        arr = a;
        System.out.println("thread: " + Thread_num);
        start();
    }
    public void run()
    {
        multiply();
        System.out.println("Thread " + Thread_num + " existing.");
    }
    void multiply()
    {
        System.out.println("Multiplying..");
        for(int i=0; i<arr.length; i++)
        {
            arr[i] *= val;
        }
    }
}
public class DemoJoin2 {
    public static void main(String[] args) {
        int arr1[] = {10,20,30,40,50};
        int arr2[] = {11,22,33,44,55};
        int val1 = 2, val2 = 3;
        NewThread t1 = new NewThread(1, arr1, val1);
        NewThread t2 = new NewThread(2, arr2, val2);

        try
        {
            t1.join();
            t2.join();
        }
        catch(InterruptedException e)
        {
            System.out.println("Main thread Interrupted");
        }

        System.out.println("Displaying arr1 & arr2");
        for(int i=0; i<arr1.length; i++)
        {
            System.out.print(arr1[i] + " ");
        }
        System.out.println();
        for(int i=0; i<arr2.length; i++)
        {
            System.out.print(arr2[i] + " ");
        }
        System.out.println();
        System.out.println("Main thread exiting.");

    }
}
