import java.util.Scanner;
class Question3
{

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the row of matrix: ");
		int row = s.nextInt();
		System.out.print("Enter the col of matrix: ");
		int col = s.nextInt();
		int matrix[][] =  new int[row][col];

		System.out.println("Enter the element of matrix: ");
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col; j++)
			{
				matrix[i][j] = s.nextInt();
			}
		}

		for(int k=0; k<row; k++)
		{
			for(int i=0; i<row-1; i++)
			{
				int count=0;
				int count1=0;
				for(int j=0; j<col; j++)
				{
					if(matrix[i][j]==1)
						count++;
					if(matrix[i+1][j]==1)
						count1++;
				}
				if(count1 > count)
				{
					for(int j=0; j<col; j++)
					{
						int temp = matrix[i][j];
						matrix[i][j] = matrix[i+1][j];
						matrix[i+1][j] = temp;
					}
				}
			}
		}

		System.out.println("After sorted in row wise: ");
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<col; j++)
			{
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
		s.close();
	}
}
