public class FinallyDemo2 {
    static void methodA(){
        try{
            System.out.println("In methodA");
            return;
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
