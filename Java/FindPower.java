import java.util.*;
public class FindPower {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("enter base");
		int base=sc.nextInt();
		System.out.println("enter power");
		int power=sc.nextInt();
		int product=1;
		while(power>0) {
			product=product*base;
			power--;
		}
		System.out.println("ans: "+product);
	}

}
