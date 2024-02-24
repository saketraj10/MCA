import java.util.Scanner;
class Question7
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		float km_per_hr, mtr_per_sec;
		int ch;
		do
		{
			System.out.println("1.km_per_hr to mtr_per_sec");
			System.out.println("2.mtr_per_sec to km_per_hr");
			System.out.print("Enter your choice(0 to stop): ");
			ch = s.nextInt();
			switch(ch)
			{
				case 1:
					System.out.print("Enter the speed in km_per_hr : ");
					km_per_hr = s.nextFloat();
					mtr_per_sec = km_per_hr * (5.0f/18.0f);
					System.out.println("speed in mtr_per_sec=" + mtr_per_sec);
					break;
				case 2:
					System.out.print("Enter the speed in mtr_per_sec : ");
					mtr_per_sec = s.nextFloat();
					km_per_hr = mtr_per_sec * (18.0f/5.0f);
					System.out.println("speed in km_per_hr=" + km_per_hr);
					break;
			}
		}while(ch != 0);
		s.close();
	}
}
