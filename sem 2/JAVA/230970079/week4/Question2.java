import java.util.Scanner;
class Points
{
	private int x, y;
	Points(int a, int b)
	{
		x = a;
		y = b;
	}

	void display()
	{
		System.out.println("(" + x + ", " + y + ")");
	}

    double calculate_distance(int m, int n){
        double result = Math.sqrt(Math.pow(m-x,2) + Math.pow(n-y,2));
        return result;
    }

	double calculate_distance(Points ob2)
	{
		double result = Math.sqrt(Math.pow(ob2.x-x, 2) + Math.pow(ob2.y-y, 2));
		return result;
	}

}
class Question2
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		int a, b;
		System.out.print("Input the coordinates of p1 : ");
		a = s.nextInt();
		b = s.nextInt();
		Points p1 = new Points(a, b);
		System.out.print("Input the coordinates of p2 : ");
		a = s.nextInt();
		b = s.nextInt();
		Points p2 = new Points(a, b);
        double dis = p1.calculate_distance(a,b);
		System.out.print("Input the coordinates of p3 : ");
		a = s.nextInt();
		b = s.nextInt();
		Points p3 = new Points(a, b);

		System.out.print("p1 = ");
		p1.display();

		System.out.print("p2 = ");
		p2.display();

		System.out.print("p3 = ");
		p3.display();

		System.out.println("Distance between p1 and p2 = " + dis);

		System.out.println("Distance between p1 and p3 = " + p1.calculate_distance(p3));

		s.close();
	}
}