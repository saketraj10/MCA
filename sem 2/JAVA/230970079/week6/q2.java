import java.util.*;
class Student
{
    Scanner s = new Scanner(System.in);
    protected int Register;
    protected String Name, Course, Semester;
    void get_data()
    {
        System.out.print("Enter Register Number: ");
        Register = s.nextInt();
        System.out.print("Enter Name: ");
        Name = s.next();
        System.out.print("Enter Course: ");
        Course = s.next();
        System.out.print("Enter Semester: ");
        Semester = s.next();
    }
    void display()
    {
        System.out.println("Register Number: " + Register);
        System.out.println("Name: " + Name);
        System.out.println("Course: " + Course);
        System.out.println("Semester: " + Semester);
    }
    //s.close();
}
class Exam extends Student
{
    Scanner s = new Scanner(System.in);
    protected double mark1, mark2, mark3;
    void get_data()
    {
        super.get_data();
        System.out.print("Enter the marks of subject1: ");
        mark1 = s.nextDouble();
        System.out.print("Enter the marks of subject2: ");
        mark2 = s.nextDouble();
        System.out.print("Enter the marks of subject3: ");
        mark3 = s.nextDouble();
    }
    void display()
    {
        super.display();
        System.out.println("Marks of subject1: " + mark1);
        System.out.println("Marks of subject2: " + mark2);
        System.out.println("Marks of subject3: " + mark3);
    }

    //s.close();
}
class Result extends Exam
{
    protected double totalMarks;
    protected String grade;
    void get_data()
    {
        super.get_data();
    }
    double calculateTotalMarks()
    {
        return mark1+mark2+mark3;
    }
    String calculateGrade(double percent)
    {
        if(mark1<40 || mark2<40 || mark3<40) return "F";
        if(percent>90) return "A+";
        else if(percent>80) return "A";
        else if(percent>70) return "B";
        else if(percent>60) return "C";
        else if(percent>50) return "D";
        else if(percent>=40) return "E";
        else return "F";
    }
    void display(){
        super.display();
        totalMarks = calculateTotalMarks();
        double percent = totalMarks/3;
        grade = calculateGrade(percent);
        System.out.println("Total Marks: " + totalMarks);
        System.out.println("Grade: " + grade);
    }
}
public class q2 {
    public static void main(String[] args) {
        Result r = new Result();
        r.get_data();
        r.display();    
    }
}