import java.util.ArrayList;

class ArrayListDemo1
{
    public static void main(String[] args) {
        ArrayList<String> al = new ArrayList<String>();

        System.out.println("Initial size of al: " + al.size());

        al.add("C");
        al.add("A");
        al.add("E");
        al.add("B");
        al.add("D");
        al.add("F");
        al.add(1,"A2");

        System.out.println("size of al: " + al.size());
        System.out.println("contents of al: " + al);
        
        al.remove(2);
        
        System.out.println("size of al:  " + al.size());
        System.out.println("contents of al: " + al);
    }
}