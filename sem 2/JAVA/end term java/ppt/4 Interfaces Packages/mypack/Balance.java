
package mypack;
public class Balance
{
	String name;
	double bal;
	public Balance(String n, double b)
	{
		name = n;
		bal = b;
	}
	public void show()
	{
		System.out.println(name + " " + bal);
	}
}