import java.util.Scanner;
class IntArr
{
	int size;
	int arr[];

	IntArr()
	{
		arr = new int[0];
	}

	IntArr(int[] a)
	{
		arr = a;
	}

	void display()
	{
		System.out.println("Array elements: ");
		for(int i=0; i<arr.length; i++)
		{
			System.out.print(arr[i] + " " );
		}
		System.out.println();
	}

	void search(int n)
	{
		for(int i=0; i<arr.length; i++)
		{
			if(arr[i] == n)
			{
				System.out.println("Element found");
				return;
			}
		}
		System.out.println("Element not found");
	}

	boolean compare(IntArr intarr2)
	{
		for(int i=0; i<arr.length; i++)
		{
			if(arr[i] != intarr2.arr[i])
			{
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);

		int[] array1 = {1, 2, 3, 4, 5};
		IntArr intArr1 = new IntArr(array1);

		int[] array2 = {1, 2, 3, 4, 5};
		IntArr intArr2 = new IntArr(array2);

		intArr1.display();

		System.out.println("Enter the value for search in array: ");
		int num = s.nextInt();
		intArr1.search(num);
		System.out.println();

		boolean flag = intArr1.compare(intArr2);

		if(flag == true)
		{
			System.out.println("array1 and array2 are equal");
		}
		else{
			System.out.println("array1 and array2 not equal");
		}
		s.close();
	}
}

