import java.util.Scanner;
class Question2
{
	public static int calculateGCD(int a, int b)
	{
		while(b != 0)
		{
			int temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}
	public static int calculateLCM(int a, int b)
	{
		int gcd = calculateGCD(a,b);
		return (a*b)/gcd;
	}

	public static void main(String[] args)
	{
		Scanner s= new Scanner(System.in);
		System.out.print("Enter number1: ");
		int num1 = s.nextInt();

		System.out.print("Enter number2: ");
		int num2 = s.nextInt();

		System.out.println("GCD of " + num1 + " and " + num2 + " is " + calculateGCD(num1, num2));

		System.out.println("LCM of " + num1 + " and " + num2 + " is " + calculateLCM(num1, num2));

		s.close();
	}
}