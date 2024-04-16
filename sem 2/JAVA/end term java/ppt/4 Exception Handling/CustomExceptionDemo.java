class MyException extends Exception
{
    String des;
    MyException(String ex){
        des = ex;
    }
}
public class CustomExceptionDemo {
    public static void main(String[] args) {
        int a[] = {5,15,10,20};
        for(int ele: a){
            try{
                if(ele > 10)
                    throw new MyException("ele>10");
                System.out.println("ele<=10");
            }catch(MyException e){
                System.out.println("Caught: " + e.des);
            }
        }
    }
}
