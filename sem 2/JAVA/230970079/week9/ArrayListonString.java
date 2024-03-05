import java.util.*;
class ArrayListonString
{
	public static void main(String[] args)
	{

		Scanner s = new Scanner(System.in);

		ArrayList<String> ALStr = new ArrayList<String>();

		System.out.println("Enter five strings: ");
		for(int i=0; i<5; i++)
		{
			System.out.print("String: " + (i+1) + ": ");
			String str = s.next();
			ALStr.add(str);
		}

		Collections.sort(ALStr);


		Iterator<String> itr = ALStr.iterator();
		System.out.println("Displaying using Iterator (Forward Direction): ");
		while(itr.hasNext())
		{
			System.out.print(itr.next() + " ");
		}
		System.out.println();

		ListIterator<String> Litr = ALStr.listIterator();
		System.out.println("Displaying using ListIterator (Forward Direction): ");
		while(Litr.hasNext())
		{
			System.out.print(Litr.next() + " ");
		}
		System.out.println();

		System.out.println("Displaying using ListIterator (Backward Direction): ");
		while(Litr.hasPrevious())
		{
			System.out.print(Litr.previous() + " ");
		}
		System.out.println();
		s.close();
	}
}