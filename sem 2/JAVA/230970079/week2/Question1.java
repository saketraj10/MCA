import java.util.Scanner;
class Question1
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Number of elements ? ");
		int size = s.nextInt();
		int arr[] = new int[size];
		System.out.println("Input " + size + " integers");
		for(int i=0; i<size; i++)
		{
			arr[i] = s.nextInt();
		}
		int arr1[] = new int[size];

		for(int i=0; i<size; i++)
		{
			int num = arr[i];
			int rem = 0, rev = 0;
			while(num > 0)
			{
				rev *= 10;
				rem =  num%10;
				rev += rem;
				num /= 10;
			}
			arr1[i] = rev;
		}

		System.out.println("Contents of the two array");
		for(int i=0; i<size; i++)
		{
			System.out.println(arr[i] + " \t " + arr1[i]);
		}
		s.close();
	}
}