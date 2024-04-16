public class MainThreadExample {
    public static void main(String[] args) {
        // This code will be executed immediately when the program starts
        System.out.println("Main thread started.");

        // Simulate some work being done
        for (int i = 0; i < 5; i++) {
            System.out.println("Main thread is running... " + i);
            // Adding a short delay to simulate some work
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // This will be printed after the loop finishes
        System.out.println("Main thread finished.");
    }
}
