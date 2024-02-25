import java.util.*;
class StringOperation
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Input two string : ");
		String str = s.next();
		String str1 = s.next();
		System.out.println();
		System.out.print("Input position : ");
		int n1 = s.nextInt();
		System.out.println();
		System.out.print("Input length : ");
		int n2 = s.nextInt();

		System.out.println("Uppercase of " + str + " is " + str.toUpperCase());
		System.out.println("Lowercase of " + str1 + " is " + str1.toLowerCase());
		System.out.println("Substring of " + str + " from postion " + n1 +" with length " + n2 + " = " + str.substring(n1, (n1+n2)) );

		StringBuilder sb = new StringBuilder(str);
		sb.insert(n1, str1);
		String str3 = sb.toString();
		System.out.println("After inserting " + str1 + " into " + str + " at position " + n1 + " = " + str3);

		String str4 = str + str1;
		System.out.println("After appending " + str1 + " to " + str + " = " + str4);

		s.close();
	}
}