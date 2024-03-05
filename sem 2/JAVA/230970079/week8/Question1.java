import java.util.*;

class MarkOutOfBoundsException extends Exception
{
    public MarkOutOfBoundsException(String message){
        super(message);
    }
}

class Student
{
    private String name;
    private int rollNumber;
    private int[] marks;

    Student(String name, int rollNumber, int[] marks){
        this.name = name;
        this.rollNumber = rollNumber;
        this.marks = marks;
    }

    double calculatePercentage()
    {
        int totalMarks = 0;
        for(int mark : marks){
            totalMarks += mark;
        }
        double per = (double)totalMarks/marks.length;
        return per;
    }

    String calculateGrade()
    {
        double percentage = calculatePercentage();
        if(percentage>90) return "A+";
        else if(percentage>80) return "A";
        else if(percentage>70) return "B";
        else if(percentage>60) return "C";
        else if(percentage>50) return "D";
        else if(percentage>40) return "E";
        else return "F";
    }

    void display(){
        System.out.println("Name: " + name);
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Percentage: " + calculatePercentage());
        System.out.println("Grade: " + calculateGrade());
    }
}

class Question1
{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter name: ");
        String name = s.next();
        System.out.print("Enter roll number: ");
        int rollNumber = s.nextInt();

        int[] marks = new int[3];
        for(int i=0; i<3; i++)
        {
            try{
                System.out.print("Enter marks for subject " + (i+1) + ": ");
                marks[i] = Integer.parseInt(s.next());
                if(marks[i] < 0 || marks[i] > 100){
                    throw new MarkOutOfBoundsException("Marks should be in the range 0-100");
                }
            }
            catch(NumberFormatException e){
                System.out.println("Invalid input! please enter a valid integer for marks.");
                i--;
            }
            catch(MarkOutOfBoundsException e){
                System.out.println(e.getMessage());
                i--;
            }
        }
        Student s1 = new Student(name, rollNumber, marks);
        s1.display();
        s.close();
    }
}