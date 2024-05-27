import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class PersonalCalcJava 
{
    public static void main(String[] args)
    {
        Scanner scanner=new Scanner(System.in);
        System.out.println("Welcome to Calculator App");
        System.out.println("Enter a math problem (e.g., 719 x 412):");
        while (true) 
        {
            String input=scanner.nextLine();
            if (input.equalsIgnoreCase("exit")) 
            {
                break;
            }
            if (isValidInput(input))
            {
                double result=calculateResult(input);
                System.out.println("Result: "+result);
            } 
            else 
            {
                System.out.println("Invalid input. Please enter a valid math problem.");
            }
            System.out.println("\nEnter another math problem or type 'exit' to quit:");
        }
        scanner.close();
        System.out.println("Calculator App terminated.");
    }
    private static boolean isValidInput(String input) 
    {
        String regex="^\\d+\\s*[+\\-*/xX]\\s*\\d+$";
        Pattern pattern=Pattern.compile(regex);
        Matcher matcher=pattern.matcher(input);
        return matcher.find();
    }

    private static double calculateResult(String input) 
    {
        String[] parts=input.split("\\s*[+\\-*/xX]\\s*");
        double num1=Double.parseDouble(parts[0]);
        double num2=Double.parseDouble(parts[1]);
        char operator=input.replaceAll("[^+\\-*/xX]","").charAt(0);
        switch(operator) 
        {
            case'+':
                return num1+num2;
            case'-':
                return num1-num2;
            case'*':
            case'x':
            case'X':
                return num1*num2;
            case '/':
                return num1/num2;
            default:
                throw new IllegalArgumentException("Invalid operator");
        }
    }
}
