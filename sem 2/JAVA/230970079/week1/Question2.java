class Question2
{
	public static void main(String[] args)
	{
		float fees = 50000;
		float rate = 5;
		int year = 10;
		float t = fees * rate/100.0f;
		for(int i=1; i<=year; i++){
			fees = fees + t;
			System.out.println("The fee after " + i + " year = " + fees);
		}
	}
}
