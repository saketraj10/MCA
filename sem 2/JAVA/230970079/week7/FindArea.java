import java.util.*;
abstract class Figure
{
	protected double dim1;
	protected double dim2;
	Figure(double dim1, double dim2)
	{
		this.dim1 = dim1;
		this.dim2 = dim2;
	}
	Figure(double dim1)
	{
		this.dim1 = this.dim2 = dim1;
	}
	abstract double area();
}
class Rectangle extends Figure
{
	Rectangle(double dim1, double dim2)
	{
		super(dim1, dim2);
	}

	double area()
	{
		return dim1*dim2;
	}
}
class Triangle extends Figure
{
	Triangle(double dim1, double dim2)
	{
		super(dim1, dim2);
	}

	double area()
	{
		return (1.0/2.0)*(dim1*dim2);
	}
}
class Square extends Figure
{
	Square(double dim1)
	{
		super(dim1);
	}

	double area()
	{
		return dim1*dim1;
	}
}
class FindArea
{
	public static void main(String[] args)
	{
		Scanner  s = new Scanner(System.in);
		double dim1, dim2;
		System.out.print("Enter the length of rectangle: ");
		dim1 = s.nextDouble();
		System.out.print("Enter the breadth of rectangle: ");
		dim2 = s.nextDouble();

		Rectangle r = new Rectangle(dim1, dim2);

		System.out.print("Enter the height of triangle: ");
		dim1 = s.nextDouble();
		System.out.print("Enter the base of triangle: ");
		dim2 = s.nextDouble();

		Triangle t = new Triangle(dim1, dim2);

		System.out.print("Enter the side of square: ");
		dim1 = s.nextDouble();

		Square sq = new Square(dim1);

		Figure f;
		f = r;
		System.out.println("Area of rectangle: " + f.area());

		f = t;
		System.out.println("Area of triangle: " + f.area());

		f = sq;
		System.out.println("Area of Square: " + f.area());

		s.close();
	}
}