public class ExecDemo1 {
    public static void main(String[] args) {
        int[] nums = new int[4];
        try{
            System.out.println("Before exception is generated.");
            nums[7] = 10;
            System.out.println("this won't be displayed");
        }
        catch(ArrayIndexOutOfBoundsException exc){
            System.out.println("Index out of bounds");
        }
        System.out.println("After catch");
    }
}