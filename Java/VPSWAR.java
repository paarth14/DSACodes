// Variable Precision SWAR algorithm for counting set bits in a number

import java.util.Scanner;

public class VPSWAR {

    // Implementation of VPSWAR Algorithm
    static int count_set_bits(int num) {
        int n = num;

        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
        n = n * 0x01010101;
        n = n >> 24;

        return n;
    }

    // Main method
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        int set_bits = count_set_bits(n);

        System.out.println(set_bits);

        s.close();        
    }
}