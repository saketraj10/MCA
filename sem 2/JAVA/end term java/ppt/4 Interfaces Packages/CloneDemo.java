class Test implements Cloneable
{
    int a, b;
    public Test clone() throws CloneNotSupportedException
    {
        Test cloned = (Test)super.clone();
        return cloned;
    }
}
public class CloneDemo {
    public static void main(String[] args) {
        Test x1 = new Test();
        Test x2 = new Test();
        Test x3 = new Test();
        x1.a = 10;
        x1.b = 20;
        x3 = x1;
        try{
            x2 = x1.clone();
        }
        catch(CloneNotSupportedException e){
            System.out.println("Clone not allowed.");
        }
        x1.b = 22;
        x2.b = 25;
        x3.a = 11;
        System.out.println("x1: " + x1.a + " " + x1.b);
        System.out.println("x2: " + x2.a + " " + x2.b);
        System.out.println("x3: " + x3.a + " " + x3.b);
    }
}
