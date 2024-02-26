import java.util.*;
class Employee implements Cloneable
{
    private String name, design;
    private int id;
    private float salary;
    Employee(String name, int id, String design, float salary)
    {
        this.name = name;
        this.id = id;
        this.design = design;
        this.salary = salary;
    }
    public Employee clone() throws CloneNotSupportedException
    {
        return (Employee)super.clone();
    }
    void raiseSalary()
    {
        salary += 500000;
    }
    public String toString()
    {
        return "name: " + name + " id: " + id + " designation: " + design + " salary: " + salary;
    }

}
public class MainClone {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name : ");
        String name = sc.next();
        System.out.print("Enter id : ");
        int id = sc.nextInt();
        System.out.print("Enter designation : ");
        String design = sc.next();
        System.out.print("Enter salary : ");
        float salary = sc.nextFloat();
        Employee emp1 = new Employee(name, id, design, salary);
        Employee emp2 = emp1;
        Employee emp3 = null;
        try{
            emp3 = emp1.clone();
        }
        catch(CloneNotSupportedException e){
            System.out.println("Cloning not allowed.");
        }

        emp2.raiseSalary();

        System.out.println("emp1: " + emp1);
        System.out.println("emp2: " + emp2);
        System.out.println("emp3: " + emp3);
        sc.close();
    }
}
