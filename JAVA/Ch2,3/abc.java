import java.util.Scanner;

public class abc {
    public static void main(String[] args) {
        System.out.println("Enter a number between 0 and 1000:");
        int num = new Scanner(System.in).nextInt();
        int res = 0;
        while (num != 0) {
            res = res + num % 10;
            num = num / 10;
        }
        System.out.println("The sum of the digits is " + res);
    }
}