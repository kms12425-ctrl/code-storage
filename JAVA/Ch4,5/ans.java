import java.util.Scanner;

public class ans {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        input.close();
        int[] cnt = new int[91];
        for (int i = 0; i < str.length(); i++) {
            int word = str.charAt(i);
            cnt[word >= 97 ? word - 32 : word]++;
        }
        int i = 0;
        for (i = 65; i <= 90; i++) {
            System.out.println((char) i + "出现了:" + cnt[i] + "次\n");
        }
    }
}