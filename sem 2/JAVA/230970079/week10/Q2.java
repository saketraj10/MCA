import java.io.*;
import java.util.*;
public class Q2 {
    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);

        System.out.println("Enter the file name: ");
        String file = s.next();

        FileReader fr = new FileReader(file);
        String str = "";

        int c;
        while( (c=fr.read()) != -1){
            str = str + (char)c;
        }
        fr.close();

        System.out.println("Enter the file name for write: ");
        String wr = s.next();
        FileWriter fw = new FileWriter(wr);
        fw.write(str,0,str.length());
        fw.close();

        s.close();
    }
}
