import java.util.Scanner;
class Box
{
	int width;
	int height;
	int depth;
	
	Box(int w, int h, int d)
	{
		width = w;
		height = h;
		depth = d;
	}
	
	int volume()
	{
		return width * height * depth;
	}
	
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the width of box: ");
		int w = s.nextInt();
		System.out.print("Enter the height of box: ");
		int h = s.nextInt();
		System.out.print("Enter the depth of box: ");
		int d = s.nextInt();
	
		Box b = new Box(w, h, d);
		
		System.out.println("Volume of box: " + b.volume());
		
		s.close();
	}
}