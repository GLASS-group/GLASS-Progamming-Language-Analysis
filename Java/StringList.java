class StringList {
    public static void main(String[] args) {
        final int ONE_BILLION = 1000000000;
        final int ONE_MILLION = 1000000;
        final int NUM_TRIALS = 50;

        long cumulative = 0;
        for (int t = 0; t < NUM_TRIALS; t++) {
           
            long time = System.nanoTime();
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
            long finalTime = System.nanoTime();

            long difference = finalTime - time;
            cumulative += difference;
            double seconds = difference / (double) ONE_BILLION;
            System.out.printf("Time to process: %f seconds\n", seconds);
        }

        try {
            Thread.sleep(3);
        } catch (InterruptedException e) { }

        double seconds = (double) cumulative / (double) ONE_BILLION / ((float) NUM_TRIALS);
        System.out.printf("Average time to process: %f seconds\n", seconds);

    }
}