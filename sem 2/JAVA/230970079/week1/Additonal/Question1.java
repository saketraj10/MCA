import java.util.Scanner;
class Question1
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the year of date: ");
		int year1 = s.nextInt();
		System.out.print("Enter the month of date: ");
		int month1 = s.nextInt();
		System.out.print("Enter the day of date: ");
		int day1 = s.nextInt();

		System.out.print("enter the no of days: ");
		int day = s.nextInt();


		System.out.println(year1 + "-" + month1 + "-" + day1);

		day1 = day1 + day;
		if(day1 > 30)
		{
			month1 += day1 / 30;
			day1 %= 30;
		}
		if(month1 > 12)
		{
			year1 += month1 / 12;
			month1 %= 12;
		}
		System.out.println("The resulting date after addition of date and no of days: ");
		System.out.println(year1 + "-" + month1 + "-" + day1);
		s.close();
	}
}

