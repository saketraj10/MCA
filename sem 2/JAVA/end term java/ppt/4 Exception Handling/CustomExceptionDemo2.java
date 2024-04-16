class MyException extends Exception
{
    String des;
    MyException(String ex){
        des = ex;
    }
}
public class CustomExceptionDemo2 {
    static void compute(int a) throws MyException
    {
        System.out.println("Called compute (" + a+ ")");
        if(a>10){
            throw new MyException("a>10");
        }
        System.out.println("Normal exit");
    }
    public static void main(String[] args) {
        try{
            compute(1);
            compute(20);
        }catch(MyException e){
            System.out.println("Caught: " + e.des);
        }
    }
}
