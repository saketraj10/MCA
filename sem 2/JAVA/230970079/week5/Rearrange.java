import java.util.*;
class Rearrange
{
	static void chSort(char[] arr, int x)
	{
		int n = arr.length;
		for(int i=0; i<n-1; i++)
		{
			for(int j=0; j<n-i-1; j++)
			{
				if(arr[j] > arr[j+1] && x == 0)
				{
					char temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
				if(Character.toLowerCase(arr[j]) > Character.toLowerCase(arr[j + 1]) && x == 1)
				{
					char temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}

			}
		}
	}

	static String rearrangeWithCase(String input)
	{
		char[] chars = input.toCharArray();
		chSort(chars, 0);
		return new String(chars);
	}

	static String rearrangeWithoutCase(String input)
	{
		char[] chars = input.toCharArray();
		chSort(chars, 1);
		return new String(chars);
	}

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Input a string : ");
		String str = s.next();

		String str1 = rearrangeWithCase(str);
		System.out.println("Output Sting (with Case) = " + str1);

		String str2 = rearrangeWithoutCase(str);
		System.out.println("Output String (without Case) = " + str2);

		s.close();
	}
}