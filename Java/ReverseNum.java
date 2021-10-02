import java.util.Scanner;

public class Reverse {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();                         //this will take input from user 

        int ans = 0;                     //declaring ans's value equal to zero.
        
        while (n > 0) {
            int rem = n % 10;              //this will give us remainder(which will be last digit of the input)
            n = n / 10;            //this will divide the input with 10 so that we can remove the last digit from input 

            ans = ans * 10 + rem;     //this will store the required answer
        }
        System.out.println(ans);      //this will print the required answer
    }
}
