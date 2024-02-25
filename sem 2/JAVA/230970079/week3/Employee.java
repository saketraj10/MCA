import java.util.Scanner;
class Employee
{
	Scanner s = new Scanner(System.in);
	int employee_code;
	String employee_name;
	float Basic;
	float HRA;
	float IT;
	float PF;
	float net_salary;
	float gross_salary;

	Employee()
	{
		IT = 200;
	}

	void calculateSal()
	{
			HRA = Basic * (7.5f/100f);
			PF = Basic * (12f/100f);
			gross_salary = Basic + HRA;
			net_salary = gross_salary - (IT + PF);
	}

	void setData()
	{
		System.out.print("Enter the employee code: ");
		employee_code = s.nextInt();
		System.out.print("Enter the employee name: ");
		employee_name = s.next();
		System.out.print("Enter the Basic: ");
		Basic = s.nextFloat();
		calculateSal();
	}

	void getData()
	{
		System.out.println("Employee code: " + employee_code);
		System.out.println("Employee name: " + employee_name);
		System.out.println("Basic: " + Basic);
		System.out.println("HRA: " + HRA);
		System.out.println("IT: " + IT);
		System.out.println("PF: " + PF);
		System.out.println("net salary: " + net_salary);
		System.out.println("gross salary: " + gross_salary);
	}

	public static void main(String[] args)
	{
		Employee e = new Employee();
		e.setData();
		e.getData();
	}
}