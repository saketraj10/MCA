import java.util.*;
class Student
{
    int rno;
    String name;
    float avg;
    Student(){}
    Student(int r, String n, float a)
    {
        rno = r;
        name = n;
        avg = a;
    }
    void show()
    {
        System.out.println(rno + " " + name + " " + avg);
    }
}
public class ArrayListObj {
    public static void main(String[] args) {
        ArrayList<Student> alstud = new ArrayList<Student>();
        Student s = new Student(100, "Anil", 55);
        alstud.add(s);
        alstud.add(new Student(101, "Vinod", 66));
        alstud.add(new Student(102, "Sachin",88));
        System.out.println("Contents of alstud: ");
        for(Student e: alstud)
            e.show();
    }
}
