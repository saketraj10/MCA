import java.util.*;
class Words
{
    static String[] units = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    
    static String[] aboveTen = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    static String[] aboveTwenty = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    static String convertToWord(int number)
    {
        if(number == 0)
            return "zero";
        
        return convert(number);
    }
    static String convert(int n)
    {
        if(n<10)
            return units[n];
        
        if(n<20)
            return aboveTen[n%10];

        if(n<100)
            return aboveTwenty[n/10] + ((n%10 != 0) ? " " + convert(n%10) : "");

        if(n<1000)
            return units[n/100] + ((n%100 != 0 ) ? " Hundred " + convert(n%100) : ""); 

        if(n<10000)
            return units[n/1000] + ((n%1000 != 0) ? " Thousand " + convert(n%1000) : "");

        return "";
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Input a number: ");  
        int n = s.nextInt();

        String word = convertToWord(n);
        System.out.println(word);
        
        s.close();
    }
}