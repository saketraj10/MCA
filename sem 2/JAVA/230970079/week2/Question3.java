import java.util.Scanner;
class Question3
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the number of rows and columns of array: ");
		int row = s.nextInt();
		int col = s.nextInt();

		float arr[][] = new float[row][col];
		System.out.println("Enter the array: ");
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col; j++)
			{
				arr[i][j] = s.nextFloat();
			}
		}
		float max = arr[0][0];
		int x = 0, y = 0;
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col; j++)
			{
				if(max < arr[i][j])
				{
					max = arr[i][j];
					x = i;
					y = j;
				}
			}
		}
		System.out.println("The largest element = " + max + ", location = (" + x + "," + y + ")");
		float min = arr[0][0];
		x = 0;
		y = 0;
		for(int i=0; i<row; i++)
				{
					for(int j=0; j<col; j++)
					{
						if(min > arr[i][j])
						{
							min = arr[i][j];
							x = i;
							y = j;
						}
					}
		}
		System.out.println("The smallest element = " + min + ", location = (" + x + "," + y + ")");

		s.close();
	}
}