import java.util.Scanner;
class Question2
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the size of array: ");
		int size = s.nextInt();
		int arr[] = new int[size];
		System.out.println("Enter the element of array: ");
		for(int i=0; i<size; i++)
		{
			arr[i] = s.nextInt();
		}
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
			{
				if(arr[i] > arr[j])
				{
					System.out.print("(" + arr[i] + "," + arr[j] + ") ");
				}
			}
		}
		s.close();
	}
}