import java.util.Scanner;
class Question2
{

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the size of array: ");
		int size = s.nextInt();
		int arr[] =  new int[size];

		System.out.println("Enter the element of array: ");
		for(int i=0; i<size; i++)
		{
			arr[i] = s.nextInt();
		}

		int mean=0;
		int sum=0;
		for(int i=0; i<size; i++)
		{
			sum += arr[i];
		}
		mean = sum/size;
		System.out.println("Mean=" + mean);
		System.out.println("After subtract each element from mean value: ");
		for(int i=0; i<size; i++)
		{
			System.out.print(mean-arr[i] + " ");
		}


		s.close();
	}
}
