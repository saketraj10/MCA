import java.util.*;
class ElementWiseDivision
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the size of array1: ");
		int n1 = sc.nextInt();
		int arr1[] = new int[n1];
		System.out.println("Enter the element of array1: ");
		for(int i=0; i<n1; i++)
		{
			arr1[i] = sc.nextInt();
		}
		System.out.print("Enter the size of array2: ");
		int n2 = sc.nextInt();
		int arr2[] = new int[n2];
		System.out.println("Enter the element of array2: ");
		for(int i=0; i<n2; i++)
		{
			arr2[i] = sc.nextInt();
		}
		try
		{
			for(int i=0; i<arr1.length; i++)
			{
				try
				{
					System.out.println(arr1[i] + "/" + arr2[i] + " is " +arr1[i]/arr2[i]);
				}
				catch(ArithmeticException exc)
				{
					System.out.println("Can't divide by zero");
				}
			}
		}
		catch(ArrayIndexOutOfBoundsException exc)
		{
				System.out.println("No element found array out of bound");
		}
		sc.close();
	}
}