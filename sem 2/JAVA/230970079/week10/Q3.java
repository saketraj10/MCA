import java.io.*;
import java.util.*;

class Bank implements Serializable {
    String name;
    int acno, age;
    double bal;

    Bank(String name, int acno, double bal, int age) {
        this.name = name;
        this.acno = acno;
        this.bal = bal;
        this.age = age;
    }

    public String toString()
    {
        return "Bank [name=" + name + ", acno=" + acno + ", bal=" + bal + ", age=" + age + "]";
    }
}

public class Q3 {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the no of object: ");
        int n = s.nextInt();
        try (ObjectOutputStream objOStream = new ObjectOutputStream(new FileOutputStream("account_info.txt")))
        {

            for(int i=0; i<n; i++)
            {
                System.out.print("Enter name: ");
                String name = s.next();
                System.out.print("Enter account no: ");
                int acno = s.nextInt();
                System.out.print("Enter balance: ");
                double bal = s.nextDouble();
                System.out.print("Enter age: ");
                int age = s.nextInt();
                Bank bankObj = new Bank(name, acno, bal, age);
                objOStream.writeObject(bankObj);
            }
        }

        try (ObjectInputStream objIStream = new ObjectInputStream(new FileInputStream("account_info.txt")))
        {
            for(int i=0; i<n; i++)
            {
                Bank tempObj = (Bank)objIStream.readObject();
                System.out.println(tempObj);
            }
        }
        s.close();
    }
}