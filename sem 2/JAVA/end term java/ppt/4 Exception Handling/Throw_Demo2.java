public class Throw_Demo2 {
    static void demoprocedure()
    {
        try{
            throw new NullPointerException("demo");
        }
        catch(NullPointerException e)
        {
            System.out.println("Caught inside demoproc.");
            throw e;
        }
    }

    public static void main(String[] args) {
        try{
            demoprocedure();
        }catch(NullPointerException e){
            System.out.println("Recaught: " + e);
        }
    }
}
