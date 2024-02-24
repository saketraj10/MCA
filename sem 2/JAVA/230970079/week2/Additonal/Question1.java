import java.util.Scanner;
class Question1
{

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the row of 2-d array: ");
		int row = s.nextInt();
		System.out.print("Enter the col of 2-d array: ");
		int col = s.nextInt();
		int arr[][] =  new int[row][col];

		System.out.println("Enter the element of 2-d array: ");
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col; j++)
			{
				arr[i][j] = s.nextInt();
			}
		}

		int a[] = new int[row * col];
		int size = 0;
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col; j++)
			{
				boolean flag = true;
				for(int k=0; k<size; k++)
				{
						if(a[k] == arr[i][j])
						{
							flag = false;
						}
				}
				if(flag == true)
				{
					a[size] = arr[i][j];
					size++;
				}
			}
		}

		for(int i=0; i<size; i++)
		{
			System.out.print(a[i] + " ");
		}

		s.close();
	}
}
