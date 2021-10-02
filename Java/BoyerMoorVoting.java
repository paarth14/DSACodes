// Boyer Moor Voting algorithm is used to find majority element in a given array of elements
// O(N) time complexity
// O(1) space complexity


import java.util.Scanner;

public class BoyerMoorVoting{
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int arr[] = new int[n];

        for(int i = 0; i < n; i++){
            arr[i] = s.nextInt();
        }

        // BMV implementation begins
        int count = 0;
        int element = -1;

        for(int i : arr){
            if(count == 0){
                count = 1;
                element = i;
            }else if(element == i){
                count++;
            }else{
                count--;
            }
        }

        count = 0;
        for(int i : arr){
            if(i == element){
                count++;
            }
        }

        if(count > n/2){
            System.out.println("Majority Element: " + element);
        }else{
            System.out.println("No Majority Element");
        }
        // BMV implementation ends

        s.close();        
    }
}