import java.util.Scanner;
class Question1
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		float kg, cm, m, bmi;
		System.out.print("Enter weight in KG: ");
		kg = s.nextFloat();
		System.out.print("Enter height in cm: ");
		cm = s.nextFloat();
		m = cm/100;
		//bmi = kg/(Math.pow(m,2));
		bmi = kg/(m*m);
		System.out.println("BMI = " + bmi);
		if(bmi < 18.5)
			System.out.println("Underweight");
		else if(bmi >= 18.5 && bmi <= 24.9)
			System.out.println("Normal");
		else if(bmi >= 25 && bmi <= 29.9)
			System.out.println("Overweight");
		else
			System.out.println("Obese");

		s.close();
	}
}
