class VariableAssign {
    public static void main(String[] args) {

        final double ONE_BILLION = 1000000000;
        final int NUM_TRIALS = 50;

        long cumulative = 0;
        for (int t = 0; t < NUM_TRIALS; t++) {
           
            long time = System.nanoTime();
            int x = 0;
            while (x < ONE_BILLION) { x++; }
            long finalTime = System.nanoTime();

            long difference = finalTime - time;
            cumulative += difference;
            double seconds = difference / ONE_BILLION;
            System.out.printf("Time to process: %f seconds\n", seconds);

            try {
                Thread.sleep(3);
            } catch (InterruptedException e) { }
        }



        double seconds = cumulative / ONE_BILLION / ((float) NUM_TRIALS);
        System.out.printf("Average time to process: %f seconds\n", seconds);

    }
}