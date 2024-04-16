public class FinallyDemo1 {
    static void methodA(){
        try{
            System.out.println("In methodA");
            throw new RuntimeException();
        }
        finally{
            System.out.println("In methodA's finally");
        }
    }
    public static void main(String[] args) {
        try{
            methodA();
        }
        catch(Exception e){
            System.out.println("Exception caught: " + e);
        }
    }
}
