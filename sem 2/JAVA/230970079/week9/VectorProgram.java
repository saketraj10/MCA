import java.util.*;
class VectorProgram
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		Vector<Integer> v = new Vector<Integer>();
		v.addElement(1);
		v.addElement(3);
		v.addElement(5);
		v.addElement(7);
		v.addElement(9);

		int ch;
		do
		{
			System.out.println("1. Insert an element at a specified position");
			System.out.println("2. Insert an element at the end");
			System.out.println("3. Delete an element");
			System.out.println("4. Display the contents");
			System.out.print("Enter your choice, 0 to stop: ");
			ch = s.nextInt();
			switch(ch)
			{
				case 1:
					System.out.print("Enter the value to insert: ");
					int val = s.nextInt();
					System.out.print("Enter the index value where to insert: ");
					int idx = s.nextInt();
					v.add(idx,val);
					break;
				case 2:
					System.out.print("Enter the value to insert: ");
					int value = s.nextInt();
					v.addElement(value);
					break;
				case 3:
					System.out.print("Enter an element to delete: ");
					int val2 = s.nextInt();
					if(v.remove((Integer)val2))
						System.out.println("Successfully deleted");
					else
						System.out.println("Element not removed or not found");
					break;
				case 4:
					for(int i: v)
						System.out.print(i + " ");
					System.out.println();
					break;
				case 0:
					System.out.println("Exit");
					break;
				default:
					System.out.println("Invalid choice, please enter again");
			}
		}while(ch!=0);

		s.close();
	}
}

