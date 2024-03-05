class MultiplicationTable extends Thread {
    private int tableNumber;

    public MultiplicationTable(int tableNumber) {
        this.tableNumber = tableNumber;
    }

    public void run() {
        System.out.println("Multiplication Table of " + tableNumber + ":");
        for (int i = 1; i <= 10; i++) {
            System.out.println(tableNumber + " x " + i + " = " + (tableNumber * i));
        }
    }
}

public class Question2 {
    public static void main(String[] args) {
        MultiplicationTable table5 = new MultiplicationTable(5);
        MultiplicationTable table7 = new MultiplicationTable(7);
        MultiplicationTable table13 = new MultiplicationTable(13);

        table5.start();
        table7.start();
        table13.start();
    }
}
