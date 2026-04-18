import java.util.Random;

public class ans_2 {
    private static final Random rnd = new Random();

    private static String randomPlate() {
        StringBuilder sb = new StringBuilder(7);
        for (int i = 0; i < 3; i++)
            sb.append((char) ('A' + rnd.nextInt(26)));
        for (int i = 0; i < 4; i++)
            sb.append(rnd.nextInt(10));
        return sb.toString();
    }

    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            StringBuffer plates = new StringBuffer();
            plates.append(randomPlate());
            System.out.println(plates);
        }
    }
}