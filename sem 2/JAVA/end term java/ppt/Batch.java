import java.util.*;
import java.io.*;
class MyException extends Exception
{
    public String toString()
    {
        return "Invalid text exception";
    }
}

class thread1 implements Runnable
{
    File myfile = new File("Input.txt");
    Scanner sc = new Scanner(System.in);

    public void run()
    {
        System.out.print("Input of length: ");
        int n = sc.nextInt();

        try
        {
            myfile.createNewFile();
            FileWriter writer = new FileWriter(myfile);

            System.out.println("Enter the letters individually");
            for(int i=0; i<n; i++)
            {
                char x = sc.next().charAt(0);
                if((x>=65) && (x<=91) || (x>=97) && (x<=123))
                {
                    writer.write(x + " ");
                }
                else throw new MyException();
            }
            writer.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}

class thread2 implements Runnable
{
    File newFile = new File("encrypted_file.txt");

    public void run()
    {
        try
        {
            newFile.createNewFile();
            FileWriter writer = new FileWriter(newFile);
            FileReader reader = new FileReader("Input.txt");
            
            int k = 0;
            while((k=reader.read()) != -1)
            {
                char Inputchar = (char)(k+19);
                writer.write(Inputchar + " ");
            }
            reader.close();
            writer.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}

class thread3 implements Runnable
{
    File newFile2 = new File("Decrypted_file.txt");

    public void run()
    {
        try
        {
            newFile2.createNewFile();
            FileWriter writer2 = new FileWriter(newFile2);
            FileReader reader = new FileReader("encrypted_file.txt");

            int k=0;
            while((k=reader.read()) != -1)
            {
                char inputchar = (char)(k-19);
                writer2.write(inputchar + " ");
            }

            reader.close();
            writer2.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
public class Batch {
    public static void main(String[] args) {
        thread1 t1 = new thread1();
        thread2 t2 = new thread2();
        thread3 t3 = new thread3();
        
        Thread T1 = new Thread(t1);
        Thread T2 = new Thread(t2);
        Thread T3 = new Thread(t3);

        T1.start();
        try
        {
            T1.join();
        }catch(Exception e)
        {
            System.out.println(e);
        }

        T2.start();
        try
        {
            T2.join();
        }catch(Exception e)
        {
            System.out.println(e);
        }
        T3.start();
        try
        {
            T3.join();
        }catch(Exception e)
        {
            System.out.println(e);
        }

        try
        {
            FileReader reader = new FileReader("encrypted_file.txt");

            int k = 0;
            while((k=reader.read()) !=-1)
            {
                System.out.println((char)k + " ");
            }
            reader.close();
            System.out.println();
            System.out.println();

            FileReader reader1 = new FileReader("Decrypted_file.txt");
            {
                int l = 0;
                while((l=reader1.read()) != -1)
                {
                    System.out.println((char)l + " ");
                }
                reader1.close();
            }
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
