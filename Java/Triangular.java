// Prints all triangular numbers upto given number

import java.util.*;
public class Triangular
{
    public static void main(String args[])
    {
        int n,a=2,sum=1;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter value of n");
        n=in.nextInt();
        System.out.println("The triangular numbers uptil "+n+" are : ");
        while(sum<=n)
        {
            System.out.print(sum+" ");
            sum+=a;
            a++;
        }
    }
}
