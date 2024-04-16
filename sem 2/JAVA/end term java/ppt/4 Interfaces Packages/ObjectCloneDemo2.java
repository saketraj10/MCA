class Employee implements Cloneable
{
    int id;
    String name;
    double salary;

    public Employee(int id,String name, double sal){
        this.id = id;
        this.name  = name;
        this.salary = sal;
    }
    public Employee clone() throws CloneNotSupportedException
    {
        
        Employee emp = (Employee)super.clone();
        return emp;
    }

    void raiseSalary()
    {
        salary += 5000;
    }

    public String toString()
    {
        return "id: " + id + ", name: " + name + ", salary: " + salary;
    }
}
public class ObjectCloneDemo2 {
    public static void main(String[] args) {
        Employee emp1 = new Employee(111, "John", 35000);
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
    }
}
