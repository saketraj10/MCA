import java.util.Scanner;
class Customer
{
	int cust_id;
	String name;
	long phoneNumber;
	int billNumber;
	int numberOfCall;
	float billAmount;
	static int id=1;

	Customer(String n, long m, int bill, int callsno)
	{
		cust_id = id++;
		name = n;
		phoneNumber = m;
		billNumber = bill;
		numberOfCall = callsno;
	}

	void calculate_bill_amt()
	{
		float bill = 0;
		if(numberOfCall<=100)
		{
			bill = 100;
		}
		else if(numberOfCall<=150)
		{
			bill = 100 +  .6f * (numberOfCall-100);
		}
		else if(numberOfCall<=200)
		{
			bill = 100 +  0.6f * (150-100);
			bill += 0.5f * (numberOfCall-150);
		}
		else if(numberOfCall>200)
		{
			bill = 100 +  0.6f * (150-100);
			bill += 0.5f * (200-150);
			bill += 0.4f * (numberOfCall-200);
		}
		billAmount = bill;
	}
	void display()
	{
			System.out.println("Customer id: " + cust_id );
			System.out.println("Name: " + name );
			System.out.println("Phone number: " + phoneNumber );
			System.out.println("Bill number: " + billNumber );
			System.out.println("Number of calls: " + numberOfCall );
			System.out.println("Bill amount: " + billAmount );
	}
}
class Question1
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);

		System.out.print("Enter the number of customer: ");
		int n = s.nextInt();
		Customer c1[] = new Customer[n];
		for(int i=0; i<n; i++)
		{
			System.out.println("Enter the " + (i+1) +"st customer: ");
			System.out.print("Enter the name of customer: ");
			String na = s.next();
			System.out.print("Enter the phone number of customer: ");
			long m = s.nextLong();
			System.out.print("Enter the bill number of customer: ");
			int bill = s.nextInt();
			System.out.print("Enter the number of calls: ");
			int callsno = s.nextInt();
			c1[i] = new Customer(na, m, bill, callsno);
			c1[i].calculate_bill_amt();
		}


		int ch;
		do{
			System.out.println("1. display the details ");
			System.out.println("for exit press 0 ");
			System.out.print("Enter the option: ");
			ch = s.nextInt();
			switch(ch)
			{
				case 1:
					System.out.print("Enter the customer_id (like 1,2,3 ...) for display details: ");
					int cid = s.nextInt();
					c1[cid-1].display();
					break;
				case 0:
					return;
				default:
					System.out.println("invalid input");
		}
		}while(ch!=0);

		s.close();
		}
}