import java.util.Scanner;
class Question4
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		float hr, rate, total_pay;
		System.out.print("Enter the No. of hrs worked :");
		hr = s.nextFloat();
		System.out.print("Enter the hourly rate :");
		rate = s.nextFloat();

		if(hr > 40){
			float h = hr - 40;
			h /= 2;
			hr += h;
		}
		System.out.println("The total pay = " + hr * rate);
		s.close();
	}
}
