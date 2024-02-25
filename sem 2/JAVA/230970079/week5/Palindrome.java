import java.util.*;
class Palindrome
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Input a string : ");
		String str = s.next();

		String str1 = "";
		int n = str.length();
		for(int i=0; i<n; i++)
		{
			str1 += str.charAt(n-1-i);
		}

		if(str.equalsIgnoreCase(str1))
			System.out.println(str + " is palindrome");
		else
			System.out.println(str + " is not palindrome");

		s.close();
	}
}