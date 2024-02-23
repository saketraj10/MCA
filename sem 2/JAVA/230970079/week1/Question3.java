import java.util.Scanner;
class Question3
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		float km, lt, avg;
		System.out.print("Enter the distance(in Km) : ");
		km = s.nextFloat();
		System.out.print("Enter the fuel consumed(in Litre) : ");
		lt = s.nextFloat();
		avg = km/lt;
		System.out.println("average fuel economy= " + avg);
		int ch;
		do
		{
			System.out.println("1.Dist estimation");
			System.out.println("2.Fuel estimation");
			System.out.print("Enter your choice(0 to stop): ");
			ch = s.nextInt();
			switch(ch)
			{
				case 1:
					System.out.print("Enter the fuel consumed(in Litre) : ");
					lt = s.nextFloat();
					km = avg * lt;
					System.out.println("Estimated distance=" + km);
					break;
				case 2:
					System.out.print("Enter the distance(in Km) : ");
					km = s.nextFloat();
					lt = km/avg;
					System.out.println("Estimated fuel=" + lt);
					break;
			}
		}while(ch != 0);
		s.close();
	}
}
