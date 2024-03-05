class FibonacciThread extends Thread {
    private int[] fibonacciArray;

    FibonacciThread() {
        fibonacciArray = new int[500]; // Maximum Fibonacci number within 500
    }

    @Override
    public void run() {
        int a = 0, b = 1, c;
        int index = 0;
        fibonacciArray[index++] = a;
        fibonacciArray[index++] = b;
        while ((c = a + b) <= 500) {
            fibonacciArray[index++] = c;
            a = b;
            b = c;
        }
    }

    public int[] getFibonacciArray() {
        return fibonacciArray;
    }
}

class PrimeThread extends Thread {
    private int[] primeArray;

    PrimeThread() {
        primeArray = new int[500]; // Maximum Prime number within 500
    }

    @Override
    public void run() {
        int index = 0;
        for (int i = 2; i <= 500; i++) {
            boolean isPrime = true;
            for (int j = 2; j <= Math.sqrt(i); j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                primeArray[index++] = i;
            }
        }
    }

    public int[] getPrimeArray() {
        return primeArray;
    }
}

public class Question1 {
    public static void main(String[] args) {
        FibonacciThread fibonacciThread = new FibonacciThread();
        PrimeThread primeThread = new PrimeThread();

        fibonacciThread.start();
        primeThread.start();

        try {
            fibonacciThread.join();
            primeThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        int[] fibonacciArray = fibonacciThread.getFibonacciArray();
        int[] primeArray = primeThread.getPrimeArray();

        System.out.println("Common numbers in Fibonacci and Prime series up to 500:");

        for (int fibonacciNumber : fibonacciArray) {
            for (int primeNumber : primeArray) {
                if (fibonacciNumber == primeNumber && fibonacciNumber != 0) {
                    System.out.print(fibonacciNumber + " ");
                    break;
                }
            }
        }
    }
}
