import java.util.Scanner;

class StringArrayMem {
    public static void main(String[] args) {
        final int ONE_BILLION = 1000000000;
        final int ONE_MILLION = 1000000;
           
        int x = 0;
        String[] strings = new String[100000];
        while (x < 100000) {
            if (x == 0) {
                strings[x] = "a";
            } else {
                strings[x] = strings[x-1] + "a";
            }
            x++;
        }

        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        scanner.close();

    }
}