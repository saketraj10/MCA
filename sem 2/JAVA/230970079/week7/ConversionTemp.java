import FToC.FahrToCels;
import CToF.CelsToFahr;
import java.util.*;
public class ConversionTemp {
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in);
        int ch;
        do
        {
            System.out.println("1. Celsius to Fahrenheit");
            System.out.println("2. Fahrenheit to Celsius");
            System.out.print("Enter the following option, 0 to exit: ");
            ch = sc.nextInt();
            switch(ch)
            {
                case 1:
                    System.out.print("Enter the celsius: ");
                    double c = sc.nextDouble();
                    CelsToFahr ctof1 = new CelsToFahr();
                    System.out.println("Fahrenheit is " + ctof1.ConvertCToF(c));
                    break;
                case 2:
                    System.out.print("Enter the fahrenheit: ");
                    double f = sc.nextDouble();
                    FahrToCels ftoc1 = new FahrToCels();
                    System.out.println("Celsius is " + ftoc1.ConvertFToC(f));
                    break;
                case 0:
                    System.out.println("Exiting");
                    break;
                default:
                    System.out.println("Invalid input, please enter again");
            }
        }while(ch!=0);
        sc.close();
    }
}
