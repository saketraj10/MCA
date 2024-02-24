import java.util.Scanner;
class Question5
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		System.out.print("Loan Amount: ");
		double loanAmount = s.nextFloat();
		System.out.print("Number of Years: ");
		double years = s.nextFloat();

		double monthlyPayment, totalPayment, monthlyInterestRate, numberOfPayments;
		System.out.println("Interest Rate \t Monthly Payment \t Total Payment");
		for(double interestRate = 5.0; interestRate <=8.0; interestRate += 1.0/8.0)
		{
			monthlyInterestRate = interestRate/12/100;
			numberOfPayments = years * 12;
			monthlyPayment = (loanAmount * monthlyInterestRate)/ (1 - (1/Math.pow(1+monthlyInterestRate,numberOfPayments)));
			totalPayment = monthlyPayment * numberOfPayments;

			System.out.println(interestRate + "% \t\t " + String.format("%.2f",monthlyPayment) + " \t\t " + String.format("%.2f",totalPayment));
		}
		s.close();
	}
}
