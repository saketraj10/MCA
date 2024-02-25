import java.util.Scanner;
class Question1
{
	int id;
	String item_name;
	int quantity;
	int unit;
	int price;
	static float total_bill;

	Question1(int id, String item_name, int quantity, int unit, int price)
	{
		this.id = id;
		this.item_name = item_name;
		this.quantity = quantity;
		this.unit = unit;
		this.price = price;
	}

	static void totalBill(float p)
	{
		if(p < 500)
			total_bill = p;
		else if(p >= 500 && p < 1000)
		{
			total_bill = p - p*(.1f);

		}
		else if(p >= 1000 && p <= 2000)
		{
			total_bill = p - p*(.12f);
		}
		else
		{
			total_bill = p - p * (.15f);
		}
	}

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);

		System.out.print("Enter the no items: ");
		int item = s.nextInt();

		Question1 q1[] = new Question1[item];

		System.out.println("Enter the details of items: ");
		for(int i=0; i<item; i++)
		{
			System.out.print("Enter the item id: ");
			int itemId = s.nextInt();
			System.out.print("Enter the item name: ");
			String itemName = s.next();
			System.out.print("Enter the item quantity: ");
			int itemQuantity = s.nextInt();
			System.out.print("Enter the item unit: ");
			int itemUnit = s.nextInt();
			System.out.print("Enter the item price: ");
			int itemPrice = s.nextInt();
			q1[i] = new Question1(itemId, itemName, itemQuantity, itemUnit, itemPrice);
		}

		float total = 0;
		for(int i=0; i<item; i++)
		{
			int p = q1[i].price * q1[i].unit;
			total += p;
		}

		totalBill(total);

		System.out.println("Total Bill = " + total_bill);
		s.close();
	}
}