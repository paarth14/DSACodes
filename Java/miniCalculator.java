import java.util.Scanner;

class ifcondition{
    public static void main(String arr[]){
        Scanner scan =new Scanner(System.in);
        System.out.println("Enter two numbers: ");
        double num1 = scan.nextInt();
        double num2 =  scan.nextInt();
        System.out.print("Enter what operation you want to perform (+,-,*,/): ");
        char spchar = scan.next().charAt(0);

        if(spchar == '+'){                 //'' this for char and "" this for string.......
            System.out.println("Sum is: "+ (num1+num2));
        }
        else if(spchar == '-'){
              System.out.println("Subtraction is: " + (num1-num2));
        }
        else if(spchar == '*'){
             System.out.println("Multiplication is: "+num1*num2);
        }
        else{
             System.out.println("Divition  is: "+num1/num2);
        }


    }
}
