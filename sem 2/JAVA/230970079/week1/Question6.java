import java.util.Scanner;
class Question6
{
	public static void main(String[] args)
	{
		int a,b,c;
		a = Integer.parseInt(args[0]);
		b = Integer.parseInt(args[1]);
		c = Integer.parseInt(args[2]);
		double r1=0,r2;
		int d = b * b - 4 * a * c;
		r1 = (-b + Math.sqrt(d))/(2 * a);
		r2 = (-b - Math.sqrt(d))/(2 * a);

		if(d == 0)
			System.out.println("only one root: " + r1);
		else if(d > 0)
			System.out.println("Two roots: " + r1 + " and " + r2);
		else
			System.out.println("Roots are imaginary");
	}
}
