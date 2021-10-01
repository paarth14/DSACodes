import java.util.Scanner;


public class UserNameValidator {
    private static final Scanner scan = new Scanner(System.in);
    
    public static void main(String[] args) {
        int n = Integer.parseInt(scan.nextLine());
        final String regularExpression = "^[a-zA-Z][a-zA-Z0-9_]{7,29}$";
        while (n-- != 0) {
            String userName = scan.nextLine();

            if (userName.matches(regularExpression)) {
                System.out.println("Valid");
            } else {
                System.out.println("Invalid");
            }           
        }
    }
}
// Author: Minal Rai 
// Github Id: MINALRAI