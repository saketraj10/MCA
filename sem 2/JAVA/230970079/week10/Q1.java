import java.io.*;
import java.util.*;
class Q1
{
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the filename for write: ");
        String file1 = s.next();
        s.nextLine();
        System.out.println("Enter the string for write in file:");
        String str1 = s.nextLine();
        
        File f = new File(file1);
        FileOutputStream f1 = new FileOutputStream(f);
        f1.write(str1.getBytes());
        f.createNewFile();
        f1.close();


        FileInputStream f2 = new FileInputStream(f);
        byte[] b = new byte[(int)f.length()];

        for(int i=0; i<(int)f.length(); i++){
            b[i] = (byte)f2.read();
        }
        
        String str2 = new String(b);

        f2.close();
        ArrayList<String> sortedStrList = new ArrayList<String>();
        
        for(String string : str2.split(" ")){
            sortedStrList.add(string);
        }

        sortedStrList.sort(null);

        System.out.println("Enter the file to write sorted data of first file: ");
        String file2 = s.next();
        String sortedStr = "";
        for(String string : sortedStrList){
            sortedStr = sortedStr + string + " ";
        }

        File sf = new File(file2);
        FileOutputStream f3 = new FileOutputStream(sf);
        f3.write(sortedStr.getBytes());
        sf.createNewFile();
        f3.close();
        
        s.close();

    }
}