import java.util.*;
class Employee
{
	private int empno;
	private String name;
	private String design;
	private int age;
	private float salary;

	Employee(){}
	Employee(int empno, String name, String design, int age, float salary)
	{
		this.empno = empno;
		this.name = name;
		this.design = design;
		this.age = age;
		this.salary = salary;
	}

	void display()
	{
		System.out.println("Empno: " + empno);
		System.out.println("Name: " + name);
		System.out.println("Designation: " + design);
		System.out.println("Age: " + age);
		System.out.println("Salary: " + salary);
		System.out.println();
	}

	int getEmpno()
	{
		return empno;
	}
}
class ArrayListOperation
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		ArrayList<Employee> ALEmp = new ArrayList<Employee>();

		int ch;
		do
		{
			System.out.println("1. Insert an object into arraylist");
			System.out.println("2. Delete an object from the arraylist");
			System.out.println("3. Display the content of the arraylist");
			System.out.print("Enter your choice, 0 to stop: ");
			ch = s.nextInt();
			switch(ch)
			{
				case 1:
					System.out.print("Enter empno: ");
					int empno = s.nextInt();
					System.out.print("Enter name: ");
					String name = s.next();
					System.out.print("Enter designation: ");
					String design = s.next();
					System.out.print("Enter age: ");
					int age = s.nextInt();
					System.out.print("Enter salary: ");
					float salary = s.nextFloat();
					ALEmp.add( new Employee(empno, name, design, age, salary));
					break;
				case 2:
					System.out.print("Enter the empno to delete: ");
					int emp = s.nextInt();
					boolean flag = true;
					for(int i=0; i<ALEmp.size(); i++)
					{
						if(ALEmp.get(i).getEmpno() == emp)
						{
							ALEmp.remove(i);
							flag = false;
							break;
						}
					}
					if(flag)
						System.out.println("Employee not found");
					else
						System.out.println("Successfull deleted");
					break;
				case 3:
					System.out.println("Content of arraylist: ");
					for(Employee e : ALEmp)
						e.display();
					break;
				case 0:
					System.out.println("Exit");
					break;
				default:
					System.out.println("Invalid choice, please enter again");
			}
		}while(ch!=0);
	}
}
