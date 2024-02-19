import java.util.Scanner;

class IntArrayMem {
    public static void main(String[] args) {
        final int ONE_BILLION = 1000000000;
        final int ONE_MILLION = 1000000;
           
        int x = 0;
        int[] ints = new int[ONE_MILLION];
        while (x < ONE_MILLION) {
            ints[x] = x;
            x++;
        }

        System.gc();

        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        scanner.close();

    }
}